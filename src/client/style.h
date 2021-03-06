/*
 * Copyright 2013 Giulio Camuffo <giuliocamuffo@gmail.com>
 *
 * This file is part of Orbital
 *
 * Orbital is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Orbital is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Orbital.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STYLE_H
#define STYLE_H

#include <QObject>
#include <QMap>
#include <QColor>

class QQmlComponent;
class QQmlEngine;

class StyleInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString prettyName READ prettyName CONSTANT)
public:
    StyleInfo() {}

    QString prettyName() const { return m_prettyName; }
    QString name() const { return m_name; }

private:
    QString m_prettyName;
    QString m_name;
    QString m_path;
    QString m_qml;

    friend class Style;
};

#define PROPERTY(type, name) \
    type name() const { return m_##name; } \
    void set_##name(type c) { m_##name = c; emit name##Changed(); } \
    private: \
        type m_##name; \
    public:

class Style : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlComponent *panelBackground READ panelBackground WRITE set_panelBackground NOTIFY panelBackgroundChanged)
    Q_PROPERTY(QQmlComponent *panelBorder READ panelBorder WRITE set_panelBorder NOTIFY panelBorderChanged)
    Q_PROPERTY(QQmlComponent *taskBarBackground READ taskBarBackground WRITE set_taskBarBackground NOTIFY taskBarBackgroundChanged)
    Q_PROPERTY(QQmlComponent *taskBarItem READ taskBarItem WRITE set_taskBarItem NOTIFY taskBarItemChanged)

    Q_PROPERTY(QQmlComponent *pagerBackground READ pagerBackground WRITE set_pagerBackground NOTIFY pagerBackgroundChanged)
    Q_PROPERTY(QQmlComponent *pagerWorkspace READ pagerWorkspace WRITE set_pagerWorkspace NOTIFY pagerWorkspaceChanged)

    Q_PROPERTY(QQmlComponent *toolTipBackground READ toolTipBackground WRITE set_toolTipBackground NOTIFY toolTipBackgroundChanged)

    Q_PROPERTY(QQmlComponent *button READ button WRITE set_button NOTIFY buttonChanged)

    Q_PROPERTY(QQmlComponent *popup READ popup WRITE set_popup NOTIFY popupChanged)
    Q_PROPERTY(QQmlComponent *popupLauncher READ popupLauncher WRITE set_popupLauncher NOTIFY popupLauncherChanged)

    Q_PROPERTY(QQmlComponent *notificationBackground READ notificationBackground WRITE set_notificationBackground NOTIFY notificationBackgroundChanged)

    Q_PROPERTY(QColor textColor READ textColor WRITE set_textColor NOTIFY textColorChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE set_backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor highlightColor READ highlightColor WRITE set_highlightColor NOTIFY highlightColorChanged)
public:
    Style(QObject *p = nullptr);

    PROPERTY(QQmlComponent *, panelBackground)
    PROPERTY(QQmlComponent *, panelBorder)
    PROPERTY(QQmlComponent *, taskBarBackground)
    PROPERTY(QQmlComponent *, taskBarItem)
    PROPERTY(QQmlComponent *, pagerBackground)
    PROPERTY(QQmlComponent *, pagerWorkspace)
    PROPERTY(QQmlComponent *, toolTipBackground)
    PROPERTY(QQmlComponent *, button)
    PROPERTY(QQmlComponent *, popup)
    PROPERTY(QQmlComponent *, popupLauncher)
    PROPERTY(QQmlComponent *, notificationBackground)
    PROPERTY(QColor, textColor)
    PROPERTY(QColor, backgroundColor)
    PROPERTY(QColor, highlightColor)

    static Style *loadStyle(const QString &name, QQmlEngine *engine);

    static void loadStylesList();
    static void cleanupStylesList();
    static QMap<QString, StyleInfo *> stylesInfo() { return s_styles; }

signals:
    void panelBackgroundChanged();
    void panelBorderChanged();
    void taskBarBackgroundChanged();
    void taskBarItemChanged();
    void pagerBackgroundChanged();
    void pagerWorkspaceChanged();
    void toolTipBackgroundChanged();
    void buttonChanged();
    void popupChanged();
    void popupLauncherChanged();
    void notificationBackgroundChanged();
    void textColorChanged();
    void backgroundColorChanged();
    void highlightColorChanged();

private:
    static void loadStyleInfo(const QString &name, const QString &path);

    static QMap<QString, StyleInfo *> s_styles;
};

#undef PROPERTY

#endif
