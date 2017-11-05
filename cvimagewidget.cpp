#include "cvimagewidget.h"
#include <QMouseEvent>
#include <ComparisonWidget_generic.h>

void CVImageWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->type() == QMouseEvent::MouseButtonPress)
    {
        int a = 0;
		_parent->widgetClicked(_id);
    }
}
