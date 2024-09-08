#include "MyEngineClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyEngineClient w;
    w.show();
    return a.exec();
}
