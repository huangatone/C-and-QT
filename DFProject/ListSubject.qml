import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

Page {
    //property var sObj: dCenter.sitesObjs;
   //property var sitesObjs: {}
    header:
        Text
        {
            text:"Site id> Subjects"
        }
    Connections {
        target: DFexploreDB
        onSitesInfoList: showSites(result)
    }
    Component.onCompleted: {
        DFexploreDB.setStudyNumber(154)
        console.log("getSitesInfoList Running!")
        DFexploreDB.getSitesInfoList()

        console.log("Completed getSitesInfoList!")
    }

    // The model:
    ListModel {
        id: sitesModel
    }

    // The view:
    ListView {
        id: listView
        height: parent.height
        width: 80
        anchors {
            left: parent.left; top: parent.top;
            right: parent.right; bottom: parent.bottom;
            margins: 20
        }
        model: sitesModel
        delegate: ItemDelegate {
            //text: title
            text: "<i>"+centerId+"</i>"  +" ⋮ "+ "<b>" + affiliation+ "</b> "  +"<br> <small> n participant </small>"
            onClicked: {
                message("clicked: "+centerId +":"+affiliation);
            }
        }
    }


    function showSites(msg) {

        console.log("studies: Studies Server Response:", msg)
        var sitesObjs = JSON.parse(msg);
        sitesModel.clear()
        var i=0;
        while (sitesObjs[i])
        {
            sitesModel.append({"centerId":sitesObjs[i].centerId, "affiliation": sitesObjs[i].affiliation});
            i++;
        }
        return "OK"
    }
}
