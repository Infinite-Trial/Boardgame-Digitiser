//Author:Gross
#include "CameraIn.h"



CameraIn::CameraIn()
{
}

std::vector<int> CameraIn::getBoardStatePlane()
{
	return std::vector<int>();
}

std::vector<chessPieces> CameraIn::getBoardStateChain()
{
	std::vector<cv::Rect> temp;
	std::vector<chessPieces> chain;

	for (auto i = 0; i < NUMBER_OF_PIECE_TYPES; i++)
	{
		temp = getPieceRecs(i);

	}
	return std::vector<chessPieces>();
}

