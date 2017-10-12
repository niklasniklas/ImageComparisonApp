#ifndef COMPARISONWIDGET6_H
#define COMPARISONWIDGET6_H

#include <qwidget.h>
#include <cvimagewidget.h>
#include <qscrollarea.h>

class ComparisonWidget6 :	public QWidget
{
	Q_OBJECT

public:
	ComparisonWidget6(QWidget *parent);
	~ComparisonWidget6();

	void showImage(cv::Mat img, int wgtNo);
	void showImage(cv::Mat img, QScrollArea *tmpScroll);

private slots:
	void runClicked(void);
	void run2Clicked(void);
	void noseClicked(void);

private:
	void resize(cv::Mat & _tmp, const cv::Mat & img, int wgtNo);
	void resize(cv::Mat& _tmp, const cv::Mat& img, QScrollArea *tmpScroll);
	void detectAndDisplay(cv::Mat frame, std::string cascade_name);

//events
	void resizeEvent(QResizeEvent * event);

	CVImageWidget*			refWgt;
	QScrollArea*			refScroll;
	QList<CVImageWidget *>	questWgts;
	QList<QScrollArea *>	questScroll;

	int ii;

};

#endif

