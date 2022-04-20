#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTimer>

#include <QDebug>
#include <Windows.h>
#include <iostream>
#include <QMutex>
#include <QDateTime>

#include "keyboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    bool eventFilter(QObject * w,QEvent *e);

private:
    Ui::Widget *ui;

    KeyBoard * keyboard;
};
#endif // WIDGET_H
