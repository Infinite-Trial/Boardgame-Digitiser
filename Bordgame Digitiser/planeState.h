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
	//constants
	int const lenght = 12;
	int const width = 12;
	//getter
	pieceTypes getPieceAt(const int x,const int y);
	pieceTypes getPieceAt(cv::Point2i pos);
	//setter
	void setPieceAt(int x, int y, pieceTypes dif);
	void setPieceAt(cv::Point2i pos, pieceTypes dif);
	//methods
	std::vector<cv::Point2i> difference(const PlaneState reference); //returns the coordinates of the different fields
	bool equals(PlaneState reference); //compares two boards
	void reset(); //resets the board
	void clear(); //sets the whole board to NP
private:
	std::vector<std::vector<pieceTypes>> state;
};

