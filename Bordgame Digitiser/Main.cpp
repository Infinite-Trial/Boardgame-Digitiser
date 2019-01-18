#include "UIBoard.h"
#include "UIMenu.h"
#include <opencv2/core/utility.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <ctype.h>
#include <chrono>
#include "Board.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace cv;

[STAThreadAttribute]
void Main() {
	/*Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BordgameDigitiser::UIMenu formMenu;
	Application::Run(%formMenu);*/
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BordgameDigitiser::UIBoard formBoard;
	Application::Run(%formBoard);
	/*Board board = Board();
	_sleep(10000);
	board.setCurrState(PlaneState({{BR,BP,NP,NP,NP,NP,WP,WR},
						{BN,BP,NP,NP,NP,NP,WP,WN},
						{BB,BP,NP,NP,NP,NP,WP,WB},
						{BQ,BP,NP,NP,NP,NP,WP,WQ},
						{BK,BP,NP,NP,NP,NP,WP,WK},
						{BB,BP,NP,NP,NP,NP,WP,WB},
						{BN,BP,NP,NP,NP,NP,WP,WN},
						{BR,BP,NP,NP,NP,NP,WP,WR}} ));
	board.setPrevState({{BR,BP,NP,NP,NP,NP,WP,WR},
						{BN,BP,NP,NP,NP,NP,WP,WN},
						{BB,BP,NP,NP,NP,NP,WP,WB},
						{BQ,BP,NP,NP,NP,NP,WP,WQ},
						{BK,BP,NP,NP,NP,NP,WP,WK},
						{BB,BP,NP,NP,NP,NP,WP,WB},
						{BN,BP,NP,NP,NP,NP,WP,WN},
						{BR,BP,NP,NP,NP,NP,WP,WR}});*/


}
