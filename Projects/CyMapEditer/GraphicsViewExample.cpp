#include "GraphicsViewExample.h"

GraphicsViewExample::GraphicsViewExample(QWidget* parent)
    : QGraphicsView(parent) {

    // 创建场景
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    setScene(scene);

    // 设置视图属性
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    CubeItem* m_cube = new CubeItem(150.0f);
    scene->addItem(m_cube);
    m_cube->setPos(400, 400);
}

void GraphicsViewExample::wheelEvent(QWheelEvent* event) {
    // 鼠标滚轮缩放
    if (event->angleDelta().y() > 0) {
        scale(1.2, 1.2);
    }
    else {
        scale(1 / 1.2, 1 / 1.2);
    }
}

void GraphicsViewExample::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Plus:
        scale(1.2, 1.2);
        break;
    case Qt::Key_Minus:
        scale(1 / 1.2, 1 / 1.2);
        break;
    case Qt::Key_R:
        resetTransform();
        break;
    }
}