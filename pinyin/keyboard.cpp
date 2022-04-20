#include "keyboard.h"
#include "ui_keyboard.h"

KeyBoard::KeyBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint | Qt::Tool | Qt::WindowDoesNotAcceptFocus);

    //拼音最大长度
    ui->lineEdit_textinput->setMaxLength(20);

    m_input = new Input(this);
    if(!m_input->init()){
        qDebug()<<"字典加载失败，请将dict文件移至工作目录";
    }

    /* 设置为列表显示模式 */
    ui->listWidget->setViewMode(QListView::ListMode);
    /* 从左往右排列 */
    ui->listWidget->setFlow(QListView::LeftToRight);
    /* 屏蔽水平滑动条 */
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    /* 屏蔽垂直滑动条 */
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    /* 设置为像素滚动 */
    ui->listWidget->setHorizontalScrollMode(QListWidget::ScrollPerPixel);
    /* 设置鼠标左键拖动 */
    QScroller::grabGesture(ui->listWidget, QScroller::LeftMouseButtonGesture);

    //删除按钮图标
    ui->pushButton_back->setIcon(style()->standardIcon(QStyle::SP_DialogDiscardButton));
    //空格图标
    //ui->pushButton_space->setIcon(style()->standardIcon());

    qss = "QPushButton{"
          "font: 16pt 黑体;"
          "font-size: 26px;"
          "color: white;"
          "margin: 2px;"
          "border-radius: 5px;"
          "background: #00C78C;}"
          ""
          "QPushButton:pressed{"
          "background: #F0FFFF ;}"
          ""
          "QListWidget::Item:hover { background: #00C78C; color: white; }"
          "QListWidget { font: 16pt 黑体; outline: none; border:1px solid #00000000; color: black; }"
          "QLineEdit {font: 16pt 黑体; outline: none; border:1px solid #00000000; color: black;}";


    this->setStyleSheet(qss);

    keyBtnList.append(ui->pushButton_q);
    keyBtnList.append(ui->pushButton_w);
    keyBtnList.append(ui->pushButton_e);
    keyBtnList.append(ui->pushButton_r);
    keyBtnList.append(ui->pushButton_t);
    keyBtnList.append(ui->pushButton_y);
    keyBtnList.append(ui->pushButton_u);
    keyBtnList.append(ui->pushButton_i);
    keyBtnList.append(ui->pushButton_o);
    keyBtnList.append(ui->pushButton_p);
    keyBtnList.append(ui->pushButton_a);
    keyBtnList.append(ui->pushButton_s);
    keyBtnList.append(ui->pushButton_d);
    keyBtnList.append(ui->pushButton_f);
    keyBtnList.append(ui->pushButton_g);
    keyBtnList.append(ui->pushButton_h);
    keyBtnList.append(ui->pushButton_j);
    keyBtnList.append(ui->pushButton_k);
    keyBtnList.append(ui->pushButton_l);
    keyBtnList.append(ui->pushButton_z);
    keyBtnList.append(ui->pushButton_x);
    keyBtnList.append(ui->pushButton_c);
    keyBtnList.append(ui->pushButton_v);
    keyBtnList.append(ui->pushButton_b);
    keyBtnList.append(ui->pushButton_n);
    keyBtnList.append(ui->pushButton_m);
    keyBtnList.append(ui->pushButton_back);
    keyBtnList.append(ui->pushButton_space);


    btnvalueList_small<<"q"<<"w"<<"e"<<"r"<<"t"<<"y"<<"u"<<"i"<<"o"<<"p"<<"a"<<"s"<<"d"<<"f"<<"g"
                   <<"h"<<"j"<<"k"<<"l"<<"z"<<"x"<<"c"<<"v"<<"b"<<"n"<<"m"<<""<<" ";
    btnvalueList_large<<"Q"<<"W"<<"E"<<"R"<<"T"<<"Y"<<"U"<<"I"<<"O"<<"P"<<"A"<<"S"<<"D"<<"F"<<"G"
                    <<"H"<<"J"<<"K"<<"L"<<"Z"<<"X"<<"C"<<"V"<<"B"<<"N"<<"M"<<""<<" ";
    btnvalueList_mark<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"0"<<"!"<<"@"<<"#"<<"%"<<"&&"
                    <<"*"<<"("<<")"<<"-"<<"_"<<":"<<";"<<"/"<<"."<<","<<"?"<<""<<" ";

    keyList_low.append(Qt::Key_Q);keyList_low.append(Qt::Key_W);keyList_low.append(Qt::Key_E);
    keyList_low.append(Qt::Key_R);keyList_low.append(Qt::Key_T);keyList_low.append(Qt::Key_Y);
    keyList_low.append(Qt::Key_U);keyList_low.append(Qt::Key_I);keyList_low.append(Qt::Key_O);
    keyList_low.append(Qt::Key_P);
    keyList_low.append(Qt::Key_A);keyList_low.append(Qt::Key_S);keyList_low.append(Qt::Key_D);
    keyList_low.append(Qt::Key_F);keyList_low.append(Qt::Key_G);keyList_low.append(Qt::Key_H);
    keyList_low.append(Qt::Key_J);keyList_low.append(Qt::Key_K);keyList_low.append(Qt::Key_L);
    keyList_low.append(Qt::Key_Z);keyList_low.append(Qt::Key_X);keyList_low.append(Qt::Key_C);
    keyList_low.append(Qt::Key_V);keyList_low.append(Qt::Key_B);keyList_low.append(Qt::Key_N);
    keyList_low.append(Qt::Key_M);keyList_low.append(Qt::Key_Backspace);keyList_low.append(Qt::Key_Space);

    keyList_mark.append(Qt::Key_1);keyList_mark.append(Qt::Key_2);keyList_mark.append(Qt::Key_3);
    keyList_mark.append(Qt::Key_4);keyList_mark.append(Qt::Key_5);keyList_mark.append(Qt::Key_6);
    keyList_mark.append(Qt::Key_7);keyList_mark.append(Qt::Key_8);keyList_mark.append(Qt::Key_9);
    keyList_mark.append(Qt::Key_0);
    keyList_mark.append(Qt::Key_Exclam);keyList_mark.append(Qt::Key_At);keyList_mark.append(Qt::Key_NumberSign);
    keyList_mark.append(Qt::Key_Percent);keyList_mark.append(Qt::Key_Ampersand);keyList_mark.append(Qt::Key_Asterisk);
    keyList_mark.append(Qt::Key_ParenLeft);keyList_mark.append(Qt::Key_ParenRight);keyList_mark.append(Qt::Key_Minus);
    keyList_mark.append(Qt::Key_Underscore);keyList_mark.append(Qt::Key_Colon);keyList_mark.append(Qt::Key_Semicolon);
    keyList_mark.append(Qt::Key_Slash);keyList_mark.append(Qt::Key_Period);keyList_mark.append(Qt::Key_Comma);
    keyList_mark.append(Qt::Key_Question);keyList_mark.append(Qt::Key_Backspace);keyList_mark.append(Qt::Key_Space);

    //大小写切换
    connect(ui->pushButton_shift,&QPushButton::clicked,[=]{
        QString text = ui->pushButton_shift->text();
        if(text == "大写")
            switchState(Type_high);
        else
            switchState(Type_Low);
    });
    //中英文切换
    connect(ui->pushButton_en,&QPushButton::clicked,[=]{
        QString text = ui->pushButton_en->text();
        if(text == "En")
            switchState(Type_chinese);
        else
            switchState(Type_Low);
    });
    //字符数字切换
    connect(ui->pushButton_123,&QPushButton::clicked,[=]{
        QString text = ui->pushButton_123->text();
        if(text == "abc")
            switchState(Type_Low);
        else
            switchState(Type_mark);
    });
    //隐藏
    connect(ui->pushButton_hide,&QPushButton::clicked,[=]{this->hide();});
    //按钮绑定槽函数
    for(KeyButton * btn : keyBtnList){
        connect(btn,&KeyButton::key_pressed,this,&KeyBoard::slot_key_keyEvent);
    }
    //不可选中
    connect(ui->lineEdit_textinput,&QLineEdit::selectionChanged,[=]{ui->lineEdit_textinput->deselect();});

    //中文输入
    connect(ui->lineEdit_textinput,&QLineEdit::textChanged,[=](const QString &text){
        /* 单个字符过长引发崩溃
         * 处理：单个字符限制长度为10
         */
        if(text.isEmpty()){
            return ;
        }

        if(text.length() >= 10){
            if(issingleChar(text)){
                QString deal_text = text.mid(0,10);
                getCandidateList(deal_text);
                return ;
            }
            getCandidateList(text);
            return ;
        }
        else {
            getCandidateList(text);
        }
    });

}

