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
	bool whiteSide=0;
	std::array<cv::VideoCapture,2> cam;
	std::array<cv::Mat, 2> snapshot;
	std::array<std::string, 12> pieceCascades;
	
	//methods
	static void getPieceCoords(std::vector<ChessPiece> &chainFragment, pieceTypes type, std::array < std::vector<ChessField>, 2> chessfields, std::array<cv::Mat, 2> pics) throw(ChessPiece);
	static std::vector<cv::Rect> getPieceROIs(pieceTypes type, cv::Mat pic) throw(pieceTypes);
	std::vector<ChessField> getChessFields(int picNumber) throw (int);
	
	void updateCameras();//quality check is missing 
};
