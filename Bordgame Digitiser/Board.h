//Author: Schneider
//Description: Functions for the virtual chess board

#pragma once


#include "UIBoard.h"

class Board
{
public:
	Board();
	~Board();
	void setPrevState(PlaneState state);
	void setCurrState(PlaneState state);
	void synchronizeVirtual(BordgameDigitiser::UIBoard form);

private:
	PlaneState originState;
	PlaneState previousState;
	PlaneState currentState;
	int current, prev;
	int numberOfChanges;
	System::Drawing::Point prevLocation;
	System::Drawing::Point currentLocation;
	std::vector <cv::Point2i> difference;
	


	
	
};

