#include "keybutton.h"

KeyButton::KeyButton(QWidget *parent) : QPushButton(parent)
{
    /*支持长按*/
    this->setAutoRepeat(true);
    this->setAutoRepeatDelay(500);
    this->setAutoRepeatInterval(100);

    connect(this,&QPushButton::pressed,this,&KeyButton::slot_onPressed);
}

void KeyButton::setValue(QString value)
{
    this->value = value;
    this->setText(value);
}

void KeyButton::setKey(int key)
{
    this->key = key;
}

void KeyButton::slot_onPressed()
{
    emit key_pressed(key,value);
}
