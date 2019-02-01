//Author:Gross

#include "CameraIn.h"
#include <iostream>
#include <thread>



CameraIn::CameraIn(int offset) throw(bool)
{
	cam0 = cv::VideoCapture(0 + offset);
	cam1 = cv::VideoCapture(1 + offset);
	if (!cam0.isOpened()||!cam1.isOpened())
	{
		std::cout << "Es konnte nicht auf alle Kameras zugegriffenwerden.";
		throw(0);
	}
}
//unfinished
PlaneState CameraIn::getBoardStatePlane() throw (BOARDeRRORS)
{
	//This funktion should read the CameraInput, detect the board + all chesspieces 
	//and return the current Planestate
	PlaneState currentState;
	std::vector<ChessPiece> fullchainState,fragment;
	std::vector<std::thread> t_worker;

	//1. The programm searches for the board and its fields.
	try {
		std::vector<ChessField> fieldROIs = getFieldRecs();
	}
	catch (int detectedFields) {
		std::cout << "Fehler: Es konnten " << detectedFields << "/" << BOARDHEIGHT * BOARDWIDTH << " Spielfelder erkannt werden.";
		throw NotEnoughFields;
	}
	//2. After the board is correctly detected:
	//The all ChessPieces are detected. 
	//Each type in a seperate thread
	//The virtual coordinates are returned as a chain of ChessPieces

	try {

		for (int i = 0; i < 12; i++)
		{
			t_worker.push_back(std::thread{ getPieceCoords,pieceTypes(i + 1) });
		}
	}
	catch (pieceTypes type) {
		
		//
		//
		//
		//
		throw(TooManyPieces);
	}
	for (int i = 0; i < t_worker.size(); i++)
	{
		if(t_worker[i].joinable()) t_worker[i].join();
	}
	//connect the chains

	//3. checking for errors and deleting unessesary maps
	//check for double assigned fields
	try
	{
		//compare every ChessPiece with every other ChessPiece 
		for (int i = 0; i < fullchainState.size(); i++)
		{
			for (int n = i + 1; n < fullchainState.size(); n++)
			{
				if (fullchainState[i].getPos() == fullchainState[n].getPos())
					throw(std::array<ChessPiece&,2>{&fullchainState[i], &fullchainState[n]});
			}
		}
	}
	catch (std::array<ChessPiece&,2> collision)
	{
		//
		//
		//
		throw(UnclearPiecePosition);
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
//unfinished
void CameraIn::getPieceCoords(std::vector<ChessPiece> chainFragment,pieceTypes type) throw(int)
{
	std::vector<cv::Rect> ROIs = getPieceROIs(type);


	
}
//unfinished
std::vector<cv::Rect> CameraIn::getPieceROIs(pieceTypes type)
{
	return std::vector<cv::Rect>();
}
//unfinished
std::vector<ChessField> CameraIn::getFieldRecs()
{
	std::vector<ChessField> fieldROIs;
	
	//

	if (fieldROIs.size() < BOARDHEIGHT*BOARDWIDTH)
		throw fieldROIs.size();
	return fieldROIs;
}

