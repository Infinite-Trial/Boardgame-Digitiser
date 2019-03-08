//Author: Gross

#include "PlaneState.h"


//constructor
PlaneState::PlaneState()
{
	reset();
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
	state= {{WR,WP,NP,NP,NP,NP,BP,BR},
			{WN,WP,NP,NP,NP,NP,BP,BN},
			{WB,WP,NP,NP,NP,NP,BP,BB},
			{WQ,WP,NP,NP,NP,NP,BP,BQ},
			{WK,WP,NP,NP,NP,NP,BP,BK},
			{WB,WP,NP,NP,NP,NP,BP,BB},
			{WN,WP,NP,NP,NP,NP,BP,BN},
			{WR,WP,NP,NP,NP,NP,BP,BR}};
}
