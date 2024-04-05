#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EngineController.h"
#include "../../../Engine/MyEngine.h"

class EngineController : public QMainWindow
{
    Q_OBJECT

public:
    EngineController(QWidget *parent = Q_NULLPTR);

private:
    Ui::EngineControllerClass ui;
    MyEngine *engine = nullptr;
};
