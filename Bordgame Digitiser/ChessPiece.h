//Author:Gross
//Description:	Its the class for a single chesspiece
//				Its components are its Type and coordinates inside the virtual chessboard

#pragma once
#include "CONSTANTS.h"
#include "opencv2/core/types.hpp"

class ChessPiece
{
public:
	ChessPiece();
	ChessPiece(cv::Point2i pos,pieceTypes type);
	~ChessPiece();
//seter
	void setPos(cv::Point2i pos); //Sets the virtual coordinates of the piece
//getter
	cv::Point2i getPos();//Gets the coordinates 
	pieceTypes getType(); //Gets the type
private:

	pieceTypes type; //The type of the chesspiece
	cv::Point2i coordinates; //The virtual coordinates of the piece in the 2d vector
};

