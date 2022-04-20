INCLUDEPATH += $$PWD/googlepinyin

HEADERS += \
        $$PWD/googlepinyin/atomdictbase.h \
        $$PWD/googlepinyin/dictbuilder.h \
        $$PWD/googlepinyin/dictdef.h \
        $$PWD/googlepinyin/dictlist.h \
        $$PWD/googlepinyin/dicttrie.h \
        $$PWD/googlepinyin/lpicache.h \
        $$PWD/googlepinyin/matrixsearch.h \
        $$PWD/googlepinyin/mystdlib.h \
        $$PWD/googlepinyin/ngram.h \
        $$PWD/googlepinyin/pinyinime.h \
        $$PWD/googlepinyin/searchutility.h \
        $$PWD/googlepinyin/spellingtable.h \
        $$PWD/googlepinyin/spellingtrie.h \
        $$PWD/googlepinyin/splparser.h \
        $$PWD/googlepinyin/sync.h \
        $$PWD/googlepinyin/userdict.h \
        $$PWD/googlepinyin/utf16char.h \
        $$PWD/googlepinyin/utf16reader.h \
        $$PWD/input.h \
        $$PWD/keyboard.h \
        $$PWD/keybutton.h

SOURCES += \
        $$PWD/googlepinyin/dictbuilder.cpp \
        $$PWD/googlepinyin/dictlist.cpp \
        $$PWD/googlepinyin/dicttrie.cpp \
        $$PWD/googlepinyin/lpicache.cpp \
        $$PWD/googlepinyin/matrixsearch.cpp \
        $$PWD/googlepinyin/mystdlib.cpp \
        $$PWD/googlepinyin/ngram.cpp \
        $$PWD/googlepinyin/pinyinime.cpp \
        $$PWD/googlepinyin/searchutility.cpp \
        $$PWD/googlepinyin/spellingtable.cpp \
        $$PWD/googlepinyin/spellingtrie.cpp \
        $$PWD/googlepinyin/splparser.cpp \
        $$PWD/googlepinyin/sync.cpp \
        $$PWD/googlepinyin/userdict.cpp \
        $$PWD/googlepinyin/utf16char.cpp \
        $$PWD/googlepinyin/utf16reader.cpp \
        $$PWD/input.cpp \
        $$PWD/keyboard.cpp \
        $$PWD/keybutton.cpp

SUBDIRS += \
        $$PWD/googlepinyin/googlepinyin.pro

FORMS += \
        $$PWD/keyboard.ui

RESOURCES += \
        $$PWD/dict.qrc
