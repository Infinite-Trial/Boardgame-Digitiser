#include "UIBoard.h"
#include "UIMenu.h"
#include <opencv2/core/utility.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <ctype.h>


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
}
