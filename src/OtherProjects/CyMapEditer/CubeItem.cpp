#include "cubeitem.h"
#include <QPainter>
#include <QVector>

CubeItem::CubeItem(float size)
    : m_size(size)
{
    // 初始化立方体的8个顶点（局部坐标）
    float half = size / 2.0f;
    m_vertices = {
        QVector3D(-half, -half, -half), // 0: 左-下-前
        QVector3D(half, -half, -half), // 1: 右-下-前
        QVector3D(half,  half, -half), // 2: 右-上-前
        QVector3D(-half,  half, -half), // 3: 左-上-前
        QVector3D(-half, -half,  half), // 4: 左-下-后
        QVector3D(half, -half,  half), // 5: 右-下-后
        QVector3D(half,  half,  half), // 6: 右-上-后
        QVector3D(-half,  half,  half)  // 7: 左-上-后
    };
}

QRectF CubeItem::boundingRect() const
{
    float padding = m_size * 1.5f;
    return QRectF(-m_size - padding, -m_size - padding,
        2 * (m_size + padding), 2 * (m_size + padding));
}

void CubeItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
    QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);

    // 定义立方体的6个面（顶点索引）
    QVector<QVector<int>> faces = {
        {0, 1, 2, 3}, // 前
        {5, 4, 7, 6}, // 后
        {4, 0, 3, 7}, // 左
        {1, 5, 6, 2}, // 右
        {3, 2, 6, 7}, // 上
        {4, 5, 1, 0}  // 下
    };

    // 定义每个面的颜色
    QVector<QColor> faceColors = {
        QColor(255, 0, 0, 200),     // 前 - 红色
        QColor(0, 255, 0, 200),     // 后 - 绿色
        QColor(0, 0, 255, 200),     // 左 - 蓝色
        QColor(255, 255, 0, 200),   // 右 - 黄色
        QColor(255, 0, 255, 200),   // 上 - 洋红色
        QColor(0, 255, 255, 200)    // 下 - 青色
    };

    // 绘制每个面
    for (int i = 0; i < faces.size(); i++) {
        if (i == 1 || i == 3 || i == 4)
        {
            const auto& face = faces[i];

            QPolygonF polygon;
            for (int j = 0; j < 4; j++) {
                polygon << projectPoint(m_vertices[face[j]]);
            }

            // 填充面
            painter->setBrush(faceColors[i]);
            painter->setPen(QPen(Qt::black, 2));
            painter->drawPolygon(polygon);
        }
    }
}

QPointF CubeItem::projectPoint(const QVector3D& point) const
{
    // 等轴测投影
    float isoX = point.x() * 0.866f - point.z() * 0.866f;
    float isoY = point.y() - point.x() * 0.5f - point.z() * 0.5f;
    return QPointF(isoX, -isoY); // 翻转Y轴使向上为正
}