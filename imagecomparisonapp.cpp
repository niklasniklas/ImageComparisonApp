#include "imagecomparisonapp.h"
#include <qpushbutton.h>
#include <qgridlayout.h>

ImageComparisonApp::ImageComparisonApp()
{
	QGridLayout* startUpLayout = new QGridLayout();
	QPushButton* but1 = new QPushButton("One of Six Test");
	QPushButton* but2 = new QPushButton("BBB");
	QPushButton* but3 = new QPushButton("CCC");
	QPushButton* but4 = new QPushButton("DDD");
	QPushButton* but5 = new QPushButton("EEE");
	QPushButton* but6 = new QPushButton("FFF");
	startUpLayout->addWidget(but1, 0, 0, 1, 1);
	startUpLayout->addWidget(but2, 0, 1, 1, 1);
	startUpLayout->addWidget(but3, 0, 2, 1, 1);
	startUpLayout->addWidget(but4, 1, 0, 1, 1);
	startUpLayout->addWidget(but5, 1, 1, 1, 1);
	startUpLayout->addWidget(but6, 1, 2, 1, 1);

	setLayout(startUpLayout);
	setCentralWidget(but1);
	connect(but1, &QPushButton::clicked, this, &ImageComparisonApp::but1Clicked);

//	OneOfSixWidget = new ComparisonWidget6(this);
//	setCentralWidget(OneOfSixWidget);
//	setMinimumSize(500, 500);
}

ImageComparisonApp::~ImageComparisonApp()
{

}

void ImageComparisonApp::but1Clicked(void)
{
	OneOfSixWidget = new ComparisonWidget6(this);
	setCentralWidget(OneOfSixWidget);
	setMinimumSize(500, 500);

}
