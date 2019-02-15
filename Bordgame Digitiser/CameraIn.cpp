//Author:Gross

#include "CameraIn.h"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <thread>



CameraIn::CameraIn(int offset = 1) throw(bool)
{
	cam[0] = cv::VideoCapture(0 + offset);
	cam[1] = cv::VideoCapture(1 + offset);
	if (!cam[0].isOpened()||!cam[1].isOpened())
	{
		std::cout << "Es konnte nicht auf alle Kameras zugegriffen werden.";
		throw(false);
	}
	//set the camera properties
	for (short i = 0; i < cam.size(); i++)
	{
		//set resolution
		cam[i].set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		cam[i].set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		//set Focus
		cam[i].set(CV_CAP_PROP_AUTOFOCUS, 0);
		cam[i].set(CV_CAP_PROP_FOCUS, 1);
		//set FPS
		cam[i].set(CV_CAP_PROP_FPS, 15);
	}
	
}

PlaneState CameraIn::getBoardStatePlane() throw (BOARDeRRORS)
{
	//This funktion should read the CameraInput, detect the board + all chesspieces 
	//and return the current Planestate
	PlaneState currentState;
	std::vector<ChessField> chessFields;
	std::vector<ChessPiece> fullchainState;
	std::array<std::vector<ChessPiece>, 12> fragments;
	std::vector<std::thread> t_worker;

	//1. The programm searches for the board and its fields.
	try {
		chessFields = getChessFields();
	}
	catch (int detectedFields) {
		std::cout << "Fehler: Es konnten nur " << detectedFields << "/" << BOARDHEIGHT * BOARDWIDTH << " Spielfelder erkannt werden.";
		throw NotEnoughFields;
	}
	//2. After the board is correctly detected:
	//The all ChessPieces are detected. 
	//Each type in a seperate thread
	//The virtual coordinates are returned as a chain of ChessPieces

	for (int i = 0; i < 12; i++){
		t_worker.push_back(std::thread{ getPieceCoords, ref(fragments[i]), pieceTypes(i + 1), chessFields });
	}
	for (int i = 0; i < t_worker.size(); i++){
		if(t_worker[i].joinable()) t_worker[i].join();
	}
	//connect the chains
	for each (std::vector<ChessPiece> frag in fragments)
	{
		for each (ChessPiece piece in frag)
		{
			fullchainState.push_back(piece);
		}
	}
	
	//3. checking for errors
	if (fullchainState.size()>32){
		throw(TooManyPieces);
	}
	//check for double assigned fields
	
		//compare every ChessPiece with every other ChessPiece 
		for (int i = 0; i < fullchainState.size(); i++)
		{
			for (int n = i + 1; n < fullchainState.size(); n++)
			{
				if (fullchainState[i].getPos() == fullchainState[n].getPos())
					throw(UnclearPiecePosition);
			}
		}
	
	//4. convert the chain to a plane and return it
	return chainToPlane(fullchainState);
}
PlaneState CameraIn::chainToPlane(std::vector<ChessPiece> pieceChain)
{
	//A chain of ChessPieces is taken and converted into a 2D vector of chesspieces
	//From: {(WR,0/0),(WP,0/1),(BP,0/6),(BR,0/7),(WN,1/1),(WP,1/2),(BP,1/6),(BN,1/7), ... }	To:	 {{WR,WP,NP,NP,NP,NP,BP,BR},
	//																							  {WN,WP,NP,NP,NP,NP,BP,BN},
	//																							  {WB,WP,NP,NP,NP,NP,BP,BB},
	//																											.
	//																											.
	//																											.			}
	PlaneState Plain;
	cv::Point2i c;
	for each (ChessPiece element in pieceChain)
	{
		c=element.getPos();
		Plain.setPieceAt(c.x,c.y,element.getType());
	}
	return Plain;
}
std::vector<ChessPiece> CameraIn::planeToChain(PlaneState piecePlain)
{
	//A 2D vector of chesspieces is taken and converted into a chain of ChessPieces
	//from: {{WR,WP,NP,NP,NP,NP,BP,BR},	To:{(WR,0/0),(WP,0/1),(BP,0/6),(BR,0/7),(WN,1/1),(WP,1/2),(BP,1/6),(BN,1/7), ... }
	//		 {WN,WP,NP,NP,NP,NP,BP,BN},
	//		 {WB,WP,NP,NP,NP,NP,BP,BB},
	//					.
	//					.
	//					.			  }
	std::vector<ChessPiece> chain;
	ChessPiece piece;
		for (int x = 0; x < piecePlain.width; x++)
		{
			for (int y = 0; y < piecePlain.length; y++)
			{
				piece = ChessPiece(cv::Point2i(x, y), piecePlain.getPieceAt(x, y));
				chain.push_back(piece);
			}
		}
	return chain;
}
//maybe needs adjustments
void CameraIn::getPieceCoords(std::vector<ChessPiece> chainFragment,pieceTypes type, std::vector<ChessField> chessfields) throw(int)
{
	//This funktion assigns each detected Chesspiece to the chessfield with which it overlapps the most.
	std::vector<cv::Rect> pROIs = getPieceROIs(type);
	int AUnion, AIntersection;
	for each (cv::Rect pieceROI in pROIs)
	{
		int maxoverlap = 0, overlappingField = -1, overlapRatio;
		for(int i=0; i<chessfields.size();i++ )
		{
			AIntersection = (pieceROI & chessfields[i].getFieldROI()).area();
			//fields with no overlap are ignored
			if (AIntersection > 0) {
				AUnion = (pieceROI | chessfields[i].getFieldROI()).area();
				overlapRatio = AIntersection / AUnion;
				if (maxoverlap<overlapRatio)
				{
					maxoverlap = overlapRatio;
					overlappingField = i;
				}
			}
		}
		//the piecetype and the coresponding chessfield are combined to a ChessPiece and added to the output-chain
		chainFragment.push_back(ChessPiece(chessfields[overlappingField].getFieldCoord(), type));
	}
}

//unfinished
void CameraIn::getPieceCoords(std::vector<ChessPiece> &chainFragment,pieceTypes type) throw(pieceTypes)
{
	std::vector<cv::Rect> pieceROIs;
	cv::Mat img;
	cam >> img;
	//insert fokus check

	//you have to create the classefier and use detectMulti...whatever
	//then compare them with the ROIs of the pieces of the right cam!!!




	return pieceROIs;
}
//unfinished
std::vector<ChessField> CameraIn::getChessFields(cv::VideoCapture cam)
{
	std::vector<ChessField> fieldROIs;
	
	//

	if (fieldROIs.size() < BOARDHEIGHT*BOARDWIDTH)
		throw fieldROIs.size();
	return fieldROIs;
}

