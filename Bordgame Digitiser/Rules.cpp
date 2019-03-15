#include "Rules.h"

Rules::Rules() 
{
	enPassant_var.x = -1;
	enPassant_var.y = -1;
}

bool Rules::whitePawn(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference, cv::Point2i enPassant_var)
{
	cv::Point2i oldPoint, newPoint;
	if (oldState.getPieceAt(difference[0]) == WP) {
		oldPoint = difference[0];
		newPoint = difference[1];
	}
	else {
		newPoint = difference[0];
		oldPoint = difference[1];
	}

	if (abs(oldPoint.x - newPoint.x) == 1 && oldPoint.y - newPoint.y == 1) {
		if (oldState.getPieceAt(newPoint) != NP) {
			return false;
		}
		if (enPassant_var != cv::Point2i(-1,-1)) {
			if (oldState.getPieceAt(cv::Point2i(newPoint.x, oldPoint.y)) != NP)
				enPassant_var = cv::Point2i(-1, -1);
				return false;
			return true;
		}
		return true;
	}
	if (oldPoint.y == 7) {
		if (oldPoint.y - newPoint.y == 2) {
			enPassant_var = newPoint;
			return false;
		}
	}
	if (oldPoint.y - newPoint.y == 1)
		return false;
	return true;

}

bool Rules::blackPawn(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference, cv::Point2i enPassant_var)
{
	cv::Point2i oldPoint, newPoint;
	if (oldState.getPieceAt(difference[0]) == BP) {
		oldPoint = difference[0];
		newPoint = difference[1];
	}
	else {
		newPoint = difference[0];
		oldPoint = difference[1];
	}

	if (abs(oldPoint.x - newPoint.x) == 1 && newPoint.y - oldPoint.y == 1) {
		if (oldState.getPieceAt(newPoint) != NP) {
			return false;
		}
		if (enPassant_var != cv::Point2i(-1, -1)) {
			if (oldState.getPieceAt(cv::Point2i(newPoint.x, oldPoint.y)) != NP)
				return false;
			return true;
		}
		return true;
	}
	if (oldPoint.y == 2) {
		if (newPoint.y - oldPoint.y == 2) {
			enPassant_var = newPoint;
			return false;
		}
	}
	if (newPoint.y - oldPoint.y == 1)
		return false;
	return true;

}

bool Rules::king(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference)
{
	cv::Point2i oldPoint, newPoint;
	if (oldState.getPieceAt(difference[0]) == BK || oldState.getPieceAt(difference[0]) == BK) {
		oldPoint = difference[0];
		newPoint = difference[1];
	}
	else {
		newPoint = difference[0];
		oldPoint = difference[1];
	}
	if (abs(oldPoint.x - newPoint.x) < 1 && abs(oldPoint.y - newPoint.y) < 1) {
		check(oldState, newState, difference);
		return false;
	}
	return false;
}



bool Rules::check(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference)
{

	return false;
}

pieceTypes dedectMovedPiece(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference)
{

	if (oldState.getPieceAt(difference[0]) == newState.getPieceAt(difference[1])) {

		return newState.getPieceAt(difference[1]);
	}

	if (oldState.getPieceAt(difference[1]) == newState.getPieceAt(difference[0])) {

		return newState.getPieceAt(difference[0]);
	}

}

void Rules::rulecheck(PlaneState oldState, PlaneState newState, pieceTypes type, cv::Point2i enPassant_var, std::vector<cv::Point2i> difference)
{
	switch (difference.size()) {
	case 2:
		rulebreak(promotion(newState, oldState, difference));
		rulebreak(selection(newState, oldState, dedectMovedPiece(newState, oldState, difference), enPassant_var, difference));
		break;
	case 3:
		rulebreak(enPassant(newState, oldState, enPassant_var, difference));
		break;
	case 4:
		rulebreak(casteling(newState, oldState, difference));
		break;
	default:
		rulebreak(true);
		break;
	}
}

