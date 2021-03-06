/*
 * Copyright 2013-2014 Giulio Camuffo <giuliocamuffo@gmail.com>
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

#include <QProcess>

#include "clibackend.h"

CliBackend::CliBackend()
{

}

CliBackend::~CliBackend()
{

}

CliBackend *CliBackend::create()
{
    CliBackend *logind = new CliBackend();
    return logind;
}

void CliBackend::poweroff()
{
    QProcess::execute("shutdown -h now");
}

void CliBackend::reboot()
{
    QProcess::execute("shutdown -r now");
}
