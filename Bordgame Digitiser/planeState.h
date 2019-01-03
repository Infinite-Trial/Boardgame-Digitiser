//Author: Gross
//Discription: Helps to savely handle a 2D vector to store a boardstate

#pragma once
#include "opencv2/core/types.hpp"
#include "CONSTANTS.h"
#include <vector>

class PlaneState
{
public:
	PlaneState();
	~PlaneState();
	//getter
	pieceTypes getPieceAt(int x,int y);
	pieceTypes getPieceAt(cv::Point2i pos);
	//setter
	void setPieceAt(int x, int y, pieceTypes dif);
	void setPieceAt(cv::Point2i pos, pieceTypes dif);
	//methods
	std::vector<cv::Point2i> difference(const PlaneState reference); //returns the coordinates of the different fields
	bool equals(PlaneState reference); //compares two boards
	void reset(); //resets the board
private:
	std::vector<std::vector<pieceTypes>> state;
};

