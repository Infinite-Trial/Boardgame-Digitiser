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
private:
	std::vector<int> getPieceRecs(chessPieces piece);
	std::vector<ChessField> getFielsRecs();
	std::vector<int, int> chainToPlane(std::vector<chessPieces> pieceChain);



};

