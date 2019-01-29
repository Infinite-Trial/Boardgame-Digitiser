//Author:Gross
#include "CameraIn.h"
#include <iostream>
#include <thread>



CameraIn::CameraIn()
{
}

std::vector<std::vector<pieceTypes>> CameraIn::getBoardStatePlane() throw (int)
{
	std::vector<std::vector<pieceTypes>> currentState;
	std::vector<std::vector<cv::Rect>> pieceROIs;
	std::thread t[num_threads];
	try {
		std::vector<ChessField> fieldROIs = getFieldRecs();
	}
	catch (int i) {
		std::cout << "Fehler: Es konnten " << i << "/" << BOARDHEIGHT * BOARDWIDTH << " Spielfelder erkannt werden.";
		throw i;
	}
	try {
		for (size_t i = 0; i < pieceROIs.size(); i++)
		{
			std::thread pawns = std::thread(CameraIn::getPieceRecs,pieceROIs[i],pieceTypes(i+1));
			pawns.join();
		}
		
	}
	catch (int i) {

	}



	return currentState;
}
std::vector<std::vector<pieceTypes>> CameraIn::chainToPlane(std::vector<ChessPiece> pieceChain)
{
	//A chain of ChessPieces is taken and converted into a 2D vector of chesspieces
	//From: {WR,WP,NP,NP,NP,NP,BP,BR, WN,WP,NP,NP,NP,NP,BP,BN, WB,WP,NP,NP,NP,NP,BP,BB, ... }	To:	 {{WR,WP,NP,NP,NP,NP,BP,BR},
	//																								  {WN,WP,NP,NP,NP,NP,BP,BN},
	//																								  {WB,WP,NP,NP,NP,NP,BP,BB},
	//																												.
	//																												.
	//																												.			}

	std::vector<std::vector<pieceTypes>> Plain;
	cv::Point2i c;
	for each (ChessPiece element in pieceChain)
	{
		c=element.getPos();
		Plain[c.x][c.y] = element.getType();
	}
	return Plain;
}
std::vector<ChessPiece> CameraIn::planeToChain(const std::vector<std::vector<pieceTypes>> piecePlain)
{
	//A 2D vector of chesspieces is taken and converted into a chain of ChessPieces
	//from: {{WR,WP,NP,NP,NP,NP,BP,BR},	To:{WR,WP,NP,NP,NP,NP,BP,BR, WN,WP,NP,NP,NP,NP,BP,BN, WB,WP,NP,NP,NP,NP,BP,BB, ... }
	//		 {WN,WP,NP,NP,NP,NP,BP,BN},
	//		 {WB,WP,NP,NP,NP,NP,BP,BB},
	//					.
	//					.
	//					.			  }
	std::vector<ChessPiece> chain;
		for (int x = 0; x < piecePlain.size(); x++)
		{
			for (int y = 0; y < piecePlain[x].size(); y++)
			{
				chain.push_back(ChessPiece(cv::Point2i(x,y),piecePlain[x][y]));
			}
		}
	return chain;
}

void CameraIn::getPieceRecs(std::vector<cv::Rect> ROIs,pieceTypes piece) throw(int)
{
	std::thread::detach();
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
