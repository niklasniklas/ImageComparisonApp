#ifndef GLASGOWWIDGET_H
#define GLASGOWWIDGET_H

#include <qwidget.h>
#include <cvimagewidget.h>
#include <qscrollarea.h>
#include <ComparisonWidget_generic.h>


class GlasgowWidget : public ComparisonWidget_generic
{
	Q_OBJECT

public:
	GlasgowWidget(QWidget *parent);
	~GlasgowWidget();

	virtual void widgetClicked(int no);
	void setDifficulty(int no);

private slots:
	void btn1Clicked(void);
	void btn2Clicked(void);

private:
	void resizeEvent(QResizeEvent * event);
	void mouseEvent(QMouseEvent* event);

	int _difficulty;  // between 1-10
	QList<CVImageWidget *>	imgWgts;
	QList<QScrollArea *>	imgScroll;

};

#endif