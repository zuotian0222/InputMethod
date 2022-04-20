#include "input.h"

Input::Input(QObject *parent ) : QObject(parent)
{

}

Input::~Input()
{

}

bool Input::getEnable()
{
    return m_able;
}
void Input::setEnable(bool able)
{
    m_able = able;
    im_flush_cache();
    emit signal_input_able(able);
}

bool Input::init(int max_spell_len, int max_out_len)
{
    QString path = QDir::currentPath();
    qDebug()<<path;

    QFile file_pinyin(dict_path);
    if(!file_pinyin.exists()){
        QFile::copy(":/dict/dict_pinyin.dat", path+"/"+dict_path);
        QFile::setPermissions(path,QFileDevice::ReadOther|QFileDevice::WriteOther);
    }
    QFile file_user(dict_user_path);
    if(!file_user.exists()){
        QFile::copy(":/dict/dict_pinyin_user.dat",path+"/"+dict_user_path);
        QFile::setPermissions(path,QFileDevice::ReadOther|QFileDevice::WriteOther);
    }

    m_spell_len = max_spell_len;
    m_out_len = max_out_len;

    bool ret = im_open_decoder(QString("%1/"+dict_path).arg(path).toLocal8Bit().data(),
                               QString("%1/"+dict_user_path).arg(path).toLocal8Bit().data());
    if(!ret)
        return ret;

    im_set_max_lens(static_cast<size_t>(m_spell_len),static_cast<size_t>(m_out_len));
    reset_search();

    m_able = ret;
    return ret;
}
void Input::deinit()
{
    im_close_decoder();
}

void Input::reset_search()
{
    if(m_able)
        im_reset_search();
}

unsigned int Input::search(const QString spell)
{
    if (!m_able)
        return 0;
    QByteArray bytearray;
    char    *pinyin;

    bytearray = spell.toUtf8();
    pinyin = bytearray.data();

    size_t candnum = im_search(pinyin, static_cast<size_t>(bytearray.size()));

    if(static_cast<int>(candnum) < m_out_len){
        return static_cast<unsigned int>(candnum);
    }
    return static_cast<unsigned int>(m_out_len);
}

int Input::cur_search_pos()
{
    const uint16 *start_pos;
    size_t  pos_len;
    pos_len = im_get_spl_start_pos(start_pos);
    return static_cast<int>(pos_len);
}


QStringList Input::get_candidate(unsigned int candnum)
{   
    QStringList textList;
    if(candnum == 0)
        return textList;

    char16 * cand_buf = new char16[m_out_len];
    for (unsigned int i = 0; i < candnum; i++) {
        char16 *cand;
        cand = im_get_candidate(i, cand_buf, static_cast<unsigned int>(m_out_len));
        if(cand){
            textList.append(QString::fromUtf16(cand));
        }
        else {
            continue;
        }
    }
    delete[] cand_buf;
    //qDebug()<<textList;
    return textList;
}


