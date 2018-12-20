//Author:Gross

#include "ChessField.h"

ChessField::ChessField(cv::Rect fieldROI, cv::Point2i fieldCoord)
{
	this->fieldCoord = fieldCoord;
	this->fieldROI = fieldROI;
}

ChessField::~ChessField()
{
}

cv::Rect ChessField::getFieldROI()
{
	return this->fieldROI;
}

cv::Point2i ChessField::getFieldCoord()
{
	return this->fieldCoord;
}
