#pragma once
#include "CONSTANTS.h"
#include <vector>
public class CameraIn
{
public:
	CameraIn();
	std::vector<int> getBoardState();
	void updateBoardState();

private:
	std::vector<int> getPieceROIs(chessPieces piece);


};

