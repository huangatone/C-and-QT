import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

Page {

    Connections {
        target: p1
        onSwitchTo: switchTo(index)
    }

    visible: true
        width: parent.width
        height: parent.height
        title: qsTr("Hello World")
        id:root
        SwipeView {
            id: swipeView
            anchors.fill: parent
            currentIndex: tabBar.currentIndex

            ListStudy {
                id:p1
            }

            ListSite {
                id:p2
                Label {
                    id: t2
                    text: qsTr("Second page")
                    anchors.centerIn: parent
                }
            }

            ListSubject
            {
                id:p3
            }
            PageView
            {
                id:p4
            }


        }

        footer: TabBar {
            id: tabBar
            currentIndex: swipeView.currentIndex
            TabButton {
                text: qsTr("Study")
            }
            TabButton {
                text: qsTr("Site")
            }
            TabButton {
                text: qsTr("Subject")
            }
            TabButton {
                text: qsTr("Page")
            }

        }

        function switchTo( index)
        {
            tabBar.currentIndex = index
        }
}
