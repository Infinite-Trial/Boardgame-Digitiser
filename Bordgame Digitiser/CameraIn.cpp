//Author:Gross

#include "CameraIn.h"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <thread>



CameraIn::CameraIn(int offset = 1) throw(bool)
{
	//connect to the cameras
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
		cam[i].set(CV_CAP_PROP_FRAME_WIDTH, SNAPSHOTWIDTH);
		cam[i].set(CV_CAP_PROP_FRAME_HEIGHT, SNAPSHOTHEIGHT);
		//set Focus
		cam[i].set(CV_CAP_PROP_AUTOFOCUS, 0);
		cam[i].set(CV_CAP_PROP_FOCUS, 1);
		//set FPS
		cam[i].set(CV_CAP_PROP_FPS, 15);
	}
	//get the tiles ROIs
	updateCameras();
	for (int i = 0; i < fieldROIs.size(); i++)
	{
		try {
			fieldROIs[i] = getFieldROIs(i);
		}
		catch (int detectedFields) {
			std::cout << "Fehler: Es konnten nur " << detectedFields << "/" << BOARDHEIGHT * BOARDWIDTH << " Spielfelder erkannt werden.";
			throw NotEnoughFields;
		}
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

	//1. on the first turn update the orientation of the board
	if (leftSide < 0) {
		updateBoardOrientation();
		for(int i = 0; i < cam.size(); i++)
		{
			mapToVirtualCoordinates(fieldROIs[i],i);
		}
	}

	//2. After the board is correctly detected:
	//The all ChessPieces are detected. 
	//Each type in a seperate thread
	//The virtual coordinates are returned as a chain of ChessPieces

	for (int i = 0; i < 12; i++){
		
		t_worker.push_back(std::thread( getPieceCoords, ref(fragments[i]), pieceTypes(i + 1), chessFields, snapshot));
	}
	//let all threads join
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
	//->compare every ChessPiece with every other ChessPiece 
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
	for (short n = 0; n < pics.size(); n++)
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
					if (maxoverlap < overlapRatio && overlapRatio > 5)
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
//For parallelisation add the TBB library
std::vector<cv::Rect> CameraIn::getPieceROIs(pieceTypes type, cv::Mat pic) throw(pieceTypes)
{
	cv::Size minSize(60,60), maxSize(100,160);
	std::vector<cv::Rect> pieceROIs;
	cv::CascadeClassifier cascade(cascadesPaths[type-1]);
	
	cascade.detectMultiScale(pic, pieceROIs, 1.1, 3, 0, minSize, maxSize);

	return pieceROIs;
}

std::array<std::array<cv::Rect*, 5>, 8> CameraIn::getFieldROIs(int picNumber) throw(int)
{
	std::vector<cv::Rect> ROIs;
	std::array<std::array<cv::Rect*, 5>, 8> layout = {NULL};

	CvSeq *contour, *result;
	CvMemStorage *storage = cvCreateMemStorage(0);
	double area;
	//convert mat to cvarr
	IplImage* tmp = &IplImage(snapshot[picNumber]);
	
	//remove unnececarry noise and clean the image
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
			std::vector<CvPoint> pt;
			for (int i = 0; i < 4; i++){
				pt[i] = *cvGetSeqElem(result, i);
			}

			// ignore all with x=0 
			if (!touchesBorder(pt)){
				//turn the polygon into a rectangle
				ROIs.push_back(toRect(pt));
			}
		}
		//obtain the next contour
		contour = contour->h_next;
	}
	// checks if all fields were detected
	if (ROIs.size() < 32)throw(ROIs.size());
	// construct black tiles
	sortBoard(layout,ROIs);
	constructBlack(layout);

	//show the results in debug mode
	if (debugMode)
	{	
		//drawing the rectangles
		for (int x = 0; x < layout.size(); x++)
		{
			for (int y = 0; y < layout[x].size(); y++)
			{
				cvRectangleR(tmp, *layout[x][y], cvScalar(255, 0, 0), 4);
			}
		}
		cv::namedWindow("DebugWindow");
		cvShowImage("DebugWindow",tmp);
	}
	
	return layout;
}

std::vector<ChessField> CameraIn::mapToVirtualCoordinates(std::array<std::array<cv::Rect*, 5>, 8> layout, int picNumber)
{
	std::vector<ChessField> fields;
	// get virtual coordinates
	for (int x = 0; x < layout.size(); x++)
	{
		int fy = picNumber == leftSide ? 8 - x : x;
		for (int y = 0; y < layout[x].size(); y++)
		{
			int fx = picNumber == leftSide ? 5 - y : 3 + y;
			fields.push_back(ChessField(*layout[x][y], cv::Point2i(fx, fy)));
		}
	}
	return fields;
}


void CameraIn::updateCameras() throw(bool)
{
	int n=0;
	double quality;
	for (short i = 0; i < cam.size(); i++)
	{
		do
		{
			//grab the next frame
			cam[n] >> snapshot[n];
			//convert to greyscale
			cv::cvtColor(snapshot[n], snapshot[n], cv::COLOR_BGR2GRAY);
			//check the blurrieness
			quality = blurryness(snapshot[n]);
			//try five times then throw an exeption
			if (n > 5)throw(false);
			n++;
		} while (quality < CAMTHRESHOLD);
	}
	
}

bool CameraIn::touchesBorder(std::vector<CvPoint> points)
{
	//checks if the polygon touches the picture border. returns true if so.
	for each (CvPoint p in points)
	{
		if (p.y==0||p.x)
		{
			return true;
		}
	}
	return false;
}

