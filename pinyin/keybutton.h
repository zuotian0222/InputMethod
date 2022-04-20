#ifndef KEYBUTTON_H
#define KEYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class KeyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit KeyButton(QWidget *parent = nullptr);

    void setValue(QString value);

    void setKey(int key);

signals:
    void key_pressed(int key,QString value);

protected:
    void slot_onPressed();

private:
    int key;
    QString value;
};

#endif // KEYBUTTON_H
