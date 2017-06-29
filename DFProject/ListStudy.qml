import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

Page {
    //property var sObj: dCenter.sitesObjs;
   id:studyPage
   signal switchTo(int index)
   property var sitesObjs: {}
    header:
        Text
        {
            text:"DFexploreDB Server: "
        }
    Connections {
        target: DFexploreDB
        onStudiesList: showSites(result)
    }
    Component.onCompleted: {
       // DFexploreDB.setStudyNumber(154)
        console.log("getSitesInfoList Running!")
        DFexploreDB.getStudies()

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
            text: "<i>"+name+"</i>"  +" ⋮ "+ "<b>" + id+ "</b> "  +"<br> <small> n participant </small>"
            onClicked: {
                //message("clicked: "+name +":"+id);
                DFexploreDB.setStudyNumber(id)
                DFexploreDB.getSitesInfoList()
                studyPage.switchTo(1)
            }
        }
    }


    function showSites(msg) {

        console.log("studies: Studies Server Response:", msg)
        //sitesObjs = JSON.parse(msg);
        var sObj = JSON.parse(msg);
        var i=0;
        while (sObj[i])
        {
            //studiesPage.studiesDataModel.append(sObj[i]);
            console.log("name: ",sObj[i].name,"id:", sObj[i].studyId)
            sitesModel.append({"name":sObj[i].name,"id": sObj[i].studyId})
            i++;
        }
        return "OK"
    }
}
