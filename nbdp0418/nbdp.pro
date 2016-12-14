include(nbdp.pri)

TEMPLATE  = subdirs
CONFIG   += ordered

SUBDIRS =  logging \
    transit \
    control \
     src \
     myCom

TRANSLATIONS = src/resources/translations/nbdp_en.ts \
               src/resources/translations/nbdp_ja.ts \
               src/resources/translations/nbdp_zh.ts \
               src/resources/translations/nbdp_zh_CN.ts

DISTFILES += nbdp.astylerc
