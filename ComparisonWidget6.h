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

private slots:
	void runClicked(void);

private:
	void resize(cv::Mat & _tmp, const cv::Mat & img, int wgtNo);

	void resizeEvent(QResizeEvent * event);

	QList<CVImageWidget *> questWgts;
	QList<QScrollArea *> questScroll;
};

#endif

