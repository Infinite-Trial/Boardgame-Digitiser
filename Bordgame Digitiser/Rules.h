#pragma once
#include "planeState.h"
#include "CONSTANTS.h"
#include "opencv2/core.hpp"
class Rules {
	cv::Point2i enPassant_var;

	bool whitePawn(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference, cv::Point2i enPassant_var);
	bool blackPawn(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference, cv::Point2i enPassant_var);
	bool king(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool queen(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool bishop(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool knight(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool rook(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool promotion(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool enPassant(PlaneState oldState, PlaneState newState, cv::Point2i enPassant_var, std::vector<cv::Point2i> difference);
	bool casteling(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	bool check(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	pieceTypes dedectMovedPiece(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference);
	void rulecheck(PlaneState oldState, PlaneState newState, pieceTypes type, cv::Point2i enPassant_var, std::vector<cv::Point2i> difference);

	bool selection(PlaneState oldState, PlaneState newState, pieceTypes type, cv::Point2i enPassant_var, std::vector<cv::Point2i> difference);
	void rulebreak(bool inOrder);
};
