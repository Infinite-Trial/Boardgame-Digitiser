#pragma once
#include "CONSTANTS.h"
#include "opencv2/core/types.hpp"
public class ChessPiece
{
public:
	ChessPiece();
//setter
	void setPos(cv::Point2i pos);
	void setX();
	void setY();

//getter
	cv::Point2i getPos();
	int getX();
	int getY();
	chessPieces getType();
private:
	chessPieces type;
	cv::Point_<int> position;


};

