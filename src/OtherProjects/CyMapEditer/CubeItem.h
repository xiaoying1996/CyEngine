#ifndef CUBEITEM_H
#define CUBEITEM_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector3D>
#include <QTimer>

class CubeItem : public QGraphicsItem
{
public:
    CubeItem(float size = 100.0f);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
        QWidget* widget = nullptr) override;

    void setRotation(float x, float y, float z);
    void setPerspective(float perspective);

private:
    void updateVertices();
    QPointF projectPoint(const QVector3D& point) const;

    float m_size;
    float m_perspective;
    QVector3D m_rotation;

    // 立方体的8个顶点（局部坐标）
    QVector<QVector3D> m_localVertices;
    QVector<QVector3D> m_transformedVertices;

    // 立方体的6个面，每个面由4个顶点索引组成
    QVector<QVector<int>> m_faces;

    // 面的颜色
    QVector<QColor> m_faceColors;
    QVector<QVector3D> m_vertices;
};

#endif // CUBEITEM_H