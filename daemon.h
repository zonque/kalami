/***
  Copyright (c) 2017 Nepos GmbH

  Authors: Daniel Mack <daniel@nepos.io>

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This software is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this software; If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef DAEMON_H
#define DAEMON_H

#include <QObject>
#include <QWebSocket>
#include <QNetworkConfigurationManager>
#include <QtDBus/QDBusInterface>

#include "alsamixer.h"
#include "connman.h"
#include "linuxled.h"
#include "reduxproxy.h"
#include "udevmonitor.h"

class Daemon : public QObject
{
    Q_OBJECT
public:
    explicit Daemon(QUrl serverUri, QObject *parent = 0);
    ~Daemon();

signals:

public slots:

private slots:
    void reduxStateUpdated(const QJsonObject &state);

private:
    ALSAMixer *mixer;
    LinuxLED *homeButtonLED;
    Connman *connman;
    ReduxProxy *redux;
    UDevMonitor *udev;
    QDBusInterface *systemdConnection;
};

#endif // DAEMON_H
