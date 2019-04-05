//Author:Gross

#include "ChessField.h"

ChessField::ChessField(const cv::Rect fieldROI, const cv::Point2i fieldCoord)
{
	this->fieldCoord = fieldCoord;
	this->fieldROI = fieldROI;
}

ChessField::~ChessField()
{
}

void ChessField::updateChessFieldROI(const cv::Rect fieldROI)
{
	this->fieldROI = fieldROI;
}

cv::Rect ChessField::getFieldROI()
{
	return this->fieldROI;
}

cv::Point2i ChessField::getFieldCoord()
{
	return this->fieldCoord;
}
