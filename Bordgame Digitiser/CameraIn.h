//Author:Gross
//Description: 
//

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
	std::vector<std::vector<int>> chainToPlane(std::vector<chessPieces> pieceChain);
	std::vector<chessPieces> planeToChain(std::vector<std::vector<int>>);
private:
	//properties
	std::vector<chessPieces> detectedPieces;
	std::vector<ChessField> detectedFields;
	//methods
	std::vector<cv::Rect> getPieceRecs(chessPieces piece);
	std::vector<ChessField> getFielsRecs();
};

