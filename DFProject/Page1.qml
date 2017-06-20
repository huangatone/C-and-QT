import QtQuick 2.7
import QtQuick.Window 2.0

Page1Form {

    //! [orientation]
        readonly property bool inPortrait: window.width < window.height
   //! [orientation]


    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
       comboBox.model.append({"text": "Banana", "color": "red"})


    }


}
