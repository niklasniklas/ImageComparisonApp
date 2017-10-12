#ifndef IMAGECOMPARISONAPP_H
#define IMAGECOMPARISONAPP_H

#include <QtWidgets/QMainWindow>
#include "ComparisonWidget6.h"


class ImageComparisonApp : public QMainWindow
{
	Q_OBJECT

public:
	ImageComparisonApp();
	~ImageComparisonApp();

private slots:
	void but1Clicked(void);

private:
	ComparisonWidget6* OneOfSixWidget;
};

#endif // IMAGECOMPARISONAPP_H
