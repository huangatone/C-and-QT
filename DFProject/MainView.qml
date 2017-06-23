import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

import Qt.labs.platform 1.0

Page {

    visible: true
    width: parent.width
    height: parent.height
    title: qsTr("Hello World")
    //! [orientation]
       readonly property bool inPortrait: window.width < window.height
   //! [orientation]

    id:root

    header: ToolBar {
        id:overlayHeader
             RowLayout {
                 id:t_lay
                 anchors.fill: parent
                 ToolButton {
                     text: qsTr("‹")
                     onClicked: {

                         //stack.pop()
                         drawer.visible = true
                     }
                 }
                 Label {
                     text: "Title"
                     elide: Label.ElideRight
                     horizontalAlignment: Qt.AlignHCenter
                     verticalAlignment: Qt.AlignVCenter
                     Layout.fillWidth: true
                 }
                 ToolButton {
                     text: qsTr("⋮")
                     onClicked: menu.open()
                 }
             }
         }

    Menu    {
        id: menu
        //y: 0

        MenuItem {
            text: "New..."
            onTriggered:
            {

            }
        }
        MenuItem {
            text: "Open..."
        }
        MenuItem {
            text: "Save"
        }
        MenuItem {
                  text: qsTr("Zoom In")
                  shortcut: StandardKey.ZoomIn
                  onTriggered: zoomIn()
              }

              MenuItem {
                  text: qsTr("Zoom Out")
                  shortcut: StandardKey.ZoomOut
                  onTriggered: zoomOut()
              }

    }

    Drawer {
            id: drawer
        topMargin: overlayHeader.height
            //y: overlayHeader.height
            width: window.width / 4
            height: window.height - overlayHeader.height

            modal: inPortrait
            //interactive: inPortrait
            position: inPortrait ? 0 : 1
            visible: !inPortrait

            ListView {
                id: listView
                anchors.fill: parent

                headerPositioning: ListView.OverlayHeader
                header: Pane {
                    id: header
                    z: 2
                    width: parent.width

                    contentHeight: logo.height

                    Image {
                        id: logo
                        width: parent.width
                        source: "images/cdsi_logo.png"
                        fillMode: implicitWidth > width ? Image.PreserveAspectFit : Image.Pad
                    }

                    MenuSeparator {
                        //parent: header
                        //width: parent.width
                        //anchors.verticalCenter: parent.bottom
                        visible: !listView.atYBeginning
                    }
                }

                footer: ItemDelegate {
                    id: footer
                    text: qsTr("Footer")
                    width: parent.width

                    MenuSeparator {
                        //parent: footer
                        //width: root.width
                        //anchors.verticalCenter: root.top
                    }
                }

                model: 10

                delegate: ItemDelegate {
                    text: qsTr("Title %1").arg(index + 1)
                    width: parent.width
                    onPressed: console.log(text)
                }

                ScrollIndicator.vertical: ScrollIndicator { }
            }
        }

   /* Flickable {
           id: flickable

           anchors.fill: parent
           anchors.topMargin: overlayHeader.height
           anchors.leftMargin: !inPortrait ? drawer.width : undefined

           topMargin: 20
           bottomMargin: 20
           contentHeight: column.height

           Column {
               id: column
               spacing: 20
               anchors.margins: 20
               anchors.left: parent.left
               anchors.right: parent.right

               Label {
                   font.pixelSize: 22
                   width: parent.width
                   elide: Label.ElideRight
                   horizontalAlignment: Qt.AlignHCenter
                   text: qsTr("Side Panel Example")
               }

               Label {
                   width: parent.width
                   wrapMode: Label.WordWrap
                   text: qsTr("This example demonstrates how Drawer can be used as a non-closable persistent side panel.\n\n" +
                              "When the application is in portrait mode, the drawer is an interactive side panel that can " +
                              "be swiped open from the left edge. When the application is in landscape mode, the drawer " +
                              "and the content are laid out side by side.\n\nThe application is currently in %1 mode.").arg(inPortrait ? qsTr("portrait") : qsTr("landscape"))
               }
           }

           ScrollIndicator.vertical: ScrollIndicator { }
       }
       */






    Landscape
    {
        x: !inPortrait? drawer.width:0
        width: inPortrait?parent.width :parent.width - drawer.width
    }
}
