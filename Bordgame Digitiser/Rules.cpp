#include "Rules.h"

bool whitePawn(PlaneState oldState, PlaneState newState)
{

	return false;
}

bool check(PlaneState oldState, PlaneState newState, std::vector<cv::Point2i> difference)
{
	return false;
}

void rulecheck(PlaneState oldState, PlaneState newState, pieceTypes type, cv::Point2i enPassant_var, std::vector<cv::Point2i> difference)
{
	switch (difference.size()) {
	case 2: 
		promotion(newState, oldState, difference);
		selection(newState, oldState, captureOrMove(newState, oldState, difference), enPassant_var, difference);		
		break;
	case 3:
		enPassant(newState, oldState, enPassant_var, difference);
		break;
	case 4:
		casteling(newState, oldState, difference);
		break;
	default:
		rulebreak();
		break
	}
}
