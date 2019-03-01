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
	void toggleDebug();
private:
	//properties
	short leftSide=-1; //stores the number of the cam which is positioned on the left edge of the board
	bool debugMode;
	std::array<cv::VideoCapture,2> cam;
	std::array<cv::Mat, 2> snapshot; //the current view as a grayscale image
	static std::array<std::string, 12> cascadesPaths;
	
	//methods
	static void getPieceCoords(std::vector<ChessPiece> &chainFragment, pieceTypes type, std::array < std::vector<ChessField>, 2> chessfields, std::array<cv::Mat, 2> pics) throw(ChessPiece);
	static std::vector<cv::Rect> getPieceROIs(pieceTypes type, cv::Mat pic) throw(pieceTypes);
	std::vector<ChessField> getChessFields(int picNumber) throw (int);
	
	void updateCameras();//quality check is missing 
	bool touchesBorder(std::vector<CvPoint> points); 
	void updateBoardOrientation();
	cv::Rect toRect(std::vector<CvPoint> pts);

	void sortBoard(std::array<std::array<cv::Rect*, 5>, 8> &board, std::vector<cv::Rect> ROIs);//indirect adresses to speed up the prozess
	void constructBlack(std::array<std::array<cv::Rect*, 5>, 8 > &board);
};

int average(int A, int B);
