import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    property alias  db_btn: db_btn
    property alias line_cmb:line_cmb

    property alias  li_mod:li_mod

    Rectangle
    {
        id:header
        y:20
        height: title_text.height * 2
        color: "#46a2da"
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.left: parent.left
        anchors.right: parent.right
        Label
        {
            id:title_text
            text: qsTr("Route Coordinates")
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Item
    {

        id: item2
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: header.bottom
        GridLayout
        {
            id:gridLayout3
            rowSpacing: 10
            rows:1
            columns:3
            anchors.fill: parent
            Button
            {
                id:db_btn
                text:"select db"
            }
            ComboBox
            {
                id:line_cmb
                model: ListModel
                {
                    id:li_mod
                    ListElement{text:"0"}

                }

            }

            Button
            {
                id:create_route_btn
                text:"create route"
            }

        }
    }













}
