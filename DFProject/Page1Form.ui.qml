import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias textField1: textField1
    property alias button1: button1
    property alias comboBox: comboBox
    property alias comboBoxTextRole: comboBox.textRole
    property alias button: button

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: textField1
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button1
            text: qsTr("Press Me")
        }
    }

    ComboBox {
        id: comboBox
        currentIndex: 2
        x: 167
        y: 86
        textRole: qsTr("color")

        model: ListModel {
            id: list_1
            ListElement {
                text: "Banana"
                color: "Yellow"
            }
            ListElement {
                text: "Apple"
                color: "Green"
            }
            ListElement {
                text: "Coconut"
                color: "Brown"
            }
        }
    }

    Button {
        id: button
        x: 394
        y: 123
        text: qsTr("OK")
    }
}
