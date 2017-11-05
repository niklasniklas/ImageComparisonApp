#include "GlasgowWidget.h"
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qgroupbox.h>
#include <QMouseEvent>


GlasgowWidget::GlasgowWidget(QWidget *parent)
	: ComparisonWidget_generic(parent)
{
	_difficulty = 1;
	QGroupBox* group = new QGroupBox("Same or Different");

	// Add CVImageWidget
	QVBoxLayout* vlayout = new QVBoxLayout();
	{
		CVImageWidget* tmp1 = new CVImageWidget(this, 0);
		tmp1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		imgWgts.append(tmp1);

		QScrollArea* tmp2 = new QScrollArea();
		tmp2->setWidget(tmp1);
		tmp2->setBackgroundRole(QPalette::Midlight);
		tmp2->setVisible(true);
		tmp2->setFrameStyle(0);
		imgScroll.append(tmp2);
	}

	// Buttons
	QHBoxLayout* hlayout = new QHBoxLayout();
	QPushButton* btn1 = new QPushButton("Same");
	QPushButton* btn2 = new QPushButton("Different");
	btn1->setFixedSize(100, 50);
	btn2->setFixedSize(100, 50);
	hlayout->addStretch();
	hlayout->addWidget(btn1);
	hlayout->addStretch();
	hlayout->addWidget(btn2);
	hlayout->addStretch();

	
	// Total layout
	vlayout->addWidget(imgScroll[0]);
	vlayout->addLayout(hlayout);

	setLayout(vlayout);

	connect(btn1, &QPushButton::clicked, this, &GlasgowWidget::btn1Clicked);
	connect(btn2, &QPushButton::clicked, this, &GlasgowWidget::btn2Clicked);

}


GlasgowWidget::~GlasgowWidget()
{
}

void GlasgowWidget::widgetClicked(int no)
{
	int a = 0;
}

void GlasgowWidget::setDifficulty(int no)
{
	_difficulty = no;
}

void GlasgowWidget::btn1Clicked(void)
{
	QMessageBox msgBox;
	msgBox.setText("btn1");
	msgBox.exec();

	cv::Mat img = cv::imread("C:\\Testdata\\mtDatabas\\ID nr(5).jpg");
	imgWgts[0]->showImage(img);

}

void GlasgowWidget::btn2Clicked(void)
{
	QMessageBox msgBox;
	msgBox.setText("btn2");
	msgBox.exec();
}

void GlasgowWidget::resizeEvent(QResizeEvent * event)
{
}

void GlasgowWidget::mouseEvent(QMouseEvent * event)
{
}


