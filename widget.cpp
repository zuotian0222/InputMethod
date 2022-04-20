#include "widget.h"
#include "ui_widget.h"

bool Widget::isConsoleable = false;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    keyboard = new KeyBoard();
    keyboard->resize(600,300);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=]{qDebug()<<"test.....";});
    timer->start(100);
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


void Widget::on_pushButton_clicked()
{
    QString qss;
    qss = "QMessageBox QPushButton{"
          "border: 1px solid #298DFF;"
          "border-radius: 3px;"
          "background-color: #F2F2F2;"
          "color: #298DFF;"
          "width:80px;"
          "height:35px;}"
          ""
          "QMessageBox QLabel#qt_msgbox_label{"

          "min-height:80px;}"
          ""
          "QMessageBox QLabel#qt_msgboxex_icon_label{"
          "min-width:80px;"
          "min-height:80px;"
          "qproperty-scaledContents:true;}";

    this->setStyleSheet(qss);

    QMessageBox::information(this,"提示","测试框。。。。。",QMessageBox::No,QMessageBox::Yes);
}

void Widget::on_pushButton_2_clicked()
{
    AllocConsole();
    SetConsoleTitleA("Debug output window");

    FILE *pf;
    freopen_s(&pf,"CONOUT$", "w+t", stdout);

    isConsoleable = true;
    qInstallMessageHandler(messageHandler);
}


void Widget::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();
    QString msgtype;
    if(type == QtDebugMsg){
        msgtype = QString("Debug:");
    }
    if(type == QtInfoMsg){
        msgtype = QString("Info:");
    }
    if(type == QtWarningMsg){
        msgtype = QString("Warning:");
    }
    if(type == QtCriticalMsg){
        msgtype = QString("Critical:");
    }
    if(type == QtFatalMsg){
        msgtype = QString("Fatal:");
    }
    // 设置输出信息格式
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString message = QString("%1 %2 %3 %4\n").arg(msgtype).arg(" ").arg(msg).arg(datetime);

    if(isConsoleable)
        std::cout<<message.toStdString().c_str();

    // 解锁
    mutex.unlock();
    return;
}
