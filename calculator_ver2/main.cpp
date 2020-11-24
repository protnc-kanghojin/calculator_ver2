#include "calculator_ver2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculator_ver2 w;
    w.show();
    return a.exec();
}
