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
	cv::VideoCapture cam1,cam0;
	std::vector<pieceTypes> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	static void getPieceCoords(std::vector<ChessPiece> chainFragment, pieceTypes type) throw (pieceTypes);
	static std::vector<cv::Rect> getPieceROIs(pieceTypes type);
	std::vector<ChessField> getFieldRecs() throw (int);
	
};

