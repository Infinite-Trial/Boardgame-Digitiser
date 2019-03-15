#include "Rules.h"

bool whitePawn(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference)
{
	cv::Point2i oldPoint, newPoint;
	if (oldState.getPieceAt(difference[0]) == WP) {
		oldPoint = difference[0];
	}
	else {
		newPoint = difference[0];
	}
	return false;
}

bool check(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference)
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

void rulecheck(PlaneState oldState, PlaneState newState, pieceTypes type, cv::Point2i enPassant_var, std::vector<cv::Point2i> difference)
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

