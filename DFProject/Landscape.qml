import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

Page {

    visible: true
        width: parent.width
        height: parent.height
        title: qsTr("Hello World")
        id:root
        SwipeView {
            id: swipeView
            anchors.fill: parent
            currentIndex: tabBar.currentIndex

            Page1 {
                id:p1
            }

            Page {
                id:p2
                Label {
                    id: t2
                    text: qsTr("Second page")
                    anchors.centerIn: parent
                }
            }

            Page
            {
                id:p3
            }
        }

        footer: TabBar {
            id: tabBar
            currentIndex: swipeView.currentIndex
            TabButton {
                text: qsTr("First")

            }
            TabButton {
                text: qsTr("Second")
                onClicked:  t2.text = p1.button1.text

            }
            TabButton {
                text: qsTr("Third")
            }
        }
}
