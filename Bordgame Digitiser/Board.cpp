#include "Board.h"



Board::Board()
{

}

/*void Board::synchronizeVirtual(BordgameDigitiser::UIBoard form)
{
	this->difference = currentState.difference(previousState);
	if (currentState.getPieceAt(difference[0]) == NP) 
	{
		prev = 0; current = 1;
	}
	if (currentState.getPieceAt(difference[1]) == NP) 
	{
		prev = 1; current = 0;
	}
	this->prevLocation.X = difference[prev].x * 240;
	this->prevLocation.Y = difference[prev].y * 240;
	this->currentLocation.X = difference[current].x * 240;
	this->currentLocation.Y = difference[current].y * 240;
//	form.setLocation(currentState.getPieceAt(difference[current]), prevLocation, currentLocation);

}*/



Board::~Board()
{

}

void Board::setPrevState(PlaneState state)
{
	this->previousState = state;
}

void Board::setCurrState(PlaneState state)
{
	this->previousState = state;
}
