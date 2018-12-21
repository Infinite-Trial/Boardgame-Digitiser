#include "UIMenu.h"

using namespace System;
using namespace System::Windows::Forms;


#include <opencv2/core/utility.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <ctype.h>
using namespace cv;
using namespace std;

[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BordgameDigitiser::UIMenu form;
	Application::Run(%form);