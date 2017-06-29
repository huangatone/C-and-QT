import QtQuick 2.7

Rectangle {
    width: 320
    height: 480
    ListView {
        id: view
        anchors.fill: parent

    }

    function request() {
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.HEADERS_RECEIVED) {
                print('HEADERS_RECEIVED')
            } else if(xhr.readyState === XMLHttpRequest.DONE) {
                print('DONE')
                var json = JSON.parse(xhr.responseText.toString())
                view.model = json.items
            }
        }
        xhr.open("GET", "http://api.flickr.com/services/feeds/photos_public.gne?format=json&nojsoncallback=1&tags=munich");
        xhr.send();
    }

    Component.onCompleted: {
        request()
    }
}
