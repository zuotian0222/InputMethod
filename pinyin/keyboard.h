#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QDebug>
#include <QShowEvent>
#include <QKeyEvent>
#include <QScroller>
#include <QListWidgetItem>

#include "keybutton.h"
#include "input.h"


namespace Ui {
class KeyBoard;
}

class KeyBoard : public QWidget
{
    Q_OBJECT

    enum TYPE{
        Type_Low = 1,
        Type_high,
        Type_mark,
        Type_chinese
    };

public:
    explicit KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard();

    void setEdit(QWidget * edit);

protected:
    //切换状态
    void switchState(TYPE type);
    //获取字符匹配的中文字符组
    void getCandidateList(const QString spell);

    bool issingleChar(QString spell);

protected slots:
    //重写显示函数，显示时回归初始状态
    void showEvent(QShowEvent *event);
    //发送键盘事件
    void slot_key_keyEvent(int key,QString value);

    //void slot_edit_changed(QString spell);

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::KeyBoard *ui;

    TYPE m_type;

    Input * m_input;

    QWidget * edit;

    QList<KeyButton*> keyBtnList;

    QStringList btnvalueList_small;
    QStringList btnvalueList_large;
    QStringList btnvalueList_mark;

    QString qss;

    QList<Qt::Key> keyList_low;
    QList<Qt::Key> keyList_mark;
};

#endif // KEYBOARD_H
