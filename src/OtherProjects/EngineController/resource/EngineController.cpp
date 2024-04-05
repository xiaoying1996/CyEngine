#include "../header/EngineController.h"

EngineController::EngineController(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    engine = MyEngine::GetInstance();
    ErrorState err = engine->Init(1, 10);
}
