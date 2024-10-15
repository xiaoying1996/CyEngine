#pragma once

#include <QMainWindow>
#include <QScrollArea>
#include <QTimer>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QButtonGroup>
#include <QBitMap>
#include "ui_PicPlayer.h"

class PicPlayer : public QMainWindow
{
	Q_OBJECT

public:
	PicPlayer(QWidget *parent = nullptr);
	~PicPlayer();

    void setImageList(QStringList imageFileNameList);
    void addImage(QString imageFileName);
    void startPlay();
    void stopPlay();
    void startPlayAgain();

private:
    void initChangeImageButton();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

public slots:
    void onImageChangeTimeout();
    void onImageSwitchButtonClicked(int buttonId);

private:
	Ui::PicPlayerClass ui;
    QScrollArea* m_imagePlayWidget;
    QList<QString> m_imageFileNameList;
    QTimer m_imageChangeTimer;
    int m_currentDrawImageIndx;
    QPixmap m_currentPixmap;
    QPixmap m_nextPixmap;
    QPropertyAnimation* m_opacityAnimation;
    QList<QPushButton*> m_pButtonChangeImageList;
};
