#ifndef HTMLVIEWER_GLOBAL_H
#define HTMLVIEWER_GLOBAL_H

#include <QtGlobal>

#if defined(HTMLVIEWER_LIBRARY)
#  define HTMLVIEWERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HTMLVIEWERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HTMLVIEWER_GLOBAL_H

