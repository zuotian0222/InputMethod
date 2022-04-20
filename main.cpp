/*
 * The library is needed by function SendMessageA()
 * This code is sometimes necessary, sometimes not
 */
#pragma comment(lib, "User32.lib")

#include "widget.h"
#include <Windows.h>
#include <QDebug>

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

    MessageBox(nullptr, L"Hello World!!!", L"这是第一个Windows程序", MB_OK);


    return a.exec();
}

