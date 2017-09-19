#include "ComparisonWidget6.h"
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>



ComparisonWidget6::ComparisonWidget6(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout* totalLayout = new QVBoxLayout();
	QVBoxLayout* questLayout = new QVBoxLayout();
	QHBoxLayout*  questLine1 = new QHBoxLayout();
	QHBoxLayout*  questLine2 = new QHBoxLayout();

	// Create CVImage widgets w scollarea
	for (int i = 0; i < 6; i++) {
		CVImageWidget* tmp1 = new CVImageWidget();
		tmp1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		questWgts.append(tmp1);

		QScrollArea* tmp2 = new QScrollArea();
		tmp2->setWidget(tmp1);
		tmp2->setBackgroundRole(QPalette::Midlight);
		tmp2->setVisible(true);
		tmp2->setFrameStyle(0);
		questScroll.append(tmp2);

	}

	// Add cvimagewidget to qui  
	for (int i = 0; i < questWgts.size(); i++) {
		if(i<3)
			questLine1->addWidget(questScroll[i]);
		else
			questLine2->addWidget(questScroll[i]);
	}

	questLayout->addLayout(questLine1);
	questLayout->addLayout(questLine2);

	// == temp
	QPushButton* runBut = new QPushButton("run");
	questLayout->addWidget(runBut);
	// == end temp

	setLayout(questLayout);

	connect(runBut, &QPushButton::clicked, this, &ComparisonWidget6::runClicked);
}


ComparisonWidget6::~ComparisonWidget6()
{
}

void ComparisonWidget6::showImage(cv::Mat img, int wgtNo)
{
	cv::Mat _tmp;
	resize(_tmp, img, wgtNo);
	questWgts[wgtNo]->showImage(_tmp);
}

void ComparisonWidget6::resize(cv::Mat& _tmp, const cv::Mat& img, int wgtNo)
{
	float scaleFactor;

	if (true /*adjustToWidget*/) {
		QSize siz = questScroll[wgtNo]->size();
		double wig_w = double(siz.width());
		double wig_h = double(siz.height());
		double img_w = double(img.cols);
		double img_h = double(img.rows);

		if ((wig_w / img_w) > (wig_h / img_h))
			scaleFactor = wig_h / img_h;
		else
			scaleFactor = wig_w / img_w;

		//if( (double(siz.width()) / (double(img.cols)) > (double(siz.height()) / double(img.rows))
		//7 == 5 ? 4 : 3     // evaluates to 3, since 7 is not equal to 5.
	}

	if (scaleFactor > 1.0)
		cv::resize(img, _tmp, cv::Size(img.cols * scaleFactor, img.rows * scaleFactor), 0, 0, cv::INTER_CUBIC);
	else
		cv::resize(img, _tmp, cv::Size(img.cols * scaleFactor, img.rows * scaleFactor), 0, 0, cv::INTER_AREA);

}


void ComparisonWidget6::runClicked(void)
{
	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");

	for (int i = 0; i < questWgts.size(); i++) {
		showImage(img, i);
		//questWgts[i]->showImage(img);
	}
	int a = questWgts.size();

	//QMessageBox msgBox;
	//msgBox.setText("Prev");
	//msgBox.exec();
}

void ComparisonWidget6::resizeEvent(QResizeEvent* event)
{

}