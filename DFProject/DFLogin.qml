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
        text: qsTr("Button 123")
        onClicked: {
            //var a = Qt.createComponent()
            var newObject = Qt.createQmlObject('import QtQuick 2.0; Rectangle {color: "red"; width: 20; height: 20}',
                                                 root,
                                                 "dynamicSnippet1");
            var newObject1 = Qt.createQmlObject('import QtQuick.Controls 2.1; Button {  width: 120; height: 30; text:"New"; x:60 ;onClicked: {console.log("Button Pressed.  text: " +  button.text)}}',
                                                 root,
                                                 "dynamicSnippet2");
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
        id: labe_time
        x: 142
        y: 10
        text: qsTr("Label")
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

    Connections
    {
        target: MyDB
        onDataChanged:
        {
            labe_time.text= MyDB.getCurrentDateTime()
            console.log("The application data changed!")
            console.log("Hha!")
        }
    }



}
