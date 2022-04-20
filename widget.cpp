#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    keyboard = new KeyBoard();
    keyboard->resize(600,300);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
}

Widget::~Widget()
{
    delete keyboard;
    delete ui;
}

bool Widget::eventFilter(QObject *w, QEvent *e)
{
    if(w->inherits("QLineEdit") && e->type() == QEvent::MouseButtonRelease){
        QWidget * p = qobject_cast<QWidget *>(w);
        keyboard->setEdit(p);
        QPoint posA = p->mapToGlobal(QPoint(0, 0));
        keyboard->move(posA.x(),posA.y()+p->height());
        keyboard->show();
    }
    return QWidget::eventFilter(w,e);
}

