#include "planeState.h"



planeState::planeState()
{
}


planeState::~planeState()
{
}

pieceTypes planeState::getPieceAt(int x, int y)
{
	return state[x][y];
}

pieceTypes planeState::getPieceAt(cv::Point2i pos)
{
	return state[pos.x][pos.y];
}

/*bool planeState::operator==(const planeState &reference) const 
{
	for (int x = 0; x < 7; x++)
	{
		for (int y = A; y < H; y++)
		{
			if (this.getPieceAt(x,y) == reference.getPieceAt(x, y)) {
				return false;
			}
		}
	}
	return true;
}*/