KeyBoard::~KeyBoard()
{
    delete ui;
}

bool KeyBoard::issingleChar(QString spell)
{
    bool ret = true;
    for( auto s : spell){
        if(s != spell[0]){
            ret = false;
            break;
        }
    }
    return ret;
}

void KeyBoard::showEvent(QShowEvent * event)
{
    m_type = Type_high;
    switchState(Type_Low);
    event->accept();
}

void KeyBoard::setEdit(QWidget *edit)
{
    this->edit = edit;
}

void KeyBoard::slot_key_keyEvent(int key,QString value)
{
    qDebug()<<"KeyButton:"<<key<<value;

    if(m_type == Type_chinese){
        ui->lineEdit_textinput->insert(value);

        if(key == Qt::Key_Backspace){
            if(ui->lineEdit_textinput->text().isEmpty()){
                ui->listWidget->clear();
                QKeyEvent keyPress(QEvent::KeyPress, key, Qt::NoModifier, value);
                QApplication::sendEvent(edit, &keyPress);
            }
            else {
                ui->lineEdit_textinput->backspace();
            }
        }
        return;
    }

    //&&->&
    if(value == "&&")
        value = "&";

    QKeyEvent keyPress(QEvent::KeyPress, key, Qt::NoModifier, value);

    QApplication::sendEvent(edit, &keyPress);
}


