import QtQuick 2.0

Rectangle {

    id:empty_rectangle
    //property color color_empty_rectangle
    //property int x_empty_rectangle
    //property int y_empty_rectangle
    property alias text_rect  :  rect_text.text

    width: 40
    height: 40
    color :"grey"
    x:0
    y:0
    anchors.margins: 2

    Text {
        id: rect_text
        text: ""
        //text: qsTr("")
        anchors.centerIn: parent
    }

}
