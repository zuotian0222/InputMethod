#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFile>


#include "atomdictbase.h"
#include "dictbuilder.h"
#include "dictdef.h"
#include "dictlist.h"
#include "dicttrie.h"
#include "lpicache.h"
#include "matrixsearch.h"
#include "mystdlib.h"
#include "ngram.h"
#include "pinyinime.h"
#include "searchutility.h"
#include "spellingtable.h"
#include "spellingtrie.h"
#include "splparser.h"
#include "sync.h"
#include "userdict.h"
#include "utf16char.h"
#include "utf16reader.h"

using namespace ime_pinyin;

class Input : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool m_able READ getEnable WRITE setEnable NOTIFY signal_input_able)

public:
    explicit Input(QObject *parent = nullptr);
    ~Input();

    bool init(int max_spell_len = 64,int max_out_len = 64);
    void deinit();

    unsigned int search(const QString spell);
    unsigned int del_search(unsigned pos);

    int cur_search_pos();

    void reset_search();

    bool getEnable();
    void setEnable(bool able);

    QStringList get_candidate(unsigned int cnadnum);

signals:
    void signal_input_able(bool);

private:

    bool m_able = false;

    int m_spell_len;
    int m_out_len;

    const QString dict_path = "dict_pinyin.dat";
    const QString dict_user_path = "dict_pinyin_user.dat";

};

#endif // INPUT_H
