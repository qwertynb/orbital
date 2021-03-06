/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp org.freedesktop.Notifications.xml -a notificationsadaptor -c NotificationsAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "notificationsadaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QImage>

#include "notificationsservice.h"

struct DBusImageStruct {
    int width;
    int height;
    int rowstride;
    bool hasAlpha;
    int bps;
    int channels;
    QByteArray data;
};

QDBusArgument &operator<<(QDBusArgument &argument, const DBusImageStruct &v)
{
    argument.beginStructure();
    argument << v.width << v.height << v.rowstride << v.hasAlpha << v.bps << v.channels << v.data;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, DBusImageStruct &v)
{
    argument.beginStructure();
    argument >> v.width >> v.height >> v.rowstride >> v.hasAlpha >> v.bps >> v.channels >> v.data;
    argument.endStructure();
    return argument;
}

/*
 * Implementation of adaptor class NotificationsAdaptor
 */

NotificationsAdaptor::NotificationsAdaptor(NotificationsManager *parent, const QStringList &caps)
                    : QDBusAbstractAdaptor(parent)
                    , m_service(parent)
                    , m_capabilities(caps)
{
    // constructor
    setAutoRelaySignals(true);
}

NotificationsAdaptor::~NotificationsAdaptor()
{
    // destructor
}

void NotificationsAdaptor::CloseNotification(uint id)
{
    // handle method call org.freedesktop.Notifications.CloseNotification
    QMetaObject::invokeMethod(parent(), "CloseNotification", Q_ARG(uint, id));
}

QStringList NotificationsAdaptor::GetCapabilities()
{
    return m_capabilities;
}

QString NotificationsAdaptor::GetServerInformation(QString &return_vendor, QString &return_version, QString &return_spec_version)
{
    return_vendor = "Orbital";
    return_version= "0.1";
    return_spec_version = "1.2";
    return QString("");
}

template<class... Args>
bool hasHint(const QVariantMap &hints, QString &hint, const QString &given, Args... others)
{
    if (hints.contains(given)) {
        hint = given;
        return true;
    }
    return hasHint(hints, hint, others...);
}
inline bool hasHint(const QVariantMap &hints, QString &hint)
{
    return false;
}

uint NotificationsAdaptor::Notify(const QString &app_name, uint id, const QString &icon, const QString &summary, const QString &body, const QStringList &actions, const QVariantMap &hints, int timeout)
{
    // handle method call org.freedesktop.Notifications.Notify
    static uint return_id = 0;

    Notification *notification = new Notification;
    notification->setId(++return_id);
    notification->setBody(body);
    notification->setSummary(summary);
    notification->setIconName(icon);

    QString hint;
    if (hasHint(hints, hint, "image-data", "image_data")) {
        DBusImageStruct img;
        hints.value(hint).value<QDBusArgument>() >> img;
        QImage::Format format = img.hasAlpha ? QImage::Format_RGBA8888 : QImage::Format_RGBX8888;
        QImage image((const uchar *)img.data.constData(),img.width, img.height, img.rowstride, format);
        notification->setIconImage(QPixmap::fromImage(image));
    }

    m_service->newNotification(notification);
    return return_id;
}