void KeyBoard::getCandidateList(const QString spell)
{
    unsigned int cand = m_input->search(spell);
    if(cand == 0){
        return;
    }

    QStringList ret = m_input->get_candidate(cand);
    if(ret.isEmpty()){
        return;
    }

    ui->listWidget->clear();
    ui->listWidget->addItems(ret);
}

void KeyBoard::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier, item->text());
    QApplication::sendEvent(edit, &keyPress);

    ui->listWidget->clear();
    ui->lineEdit_textinput->clear();
    /*获取字符串匹配位置，不太准确*/
    //qDebug()<<"cur_search_pos:"<<m_input->cur_search_pos();
    //ui->lineEdit_textinput->setText(ui->lineEdit_textinput->text().remove(0,m_input->cur_search_pos()));
}

//切换状态
void KeyBoard::switchState(TYPE type)
{
    switch (type) {
    case Type_Low:/*小写英文*/
        for(int i=0;i<keyBtnList.count();i++){
            keyBtnList.at(i)->setValue(btnvalueList_small.at(i));
            keyBtnList.at(i)->setKey(keyList_low.at(i));
            m_type = Type_Low;
        }
        ui->pushButton_shift->setText("大写");
        ui->pushButton_123->setText("?123");
        ui->pushButton_en->setText("En");
        ui->widget_chinese->hide();
        break;
    case Type_high:/*大写英文*/
        if(m_type == Type_mark)
            return;
        if(m_type == Type_chinese)
            return;
        for(int i=0;i<keyBtnList.count();i++){
            keyBtnList.at(i)->setValue(btnvalueList_large.at(i));
            keyBtnList.at(i)->setKey(keyList_low.at(i));
            m_type = Type_Low;
        }
        ui->pushButton_shift->setText("小写");
        ui->pushButton_123->setText("?123");
        ui->pushButton_en->setText("En");
        ui->widget_chinese->hide();
        break;
    case Type_mark:/*数字字符*/
        for(int i=0;i<keyBtnList.count();i++){
            keyBtnList.at(i)->setValue(btnvalueList_mark.at(i));
            keyBtnList.at(i)->setKey(keyList_mark.at(i));
            m_type = Type_mark;
        }
        ui->pushButton_shift->setText("小写");
        ui->pushButton_123->setText("abc");
        ui->pushButton_en->setText("En");
        ui->widget_chinese->hide();
        break;
    case Type_chinese:/*中文输入*/
        if(m_type == Type_mark)
            return;
        for(int i=0;i<keyBtnList.count();i++){
            keyBtnList.at(i)->setValue(btnvalueList_small.at(i));
            keyBtnList.at(i)->setKey(keyList_low.at(i));
            m_type = Type_Low;
        }
        ui->pushButton_shift->setText("小写");
        ui->pushButton_123->setText("?123");
        ui->pushButton_en->setText("中");
        ui->widget_chinese->show();
        ui->lineEdit_textinput->clear();
        ui->listWidget->clear();
        break;
    }

    m_type = type;
    return;
}
