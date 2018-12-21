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
	std::vector<std::vector<pieceTypes>> getBoardStatePlane();
	std::vector<ChessPiece> getBoardStateChain();
	std::vector<std::vector<pieceTypes>> chainToPlane(std::vector<pieceTypes> pieceChain);
	std::vector<ChessPiece> planeToChain(std::vector<std::vector<int>>);
private:
	//properties
	std::vector<pieceTypes> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	std::vector<cv::Rect> getPieceRecs(pieceTypes piece);
	std::vector<ChessField> getFielsRecs();
};

