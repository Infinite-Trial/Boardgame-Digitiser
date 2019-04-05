#include "Board.h"
//W-Forms
using namespace System;
using namespace System::Windows::Forms;
//Opencv
#include <opencv2/core/utility.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
//Others
#include <iostream>
#include <ctype.h>

using namespace cv;
using namespace std;

[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BordgameDigitiser::Board form;
	Application::Run(%form);
}
