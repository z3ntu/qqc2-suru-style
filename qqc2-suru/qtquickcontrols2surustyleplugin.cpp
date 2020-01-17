/****************************************************************************
**
** Copyright (C) 2017, 2018 Stefano Verzegnassi <stefano@ubports.com>
** Copyright (C) 2017 The Qt Company Ltd.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
****************************************************************************/

#include <QtQuickControls2/private/qquickstyleplugin_p.h>

#include "qquicksurustyle_p.h"
#include "qquicksurutheme_p.h"
#include "qquicksuruanimations.h"
#include "qquicksuruunits.h"

#include <QQmlEngine>

class QtQuickControls2SuruStylePlugin: public QQuickStylePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    QtQuickControls2SuruStylePlugin(QObject *parent = nullptr);

    void registerTypes(const char *uri) override;

    QString name() const override;
    void initializeTheme(QQuickTheme *theme) override;
};

QtQuickControls2SuruStylePlugin::QtQuickControls2SuruStylePlugin(QObject *parent) : QQuickStylePlugin(parent)
{
}

void QtQuickControls2SuruStylePlugin::registerTypes(const char *uri)
{
    qmlRegisterModule(uri, 2, 2);
    qmlRegisterUncreatableType<QQuickSuruStyle>(uri, 2, 2, "Suru", tr("Suru is an attached property"));

    qmlRegisterModule(uri, 2, 2);

    qmlRegisterType<QQuickSuruAnimations>();
    qmlRegisterType<QQuickSuruUnits>();
    qmlRegisterType(resolvedUrl(QStringLiteral("CheckIndicator.qml")), uri, 2, 0, "CheckIndicator");
    qmlRegisterType(resolvedUrl(QStringLiteral("CursorDelegate.qml")), uri, 2, 0, "CursorDelegate");
    qmlRegisterType(resolvedUrl(QStringLiteral("ElevationEffect.qml")), uri, 2, 0, "ElevationEffect");
    qmlRegisterType(resolvedUrl(QStringLiteral("HighlightFocusRectangle.qml")), uri, 2, 0, "HighlightFocusRectangle");
    qmlRegisterType(resolvedUrl(QStringLiteral("Label.qml")), uri, 2, 0, "Label");
    qmlRegisterType(resolvedUrl(QStringLiteral("RadioIndicator.qml")), uri, 2, 0, "RadioIndicator");
    qmlRegisterType(resolvedUrl(QStringLiteral("SwitchIndicator.qml")), uri, 2, 0, "SwitchIndicator");

}

QString QtQuickControls2SuruStylePlugin::name() const
{
    return QStringLiteral("suru");
}

void QtQuickControls2SuruStylePlugin::initializeTheme(QQuickTheme *theme)
{
    QQuickSuruTheme::initialize(theme);
}

#include "qtquickcontrols2surustyleplugin.moc"
