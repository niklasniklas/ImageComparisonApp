#ifndef COMPARISONWIDGET_GENERIC_H
#define COMPARISONWIDGET_GENERIC_H

#include <qwidget.h>
#include <cvimagewidget.h>

class ComparisonWidget_generic : public QWidget
{
	Q_OBJECT

public:
	ComparisonWidget_generic(QWidget *parent);
	~ComparisonWidget_generic();

	virtual void widgetClicked(int no) = 0;

};

#endif