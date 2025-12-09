#ifndef _GRAPHICSVIEWEXAMPLE_
#define _GRAPHICSVIEWEXAMPLE_


// graphicsviewexample.h
#include <QGraphicsView>
#include <QWheelEvent>
#include <QKeyEvent>
#include "Shapes/CubeItem.h"

class GraphicsViewExample : public QGraphicsView {
    Q_OBJECT

public:
    explicit GraphicsViewExample(QWidget* parent = nullptr);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
};

#endif

