#pragma once

#include <QMainWindow>
#include "ui_MoveMissionWidget.h"
#include "Engine/MyEngine.h"
#include <QString>
#include <QTimer>

class MoveMissionWidget : public QMainWindow
{
	Q_OBJECT

public:
	MoveMissionWidget(QWidget *parent = nullptr);
	~MoveMissionWidget();
	void SetExecuter();

public slots:
	void on_SendBtn_clicked();
	void onHumanComboxSelect(int index);
	void onUavComboxSelect(int index);
	void timeout();

private:
	Ui::MoveMissionWidgetClass ui;
	std::vector<Model_BasicInfo> models;
	string choosedModelName;
	QTimer* timer = nullptr;
};
