import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Page {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id:root

    Button {
        id: button
        x: 280
        y: 202
        text: qsTr("Button")
        onClicked: {
            //var a = Qt.createComponent()
            var newObject = Qt.createQmlObject('import QtQuick 2.0; Rectangle {color: "red"; width: 20; height: 20}',
                                                 root,
                                                 "dynamicSnippet1");
        }

    }

    Button {
        id: button1
        x: 147
        y: 202
        text: qsTr("Button")
        onClicked: {
            console.log("Button Pressed. Entered text: " + textField1.text);
             console.log("Button Pressed. MyDB text: " + MyDB.getName());
            root.StackView.view.push("qrc:/MainView.qml")
        }

    }

    Label {
        id: label
        x: 142
        y: 81
        text: qsTr("Label")
    }

    Label {
        id: label1
        x: 147
        y: 135
        text: qsTr("Label")
    }

    CheckBox {
        id: checkBox
        x: 439
        y: 135
        text: qsTr("Check Box")
    }

    TextField {
        id: textField
        x: 220
        y: 69
        text: qsTr("Text Field")
    }

    TextField {
        id: textField1
        x: 220
        y: 128
        text: qsTr("Text Field")
    }


}
