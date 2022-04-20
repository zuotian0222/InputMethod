
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font;
    font.setFamily("黑体");
    font.setPixelSize(16);
    a.setFont(font);

    Widget w;
    w.show();
    return a.exec();
}

