#include "imagecomparisonapp.h"
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qboxlayout.h>
#include <qgroupbox.h>

ImageComparisonApp::ImageComparisonApp()
{
	QGridLayout* startUpLayout = new QGridLayout();
	QPushButton* but1 = new QPushButton("One of Six Test");
	QPushButton* but2 = new QPushButton("Same or Different");
	QPushButton* but3 = new QPushButton("Dummy 3");
	QPushButton* but4 = new QPushButton("Dummy 4");
	QPushButton* but5 = new QPushButton("Dummy 5");
	QPushButton* but6 = new QPushButton("Dummy 6");
	startUpLayout->addWidget(but1, 0, 0, 1, 1);
	startUpLayout->addWidget(but2, 0, 1, 1, 1);
	startUpLayout->addWidget(but3, 0, 2, 1, 1);
	startUpLayout->addWidget(but4, 1, 0, 1, 1);
	startUpLayout->addWidget(but5, 1, 1, 1, 1);
	startUpLayout->addWidget(but6, 1, 2, 1, 1);

	QGroupBox* group = new QGroupBox("Choose Comparison Test");
	group->setLayout(startUpLayout);
	setCentralWidget(group);

	setMinimumSize(400, 100);

//	setLayout(startUpLayout);
//	setCentralWidget(but1);
	connect(but1, &QPushButton::clicked, this, &ImageComparisonApp::but1Clicked);
	connect(but2, &QPushButton::clicked, this, &ImageComparisonApp::but2Clicked);


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
	setMinimumSize(800, 500);
	showMaximized();
}

void ImageComparisonApp::but2Clicked(void)
{
	glasgowWidget = new GlasgowWidget(this);
	setCentralWidget(glasgowWidget);
	setMinimumSize(700, 500);
	showMaximized();
}
