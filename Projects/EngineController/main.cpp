#include "../header/EngineController.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EngineController w;
    w.show();
    return a.exec();
}
