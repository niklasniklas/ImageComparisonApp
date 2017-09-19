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

private:
	ComparisonWidget6* questioned;
};

#endif // IMAGECOMPARISONAPP_H
