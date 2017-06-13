import QtQuick 2.7
import test 1.0

Page1Form {
    A
    {

    }

    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
    }
}
