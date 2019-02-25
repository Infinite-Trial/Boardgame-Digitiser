//Author:Gross

#include "CameraIn.h"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <thread>



CameraIn::CameraIn(int offset = 1) throw(bool)
{
	cam[0] = cv::VideoCapture(0 + offset);
	cam[1] = cv::VideoCapture(1 + offset);
	if (!cam[0].isOpened()||!cam[1].isOpened())
	{
		std::cout << "Es konnte nicht auf alle Kameras zugegriffen werden.";
		throw(false);
	}
	//set the camera properties
	for (short i = 0; i < cam.size(); i++)
	{
		//set resolution
		cam[i].set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		cam[i].set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		//set Focus
		cam[i].set(CV_CAP_PROP_AUTOFOCUS, 0);
		cam[i].set(CV_CAP_PROP_FOCUS, 1);
		//set FPS
		cam[i].set(CV_CAP_PROP_FPS, 15);
	}
	
}

PlaneState CameraIn::getBoardStatePlane() throw (BOARDeRRORS)
{
	//This funktion should read the CameraInput, detect the board + all chesspieces 
	//and return the current Planestate
	PlaneState currentState;
	std::array<std::vector<ChessField>,2> chessFields;
	std::vector<ChessPiece> fullchainState;
	std::array<std::vector<ChessPiece>, 12> fragments;
	std::vector<std::thread> t_worker;
	//0.update the cameras
	updateCameras();

	//1. The programm searches for the board and its fields.
	try {
		chessFields[0] = getChessFields(0);
		chessFields[1] = getChessFields(1);
	}
	catch (int detectedFields) {
		std::cout << "Fehler: Es konnten nur " << detectedFields << "/" << BOARDHEIGHT * BOARDWIDTH << " Spielfelder erkannt werden.";
		throw NotEnoughFields;
	}
	//2. After the board is correctly detected:
	//The all ChessPieces are detected. 
	//Each type in a seperate thread
	//The virtual coordinates are returned as a chain of ChessPieces

	for (int i = 0; i < 12; i++){
		t_worker.push_back(std::thread{ getPieceCoords, ref(fragments[i]), pieceTypes(i + 1), chessFields });
	}
	for (int i = 0; i < t_worker.size(); i++){
		if(t_worker[i].joinable()) t_worker[i].join();
	}
	//connect the chains
	for each (std::vector<ChessPiece> frag in fragments)
	{
		for each (ChessPiece piece in frag)
		{
			fullchainState.push_back(piece);
		}
	}
	
	//3. checking for errors
	if (fullchainState.size()>32){
		throw(TooManyPieces);
	}
	//check for double assigned fields
	
	//compare every ChessPiece with every other ChessPiece 
	for (int i = 0; i < fullchainState.size(); i++)
	{
		for (int n = i + 1; n < fullchainState.size(); n++)
		{
			if (fullchainState[i].getPos() == fullchainState[n].getPos())
				throw(UnclearPiecePosition);
		}
	}
	
	//4. convert the chain to a plane and return it
	return chainToPlane(fullchainState);
}
PlaneState CameraIn::chainToPlane(std::vector<ChessPiece> pieceChain)
{
	//A chain of ChessPieces is taken and converted into a 2D vector of chesspieces
	//From: {(WR,0/0),(WP,0/1),(BP,0/6),(BR,0/7),(WN,1/1),(WP,1/2),(BP,1/6),(BN,1/7), ... }	To:	 {{WR,WP,NP,NP,NP,NP,BP,BR},
	//																							  {WN,WP,NP,NP,NP,NP,BP,BN},
	//																							  {WB,WP,NP,NP,NP,NP,BP,BB},
	//																											.
	//																											.
	//																											.			}
	PlaneState Plain;
	cv::Point2i c;
	for each (ChessPiece element in pieceChain)
	{
		c=element.getPos();
		Plain.setPieceAt(c.x,c.y,element.getType());
	}
	return Plain;
}
std::vector<ChessPiece> CameraIn::planeToChain(PlaneState piecePlain)
{
	//A 2D vector of chesspieces is taken and converted into a chain of ChessPieces
	//from: {{WR,WP,NP,NP,NP,NP,BP,BR},	To:{(WR,0/0),(WP,0/1),(BP,0/6),(BR,0/7),(WN,1/1),(WP,1/2),(BP,1/6),(BN,1/7), ... }
	//		 {WN,WP,NP,NP,NP,NP,BP,BN},
	//		 {WB,WP,NP,NP,NP,NP,BP,BB},
	//					.
	//					.
	//					.			  }
	std::vector<ChessPiece> chain;
	ChessPiece piece;
		for (int x = 0; x < piecePlain.width; x++)
		{
			for (int y = 0; y < piecePlain.length; y++)
			{
				piece = ChessPiece(cv::Point2i(x, y), piecePlain.getPieceAt(x, y));
				chain.push_back(piece);
			}
		}
	return chain;
}

