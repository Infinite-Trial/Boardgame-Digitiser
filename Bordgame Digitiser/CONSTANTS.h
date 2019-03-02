#pragma once
#include <vector>
enum pieceTypes {NP, BB, BK, BN, BP, BQ, BR, WB, WK, WN, WP, WQ, WR };
enum chessCoord { A, B, C, D, E, F, G, H };
const int BOARDWIDTH = 8;
const int BOARDHEIGHT = 8;
const int CAMTHRESHOLD = 100;
const int SNAPSHOTWIDTH = 1280;
const int SNAPSHOTHEIGHT = 720;
//all the filepaths of the cascades
const std::string cascadesPaths[12]={
"../Cascades/BB",
"../Cascades/BK",
"../Cascades/BN",
"../Cascades/BP",
"../Cascades/BQ",
"../Cascades/BR",
"../Cascades/WB",
"../Cascades/WK",
"../Cascades/WN",
"../Cascades/WP",
"../Cascades/WQ",
"../Cascades/WR" };
	
	