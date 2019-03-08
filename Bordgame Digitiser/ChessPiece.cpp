//Author:Gross

#include "ChessPiece.h"

ChessPiece::ChessPiece(cv::Point2i pos, pieceTypes type)
{
	this->coordinates = pos;
	this->type = type;
}

ChessPiece::~ChessPiece()
{
}

void ChessPiece::setPos(cv::Point2i pos)
{
	coordinates = pos;
}

cv::Point2i ChessPiece::getPos()
{
	return coordinates;
}

pieceTypes ChessPiece::getType()
{
	return type;
}
