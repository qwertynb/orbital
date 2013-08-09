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

import QtQuick 2.1
import Orbital 1.0

Item {
    id: elementsChooser

    Row {
        id: elementsList
        anchors.fill: parent
        spacing: 2

        Repeater {
            model: [ "Logout", "Clock", "Runner", "TaskBar", "Launcher" ]

            Rectangle {
                width: 100
                height: elementsList.height
                color: "dimgrey"

                Text {
                    text: modelData
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        var objParent = Overlay;
                        var pos = parent.mapToItem(objParent, mouse.x, mouse.y);
                        var newElem = Ui.createElement(modelData, objParent);
                        newElem.x = pos.x;
                        newElem.y = pos.y;

                        newElem.publish();
                    }
                }
            }
        }
    }
}