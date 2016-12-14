#ifndef TRANSIT_GLOBAL_H
#define TRANSIT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TRANSIT_LIBRARY)
#  define TRANSITSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TRANSITSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TRANSIT_GLOBAL_H
