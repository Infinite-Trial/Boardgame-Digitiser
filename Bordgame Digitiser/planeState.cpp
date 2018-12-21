#include "PlaneState.h"



PlaneState::PlaneState()
{
}


PlaneState::~PlaneState()
{
}

pieceTypes PlaneState::getPieceAt(int x, int y)
{
	return state[x][y];
}

pieceTypes PlaneState::getPieceAt(cv::Point2i pos)
{
	return state[pos.x][pos.y];
}

/*bool PlaneState::equals(const PlaneState reference) 
{
	for (int x = 0; x < 7; x++)
	{
		for (int y = A; y < H; y++)
		{
			if (this->getPieceAt(x,y) == reference) {
				return false;
			}
		}
	}
	return true;
}*/