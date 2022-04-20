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

    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;

    QTimer * timer;

    KeyBoard * keyboard;

    static bool isConsoleable;
};
#endif // WIDGET_H
