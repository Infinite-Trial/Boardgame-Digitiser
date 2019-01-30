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
	std::vector<PlaneState> maps(12);
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
	//The virtual coordinates are returned as a PlaneState

	try {

		for (int i = 0; i < 12; i++)
		{
			t_worker.push_back(std::thread{ getPieceMaps,pieceTypes(i + 1) });
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
	//3. checking for errors and deleting unessesary maps
	//check if both Kings exist
	if (maps[BK - 1].isEmpty() || maps[WK - 1].isEmpty()) throw(MissingKing);
	//delete empty maps
	for (int i = maps.size(); i > 0; i--)
	{
		if (maps[i].isEmpty())
		{
			maps.erase(maps.begin()+i);
		}
	}
	//check for double assigned fields
	try
	{
		//compare every plane with every other plane 
		for (int i = 0; i < maps.size(); i++)
		{
			for (int n = i + 1; n < maps.size(); n++)
			{
				//compare all fields
				for (int x = 0; x < maps[i].length; x++)
				{
					for (int y = 0; y < maps[i].length; y++)
					{
						//when both fields are not empty throw an error
						if (maps[i].getPieceAt(x, y)!=NP && maps[n].getPieceAt(x, y)!=NP) 
							throw(std::array<int, 4>{ i, n, x, y });
					}
				}
				
			}
		}
	}
	catch (std::array<int,4> collision)
	{
		//
		//
		//
		throw(UnclearPiecePosition);
	}

	//4. Merge all Maps






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
			for (int y = 0; y < piecePlain.length; y++)
			{
				piece = ChessPiece(cv::Point2i(x, y), piecePlain.getPieceAt(x, y));
				chain.push_back(piece);
			}
		}
	return chain;
}
//unfinished
void CameraIn::getPieceMaps(pieceTypes type) throw(int)
{
	std::vector<cv::Rect> ROIs = getPieceROIs(type);


	//std::thread::detach();
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

