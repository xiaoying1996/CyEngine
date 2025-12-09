#pragma once

#include <QtWidgets/QMainWindow>
#include <QAction>
#include <QKeySequence>
#include "GraphicsViewExample.h"
#include "ui_CyMapEditer.h"

class CyMapEditer : public QMainWindow
{
    Q_OBJECT

public:
    CyMapEditer(QWidget *parent = nullptr);
    ~CyMapEditer();

public slots:
    void on_NewMapBtn_clicked();

    void slot_Save();

private:
    Ui::CyMapEditerClass ui;
    GraphicsViewExample *_GraphicsViewExample = nullptr;  
    QGraphicsScene* scene = nullptr;
    QAction* _saveAction = nullptr;
    CubeItem* m_cube = nullptr;
};

