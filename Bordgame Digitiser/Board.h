//Author: Schneider
//Description: Functions for the virtual chess board

#pragma once
#include <vector>
#include "CameraIn.h"
class Board
{
public:
	Board();
	~Board();
	void synchronizeVirtual(std::vector<std::vector<ChessPiece>> Field);


};