void CameraIn::toggleDebug()
{
	debugMode = !debugMode;
}

//maybe needs adjustments
void CameraIn::getPieceCoords(std::vector<ChessPiece> &chainFragment,pieceTypes type, std::array<std::vector<ChessField>,2> chessfields, std::array<cv::Mat, 2> pics) throw(int)
{
	//This funktion assigns each detected Chesspiece to the chessfield with which it overlapps the most.
	
	int AUnion, AIntersection;
	//all cams are cycled through
	for (short n = 0; n < chessfields.size(); n++)
	{
		//look for the field the pieceROI overlaps the most with
		std::vector<cv::Rect> pROIs = getPieceROIs(type,pics[n]);
		for each (cv::Rect pieceROI in pROIs)
		{
			int maxoverlap = 0, overlappingField = -1, overlapRatio;
			for (short i = 0; i < chessfields[n].size(); i++)
			{
				AIntersection = (pieceROI & chessfields[n][i].getFieldROI()).area();
				//fields with no overlap are ignored
				if (AIntersection > 0) {
					//the overlapping field is determined over the overpalratio, becaue not all fieldROIs have to be the same size.
					AUnion = (pieceROI | chessfields[n][i].getFieldROI()).area();
					overlapRatio = AIntersection / AUnion;
					if (maxoverlap < overlapRatio)
					{
						maxoverlap = overlapRatio;
						overlappingField = i;
					}
				}
			}
			//the piecetype and the coresponding chessfield are combined to a ChessPiece and added to the output-chain
			chainFragment.push_back(ChessPiece(chessfields[n][overlappingField].getFieldCoord(), type));
		}
	}
}

//unfinished
std::vector<cv::Rect> CameraIn::getPieceROIs(pieceTypes type, cv::Mat pic) throw(pieceTypes)
{
	std::vector<cv::Rect> pieceROIs;

	
	//you have to create the classefier and use detectMulti...whatever




	return pieceROIs;
}
//unfinished
std::vector<ChessField> CameraIn::getChessFields(int picNumber)
{
	std::vector<ChessField> fieldROIs;

	CvSeq *contour, *result;
	CvMemStorage *storage = cvCreateMemStorage(0);
	double area;
	//convert mat to cvarr
	IplImage* tmp = &IplImage(snapshot[picNumber]);
	


	//remove unnececarry noise
	cvSmooth(tmp, tmp, CV_GAUSSIAN, 3, 3);
	cvThreshold(tmp, tmp, 100, 255, CV_THRESH_BINARY_INV);
	 
	//finding all contours in the image
	cvFindContours(tmp, storage, &contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	
	while (contour)
	{
		//obtain a sequence of points of the countour, pointed by the variable 'countour'
		result = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contour)*0.02, 0);

		//if there are 4 vertices in the contour and the area of the rectangle is more than 10000 pixels
		area = fabs(cvContourArea(result, CV_WHOLE_SEQ));
		if (result->total == 4 && area > 10000 && area < 20000)
		{
			//convert the sequence to a vector of CvPoints
			std::vector<CvPoint*> pt;
			for (int i = 0; i < 4; i++)
			{
				pt[i] = (CvPoint*)cvGetSeqElem(result, i);
			}

			// ignore all with x=0 
			if (!touchesBorder(pt))
			{
				// get virtual coordinates
				// 
				//
				//

				//drawing lines around the rectangle
				if (debugMode)
				{
					cvLine(tmp, *pt[0], *pt[1], cvScalar(255, 0, 0), 4);
					cvLine(tmp, *pt[1], *pt[2], cvScalar(255, 0, 0), 4);
					cvLine(tmp, *pt[2], *pt[3], cvScalar(255, 0, 0), 4);
					cvLine(tmp, *pt[3], *pt[0], cvScalar(255, 0, 0), 4);
				}
			}
		}
		//obtain the next contour
		contour = contour->h_next;
	}


	//show the results in debug mode
	if (debugMode)
	{
		cv::namedWindow("DebugWindow");
		cvShowImage("DebugWindow",tmp);
	}
	//close the window
	cv::destroyWindow("DebugWindow");
	if (fieldROIs.size() < BOARDHEIGHT*BOARDWIDTH)
		throw fieldROIs.size();
	return fieldROIs;
}

void CameraIn::updateCameras()
{
	int quality;
	do
	{
		//grab the next frame
		for (short i = 0; i < cam.size(); i++)
		{
			cam[i]>>snapshot[i];
		}
		//blurdetection

	} while (quality<CAMTHRESHOLD);
	//convert to greyscale

}

bool CameraIn::touchesBorder(std::vector<CvPoint*> points)
{
	//checks if the polygon touches the picture border. returns true if so.
	for each (CvPoint* p in points)
	{
		if (p->y==0||p->x)
		{
			return true;
		}
	}
	return false;
}

