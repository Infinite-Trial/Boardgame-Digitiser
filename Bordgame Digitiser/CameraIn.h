//Author:Gross
//Description: 
//

#pragma once
#include "CONSTANTS.h"
#include "ChessField.h"
#include "ChessPiece.h"
#include <vector>
public class CameraIn
{
public:
	CameraIn();
	std::vector<std::vector<pieceTypes>> getBoardStatePlane() throw (int); 
	std::vector<std::vector<pieceTypes>> chainToPlane(std::vector<ChessPiece> pieceChain);
	std::vector<ChessPiece> planeToChain(const std::vector<std::vector<pieceTypes>> piecePlain);
private:
	//properties
	std::vector<pieceTypes> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	void getPieceRecs(std::vector<cv::Rect>, pieceTypes piece) throw (int);
	std::vector<ChessField> getFieldRecs() throw (int);
};

