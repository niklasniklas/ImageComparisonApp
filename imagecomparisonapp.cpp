#include "imagecomparisonapp.h"

ImageComparisonApp::ImageComparisonApp()
{
	questioned = new ComparisonWidget6(this);
	setCentralWidget(questioned);
	setMinimumSize(500, 500);
}

ImageComparisonApp::~ImageComparisonApp()
{

}
