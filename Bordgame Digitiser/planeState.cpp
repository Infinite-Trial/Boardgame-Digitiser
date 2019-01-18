//Author: Gross

#include "PlaneState.h"


//constructor
PlaneState::PlaneState()
{
	clear();
}
//destruktor
PlaneState::~PlaneState()
{
}

//Getter
pieceTypes PlaneState::getPieceAt(int x, int y)
{
	return state[x][y];
}
pieceTypes PlaneState::getPieceAt(cv::Point2i pos)
{
	return state[pos.x][pos.y];
}

//setter
void PlaneState::setPieceAt(int x, int y, pieceTypes dif)
{
	state[x][y]=dif;
}
void PlaneState::setPieceAt(cv::Point2i pos, pieceTypes dif)
{
	state[pos.x][pos.y] = dif;
}

//methods
std::vector<cv::Point2i> PlaneState::difference(PlaneState reference)
{	//All members of the board are compared. The funktion returns a collection of the coordinates of all differences.
	std::vector<cv::Point2i> difs;
	cv::Point2i temp(0,0);
	for (int x = 0; x < 7; x++)
	{
		for (int y = A; y < H; y++)
		{
			if (this->getPieceAt(x, y) != reference.getPieceAt(x, y)) {
				temp.x = x;
				temp.y = y;
				difs.push_back(temp);
			}
		}
	}
	return difs;
}
bool PlaneState::equals(PlaneState reference)
{	//All members of the board are compared. The function returns false, when a difference is found.
	for (int x = 0; x < 7; x++)
	{
		for (int y = A; y < H; y++)
		{
			if (this->getPieceAt(x, y) != reference.getPieceAt(x, y)){
				return false;
			}
		}
	}
	return true;
}
void PlaneState::reset()
{
	state= {{BR,BP,NP,NP,NP,NP,WP,WR},
			{BN,BP,NP,NP,NP,NP,WP,WN},
			{BB,BP,NP,NP,NP,NP,WP,WB},
			{BQ,BP,NP,NP,NP,NP,WP,WQ},
			{BK,BP,NP,NP,NP,NP,WP,WK},
			{BB,BP,NP,NP,NP,NP,WP,WB},
			{BN,BP,NP,NP,NP,NP,WP,WN},
			{BR,BP,NP,NP,NP,NP,WP,WR}};
}
void PlaneState::clear()
{
	state= {{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP},
			{NP,NP,NP,NP,NP,NP,NP,NP} };
}
