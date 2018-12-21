//Author:Gross
//Description:	Its the class for a single chesspiece
//				Its components are its Type and coordinates inside the virtual chessboard

#pragma once
#include "CONSTANTS.h"
#include "opencv2/core/types.hpp"

public class ChessPiece
{
public:
	ChessPiece(cv::Point2i pos,chessPieces type);
	~ChessPiece();
//seter
	void setPos(cv::Point2i pos); //Sets the virtual coordinates of the piece
//getter
	cv::Point2i getPos();//Gets the coordinates 
	chessPieces getType(); //Gets the type
private:
	chessPieces type; //The type of the chesspiece
	cv::Point2i coordinates; //The coordinates of the piece in the 2d vector
};

