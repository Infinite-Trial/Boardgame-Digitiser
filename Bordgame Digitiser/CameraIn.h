//Author:Gross
//Description: 
//

#pragma once
#include "CONSTANTS.h"
#include "ChessField.h"
#include "ChessPiece.h"
#include "planeState.h"
#include <vector>
class CameraIn
{
public:
	CameraIn();
	PlaneState getBoardStatePlane() throw (int); 
	PlaneState chainToPlane(std::vector<ChessPiece> pieceChain);
	std::vector<ChessPiece> planeToChain(PlaneState piecePlain);
private:
	//this struct is only needed, because the thread-funktion can only take in one parameter
	struct pInfo
	{
		std::vector<cv::Rect> ROIs;
		pieceTypes type;
	};
	//properties
	std::vector<pieceTypes> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	void getPieceRecs(pInfo info) throw (int);
	std::vector<ChessField> getFieldRecs() throw (int);
	
};

