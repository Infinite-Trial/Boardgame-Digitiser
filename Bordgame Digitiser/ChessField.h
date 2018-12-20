#pragma once
#include "opencv2/core/types.hpp"
#include <vector>

public ref class ChessField
{
public:
	ChessField(cv::Rect fieldROI,cv::Point2i fieldCoord);
	~ChessField();
};

