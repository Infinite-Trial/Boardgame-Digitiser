//Author: Schneider
//Description: Functions for the virtual chess board

#pragma once
#include <vector>
#include "CameraIn.h"
#include "PlaneState.h"
#include "UIBoard.h"

class Board
{
public:
	Board();
	~Board();
	void synchronizeVirtual();

private:
	PlaneState originState;
	PlaneState previousState;
	PlaneState currentState;
	int numberOfChanges;
	std::vector<System::Drawing::Point> location;
	
	
};