void CameraIn::updateBoardOrientation()
{
	//The programm checks on which side of the first snapshot the white king is positioned
	//if he is positioned at the right ride of the picture, 
	//it means that the camera is positioned on the left side of the Board.
	leftSide = getPieceROIs(WK, snapshot[0]).at(0).x > SNAPSHOTWIDTH / 2 ? 0 : 1;
}

cv::Rect CameraIn::toRect(std::vector<CvPoint> pts)
{
	int minx = SNAPSHOTWIDTH * 2, minx2 = SNAPSHOTWIDTH * 2, //the left edge
		miny = SNAPSHOTHEIGHT * 2, miny2 = SNAPSHOTHEIGHT * 2, //the upper edge
		maxx = 0, maxx2 = 0, //the right edge
		maxy = 0, maxy2 = 0, //the lower edge
		x, y;
	CvPoint a, c;

	
	for (char i = 0; i < 4; i++)
	{
		x = pts[i].x;
		y = pts[i].y;
		//the most left edge
		if (x < minx) {
			minx2 = minx;
			minx = x;
		}
		else {
			//the 2nd most left edge
			if (x < minx2) {
				minx2 = x;
			}
		}
		//the most right edge
		if (x > maxx) {
			maxx2 = maxx;
			maxx = x;
		}
		//the 2nd most right edge
		else {
			if (x > maxx2) {
				maxx2 = x;
			}
		}
		//------------------------
		//the highest edge
		if (x < miny) {
			miny2 = miny;
			miny = x;
		}
		else {
			//the 2nd highest edge
			if (x < miny2) {
				miny2 = x;
			}
		}
		//the lowest edge
		if (x > maxy) {
			maxy2 = maxx;
			maxy = x;
		}
		//the 2nd lowest edge
		else {
			if (x > maxy2) {
				maxy2 = x;
			}
		}

	}
	//get a (the upper left corner)
	a = cvPoint(average(minx,minx2),average(miny,miny2));
	//get c (the lower right corner)
	c = cvPoint(average(maxx, maxx2), average(maxy, maxy2));

	return cv::Rect(a, c);
}

void CameraIn::sortBoard(std::array<std::array<cv::Rect*, 5>, 8>& board, std::vector<cv::Rect> ROIs)
{
	const int lenghtOfXBlock = 5, lenghtOfYBlock = 4;
	std::array<cv::Rect*, 20> orderX, orderY;
	int x, y;
	
	//a serial indirect acess is created
	for ( x = 0; x < board.size(); x++)
	{
		for ( y = 0; y < board[x].size(); y++)
		{
			orderX[x*y + y] = board[x][y];
			orderY[x*y + y] = board[x][y];
		}
	}
	
	//insertion sort
	cv::Rect** max;
	//a rising list of x values is made
	for (int i = orderX.size() - 1; i >= 0; i--)
	{
		max = &orderX[i];
		for (int j = i; j >= 0; j--)
		{
			if (orderX[j]->x > (*max)->x)
			{
				max = &orderX[j];
			}
			std::swap(orderX[i], *max);
		}
	}
	//a rising list of y values is made
	for (int i = orderY.size() - 1; i >= 0; i--)
	{
		max = &orderY[i];
		for (int j = i; j >= 0; j--)
		{
			if (orderY[j]->x > (*max)->x)
			{
				max = &orderY[j];
			}
			std::swap(orderY[i], *max);
		}
	}


	//now asign the ROIs to the right places
	//all even y
	//iterating through all 
	for (x = 1; x < board.size(); x += 2)
	{
		for (y = 0; y < board[x].size(); y += 2)
		{
			for (int i = 0; i < lenghtOfXBlock; i++)
			{
				for (int j = 0; j < lenghtOfXBlock; j++)
				{
					if (orderY[y * 4 + i] == orderX[y * 5 + j])
						board[x][y] = orderY[y * 4 + i];
				}
			}
		}
	}

	//all uneven ys
	for (x = 0; x < board.size(); x += 2)
	{
		for (y = 1; y < board[x].size(); y += 2)
		{
			for (int i = 0; i < lenghtOfXBlock; i++)
			{
				for (int j = 0; j < lenghtOfXBlock; j++)
				{
					if (orderY[y * 4 + i] == orderX[y * 5 + j])
						board[x][y] = orderY[y * 4 + i];
				}
			}
		}
	}
}

void CameraIn::constructBlack(std::array<std::array<cv::Rect*, 5>, 8>& board)
{
	int x, y;
	//all in y=4 and y=2
	for ( x = 0; x < board.size()-1; x+=2)
	{
		for ( y = 2; y < board[x].size(); y+=2)
		{
			board[x][y] = new cv::Rect(board[x][y-1]->tl(), board[x+1][y]->tl());
		}
	}
	//all in y=3 and y=1
	for ( x = 1; x < board.size(); x += 2)
	{
		for ( y = 1; y < board[x].size(); y += 2)
		{
			board[x][y] = new cv::Rect(board[x][y - 1]->tl(), board[x + 1][y]->tl());
		}
	}
	//y=0
	y = 0;
	for ( x = 0; x < board.size(); x += 2)
	{
		int nx1 = board[x][y + 1]->x,
			ny1 = board[x][y + 1]->y + board[x][y + 1]->height,
			nx2 = board[x + 1][y]->x ,
			ny2 = board[x + 1][y]->y + board[x + 1][y]->width;
		board[x][y] = new cv::Rect(cv::Point2i(nx1, ny1), cv::Point2i(nx2, ny2));
	}
}

int average(int A,int B) {
	return (A + B) / 2;
}

double CameraIn::blurryness(cv::Mat img_gray) {
	cv::Mat dst;
	cv::Scalar mean, stddev;

	Laplacian(img_gray, dst, CV_64F);

	meanStdDev(dst, mean, stddev, cv::Mat());

	return stddev.val[0] * stddev.val[0];
}
