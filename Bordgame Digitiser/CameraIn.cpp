//Author:Gross
#include "CameraIn.h"



CameraIn::CameraIn()
{
}

std::vector<std::vector<pieceTypes>> CameraIn::getBoardStatePlane()
{
	std::vector<std::vector<pieceTypes>> currentState = {{WR,WP,NP,NP,NP,NP,BP,BR},
														{BP,BP,BP,BP,BP,BP,BP,BP},
														{NP,NP,NP,NP,NP,NP,NP,NP} };



	return std::vector<std::vector<pieceTypes>>();
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
