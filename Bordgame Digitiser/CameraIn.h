#pragma once
#include "CONSTANTS.h"
#include "ChessField.h"
#include <vector>
public class CameraIn
{
public:
	CameraIn();
	std::vector<int> getBoardStatePlane();
	std::vector<chessPieces> getBoardStateChain();
	std::vector<int, int> chainToPlane(std::vector<chessPieces> pieceChain);
	std::vector<chessPieces> planeToChain(std::vector<int, int>);
private:
	//properties
	std::vector<chessPieces> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	std::vector<int> getPieceRecs(chessPieces piece);
	std::vector<ChessField> getFielsRecs();
};

