import QtQuick 2.4
import QtPositioning 5.5
import QtQuick.Dialogs 1.2

DbForm {
    signal clearwaypoint()
    signal addpoint(variant startCoordinate)
    signal route_update
    FileDialog
    {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        nameFilters: ["*.sqlite"]
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)


            Fin_An.Take_Path(""+fileDialog.fileUrls);



        }
        onRejected: {
            console.log("Canceled")
        }
    }

    db_btn.onClicked:
    {
          li_mod.clear();

        fileDialog.visible=true
        console.log(fileDialog.fileUrls)
    }
    line_cmb.onCurrentIndexChanged:
    {
        clearwaypoint()
        Fin_An.Take_Line(line_cmb.currentText)

    }




    Connections
    {
        target: Fin_An
        onSend_Line:
        {

            li_mod.append({"text":line} )

        }
    }
    Connections
    {
        target: Fin_An
        onSend_Coordinate:
        {

            var startCoordinate = QtPositioning.coordinate(parseFloat(lati),

                                                           parseFloat(longi));
            console.log(startCoordinate)
            addpoint(startCoordinate)

        }
    }

    Connections
    {
        target: Fin_An
        onRoute_update:
        {
            route_update()
        }
    }







}
