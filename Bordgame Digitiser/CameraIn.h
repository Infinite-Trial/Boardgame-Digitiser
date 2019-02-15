//Author:Gross
//Description: 
//

#pragma once
#include "opencv2/opencv.hpp"
#include "CONSTANTS.h"
#include "ChessField.h"
#include "ChessPiece.h"
#include "planeState.h"
#include <vector>
class CameraIn
{
public:
	enum BOARDeRRORS {NotEnoughFields,TooManyPieces,MissingKing,UnclearPiecePosition};

	CameraIn(int offset) throw(bool);
	PlaneState getBoardStatePlane() throw (BOARDeRRORS); 
	PlaneState chainToPlane(std::vector<ChessPiece> pieceChain);
	std::vector<ChessPiece> planeToChain(PlaneState piecePlain);
private:
	//properties
	std::array<cv::VideoCapture,2> cam;
	std::array<std::string, 12> pieceCascades;
	std::vector<pieceTypes> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	static void getPieceCoords(std::vector<ChessPiece> chainFragment, pieceTypes type, std::vector<ChessField> chessfields) throw (pieceTypes);
	static std::vector<cv::Rect> getPieceROIs(pieceTypes type, cv::VideoCapture cam);
	std::vector<ChessField> getChessFields(cv::VideoCapture cam) throw (int);
	
};

