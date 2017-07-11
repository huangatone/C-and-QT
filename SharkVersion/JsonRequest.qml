import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick 2.5

import "con/test.js" as MyTest

Page {

        Label {
            id: emailLabel
            text: qsTr("Email")
        }
        Label {
            id: urlLabel
            text: qsTr("URL")
        }
        Label {
           id: sinceLabel
           text: qsTr("Since")
        }
        Label {
           id: bioLabel
           text: qsTr("Bio")
        }
        Button {
            id: requestButton
            text: "World Domination"
            onClicked: {

                var JsonString = '{"a":"A whatever, run","b":"B fore something happens","c":"QW"}';
                var JsonObject= JSON.parse(JsonString);

                //retrieve values from JSON again
                var aString = JsonObject.a;
                var bString = JsonObject.b;
                var cString = JsonObject.c;

                console.log(aString);
                console.log(bString);
                console.log(cString);

                var xhr = new XMLHttpRequest();
                xhr.open("GET","https://twitter.com/search?q=canada",true);

                xhr.onreadystatechange = function()
                {
                    if ( xhr.readyState == xhr.DONE)
                    {
                        if ( xhr.status == 200)
                        {
                            //  console.log(xhr.responseText);
                            //var jsonObject1 =JSON.parse( xhr.responseText );
                            //loaded(jsonObject1)
                         }
                       }
                }
                xhr.send();

                MyTest.loadJSON("https://twitter.com/search?q=canada",function(data) { console.log(data); },
                function(xhr) { console.error(xhr); }
                );

            }
        }

    // this function is included locally, but you can also include separately via a header definition
    function request(url, callback) {
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = (function(myxhr) {
            return function() {
                callback(myxhr);
            }
        })(xhr);
        xhr.open('GET', url, true);
        xhr.send('');
    }
}
