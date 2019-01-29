//Author:Gross
#include "CameraIn.h"
#include <iostream>
#include <thread>



CameraIn::CameraIn()
{
}

PlaneState CameraIn::getBoardStatePlane() throw (int)
{
	//This funktion should read the CameraInput, detect the board + all chesspieces 
	//and return the current Planestate
	PlaneState currentState;
	std::array<std::vector<cv::Rect>,12> pieceROIs;
	std::vector<std::thread> t_Detector;

	//1. The programm searches for the board and its fields.
	try {
		std::vector<ChessField> fieldROIs = getFieldRecs();
	}
	catch (int detectedFields) {
		std::cout << "Fehler: Es konnten " << detectedFields << "/" << BOARDHEIGHT * BOARDWIDTH << " Spielfelder erkannt werden.";
		throw detectedFields;
	}

	//2. After the board is correctly detected:
	//The all ChessPieces are detected. 
	//Each one in a seperate thread 
	try {

		for (int i = 0; i < 12; i++)
		{
			t_Detector.push_back(std::thread{ getPieceRecs, ref(pieceROIs[i]),pieceTypes(i + 1) });
		}
		
	}
	catch (int detectedPieces) {

	}
	for (int i = 0; i < t_Detector.size(); i++)
	{
		t_Detector[i].join();
	}
	//3. connect pieces to fields






	return currentState;
}
PlaneState CameraIn::chainToPlane(std::vector<ChessPiece> pieceChain)
{
	//A chain of ChessPieces is taken and converted into a 2D vector of chesspieces
	//From: {WR,WP,NP,NP,NP,NP,BP,BR, WN,WP,NP,NP,NP,NP,BP,BN, WB,WP,NP,NP,NP,NP,BP,BB, ... }	To:	 {{WR,WP,NP,NP,NP,NP,BP,BR},
	//																								  {WN,WP,NP,NP,NP,NP,BP,BN},
	//																								  {WB,WP,NP,NP,NP,NP,BP,BB},
	//																												.
	//																												.
	//																												.			}

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
	//from: {{WR,WP,NP,NP,NP,NP,BP,BR},	To:{WR,WP,NP,NP,NP,NP,BP,BR, WN,WP,NP,NP,NP,NP,BP,BN, WB,WP,NP,NP,NP,NP,BP,BB, ... }
	//		 {WN,WP,NP,NP,NP,NP,BP,BN},
	//		 {WB,WP,NP,NP,NP,NP,BP,BB},
	//					.
	//					.
	//					.			  }
	std::vector<ChessPiece> chain;
	ChessPiece piece;
		for (int x = 0; x < piecePlain.width; x++)
		{
			for (int y = 0; y < piecePlain.lenght; y++)
			{
				piece = ChessPiece(cv::Point2i(x, y), piecePlain.getPieceAt(x, y));
				chain.push_back(piece);
			}
		}
	return chain;
}

void CameraIn::getPieceRecs(std::vector<cv::Rect> &ROIs, pieceTypes type) throw(int)
{
	//pInfo = std::vector<cv::Rect> ROIs,pieceTypes piece



	//std::thread::detach();
}

std::vector<ChessField> CameraIn::getFieldRecs()
{
	std::vector<ChessField> fieldROIs;
	
	//

	if (fieldROIs.size() < BOARDHEIGHT*BOARDWIDTH)
		throw fieldROIs.size();
	return fieldROIs;
}
/*
std::vector<pieceTypes> CameraIn::getBoardStateChain()
{
	std::vector<cv::Rect> temp;
	std::vector<pieceTypes> chain;

	for (auto i = 0; i < NUMBER_OF_PIECE_TYPES; i++)
	{
		temp = getPieceRecs(i);

	}
	return std::vector<pieceTypes>();

}
*/
