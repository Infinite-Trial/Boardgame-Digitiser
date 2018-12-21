#pragma once
#include "opencv2/core/types.hpp"
#include "CONSTANTS.h"
#include <vector>
class planeState
{
public:
	planeState();
	~planeState();
	//getter
	pieceTypes getPieceAt(int x,int y);
	pieceTypes getPieceAt(cv::Point2i pos);
	//setter
	void setPieceAt(chessCoord x, int y);
	void setPieceAt(cv::Point2i pos);
	//methods
	std::vector<cv::Point2i> difference(planeState reference); //returns the coordinates of the different fields
	//operator
	bool operator==(const planeState& reference) const;
private:
	std::vector<std::vector<pieceTypes>> state;
};

