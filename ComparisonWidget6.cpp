#include "ComparisonWidget6.h"
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qgroupbox.h>



ComparisonWidget6::ComparisonWidget6(QWidget *parent)
	: QWidget(parent)
{
	//http://doc.qt.io/qt-5/qtwidgets-widgets-groupbox-window-cpp.html
	//http://www.qtforum.org/article/36854/adding-widgets-to-groupbox-that-is-in-a-main-layout.html

	QHBoxLayout* totalLayout = new QHBoxLayout();

	// -- begin reference
	QGroupBox* refGroup = new QGroupBox("Reference");
	QVBoxLayout* refLayout = new QVBoxLayout();

	refWgt = new CVImageWidget();
	refWgt->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	refScroll = new QScrollArea();
	refScroll->setWidget(refWgt);
	refScroll->setBackgroundRole(QPalette::Midlight);
	refScroll->setVisible(true);
	refScroll->setFrameStyle(0);

	refLayout->addWidget(refScroll);


	// -- end reference

	// -- begin questioned
	QGroupBox* questGroup = new QGroupBox("Questioned");
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
	QPushButton* run2But = new QPushButton("run2");
	refLayout->addWidget(run2But);
	QPushButton* noseBut = new QPushButton("nose");
	refLayout->addWidget(noseBut);
	// == end temp

	refGroup->setLayout(refLayout);
	questGroup->setLayout(questLayout);
	// -- end questioned

	totalLayout->addWidget(refGroup);
	totalLayout->addWidget(questGroup);
	setLayout(totalLayout);

	connect(runBut, &QPushButton::clicked, this, &ComparisonWidget6::runClicked);
	connect(run2But, &QPushButton::clicked, this, &ComparisonWidget6::run2Clicked);
	connect(noseBut, &QPushButton::clicked, this, &ComparisonWidget6::noseClicked);

	ii = 0;
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

void ComparisonWidget6::resize(cv::Mat& _tmp, const cv::Mat& img, QScrollArea *tmpScroll)
{
	float scaleFactor;

	if (true /*adjustToWidget*/) {
		QSize siz = tmpScroll->size();
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


void ComparisonWidget6::resizeEvent(QResizeEvent* event)
{

}


void ComparisonWidget6::showImage(cv::Mat img, QScrollArea *tmpScroll)
{
	cv::Mat _tmp;
	resize(_tmp, img, tmpScroll);
	((CVImageWidget*)tmpScroll->widget())->showImage(_tmp);
}


void ComparisonWidget6::run2Clicked(void)
{
	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\mtDatabas\\ID nr(1).bmp");
	showImage(img, refScroll);
	//((CVImageWidget*)refScroll->widget())->showImage(img);
	//refWgt->showImage(img);
}

void ComparisonWidget6::noseClicked(void)
{
	ii++;
	std::string filename = "C:\\2.Testdata\\Bilder\\mtDatabas\\ID nr(" + ii;
	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\mtDatabas\\ID nr(1).bmp");

//	std::string cascade_name = "C:\\1.Dep\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
//	std::string cascade_name = "C:\\1.Dep\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml";
	std::string cascade_name = "C:\\1.Dep\\haarcascades\\new\\Nariz.xml"; 
//-	std::string cascade_name = "C:\\1.Dep\\haarcascades\\new\\Mouth.xml"; 
	detectAndDisplay(img, cascade_name);
}

void ComparisonWidget6::detectAndDisplay(cv::Mat frame, std::string cascade_name)
{
	cv::CascadeClassifier	face_cascade;
	bool ok = face_cascade.load(cascade_name);

	std::vector<cv::Rect> faces;
	cv::Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		cv::Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(frame, center, cv::Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar(255, 0, 255), 4, 8, 0);

		cv::Mat faceROI = frame_gray(faces[i]);
		std::vector<cv::Rect> eyes;

		//-- In each face, detect eyes
		//eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

		//for (size_t j = 0; j < eyes.size(); j++)
		//{
		//	Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
		//	int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
		//	circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
		//}
	}
	//-- Show what you got
	showImage(frame, refScroll);

//	imshow(window_name, frame);
}



/*
H-fil
cv::CascadeClassifier face_cascade;

cv::Mat imgROIface;



Cpp-fil
naImgWidget::naImgWidget(QWidget *parent) : QWidget(parent)
{
ui.setupUi(this);

//	std::string face_cascade_name = "E:\\7.DEP\\OpenCV_3.1.0\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
std::string face_cascade_name = "E:\\7.DEP\\OpenCV_2.4.4\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
bool ok = face_cascade.load(face_cascade_name);

//cv::Mat image = cv::imread("D:\\6.Testdata\\Bilder\\faces\\omst_bilder\\#person039_214_bakom_bast-bast.bmp", true);
//ui.naImgWidget->showImage(image);


}




// Function Headers
void naImgWidget::detectAndDisplay(cv::Mat *frame, int no)
{
// se även: http://stackoverflow.com/questions/20757147/opencv-and-cdetect-face-in-image

// Global variables
// Copy this file from opencv/data/haarscascades to target folder

// moved to constructor
//std::string face_cascade_name = "D:\\7.DEP\\OpenCV_2.4.4\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";
//cv::CascadeClassifier face_cascade;
//face_cascade.load(face_cascade_name);

std::vector<cv::Rect> faces;
cv::Mat frame_gray;

cvtColor(*frame, frame_gray, cv::COLOR_BGR2GRAY);
equalizeHist(frame_gray, frame_gray);

// Detect faces
face_cascade.detectMultiScale(frame_gray, faces, 1.10, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(40, 40));

for( size_t i = 0; i < faces.size(); i++ )
{
cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
if(no < 619) {
rectangle(*frame, cv::Point(faces[i].x,faces[i].y),cv::Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),cv::Scalar(0,0,255),1,4,0);
cv::Rect rec(faces[i]);
imgROIface = (*frame)(rec).clone();
rectangle(*frame, rec, cv::Scalar(0, 255, 0), 3, 4, 0);

} else {
cv::Rect rec(faces[i]);
//rectangle(*frame, cv::Point(faces[i].x,faces[i].y),cv::Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),cv::Scalar(0,255,0),1,4,0);
imgROIface = (*frame)(rec).clone();
rectangle(*frame, rec, cv::Scalar(0,255,0),3,4,0);
/*	cv::Mat originalImage;
cv::Rect faceRect;
cv::Mat croppedFaceImage;

croppedFaceImage = originalImage(faceRect).clone();
Or alternatively:

originalImage(faceRect).copyTo(croppedImage);
//--
		}

		//ellipse( frame, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );
	}

	//	ellipse(frame_gray,cv::Point(40,40),cv::Size(20,20),0,0,360,cv::Scalar(255,0,255),4,8,0);




*/