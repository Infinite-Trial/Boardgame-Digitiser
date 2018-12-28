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
	void setPieceAt(int x, int y);
	void setPieceAt(cv::Point2i pos);
	//methods
	std::vector<cv::Point2i> difference(PlaneState reference); //returns the coordinates of the different fields
	//operator
	bool equals(PlaneState& reference);
private:
	std::vector<std::vector<pieceTypes>> state;
};

