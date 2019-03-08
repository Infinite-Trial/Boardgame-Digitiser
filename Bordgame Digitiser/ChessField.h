//Author:Gross
//Description: Stores the actual and virtual location of a single field of the board

#pragma once
#include "opencv2/core/types.hpp"
#include <vector>

public  class ChessField
{
public:
	ChessField(cv::Rect fieldROI,cv::Point2i fieldCoord);
	~ChessField();
	cv::Rect getFieldROI();
	cv::Point2i getFieldCoord();
private:
	cv::Rect fieldROI;
	cv::Point2i fieldCoord;
};

