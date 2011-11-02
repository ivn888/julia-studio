/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef QMLJSFUNCTIONFILTER_H
#define QMLJSFUNCTIONFILTER_H

#include <locator/ilocatorfilter.h>

namespace QmlJSTools {
namespace Internal {

class LocatorData;

class FunctionFilter : public Locator::ILocatorFilter
{
    Q_OBJECT
public:
    explicit FunctionFilter(LocatorData *data, QObject *parent = 0);
    ~FunctionFilter();

    QString displayName() const { return tr("Methods and functions"); }
    QString id() const { return QLatin1String("Functions"); }
    Priority priority() const { return Medium; }
    QList<Locator::FilterEntry> matchesFor(QFutureInterface<Locator::FilterEntry> &future, const QString &entry);
    void accept(Locator::FilterEntry selection) const;
    void refresh(QFutureInterface<void> &future);

private:
    LocatorData *m_data;
};

} // namespace Internal
} // namespace QmlJSTools

#endif // QMLJSFUNCTIONFILTER_H
