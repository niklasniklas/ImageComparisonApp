#ifndef IMAGECOMPARISONAPP_H
#define IMAGECOMPARISONAPP_H

#include <QtWidgets/QMainWindow>
#include "ComparisonWidget6.h"
#include "GlasgowWidget.h"


class ImageComparisonApp : public QMainWindow
{
	Q_OBJECT

public:
	ImageComparisonApp();
	~ImageComparisonApp();

private slots:
	void but1Clicked(void);
	void but2Clicked(void);

private:
	ComparisonWidget6* OneOfSixWidget;
	GlasgowWidget*		glasgowWidget;
};

#endif // IMAGECOMPARISONAPP_H
