import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

ApplicationWindow {
    id: apl_win
    visible: true
    width: 382
    height: 550
    color: "white"
    title: qsTr("Chess")

    Column{
        id: column_left
        spacing: 2
        anchors{left: parent.left
                top : gridUp.bottom
                margins: 2
               // spacing: 2
        }

        EmptyRect{width: 20; height: 20; color: "white"}
        EmptyRect{width: 20; text_rect: "8" ; color: "white"}
        EmptyRect{width: 20; text_rect: "7" ; color: "white"}
        EmptyRect{width: 20; text_rect: "6" ; color: "white"}
        EmptyRect{width: 20; text_rect: "5" ; color: "white"}
        EmptyRect{width: 20; text_rect: "4" ; color: "white"}
        EmptyRect{width: 20; text_rect: "3" ; color: "white"}
        EmptyRect{width: 20; text_rect: "2" ; color: "white"}
        EmptyRect{width: 20; text_rect: "1" ; color: "white"}
        EmptyRect{width: 20; height: 20; color: "white"}
    }
    Column{
        spacing: 2
        id: column_right
        anchors{left:  row_top.right
                top : gridUp.bottom
                margins: 2
               // spacing: 2
        }


        EmptyRect{width: 20; height: 20; color: "white"}
        EmptyRect{width: 20; text_rect: "8" ; color: "white"}
        EmptyRect{width: 20; text_rect: "7" ; color: "white"}
        EmptyRect{width: 20; text_rect: "6" ; color: "white"}
        EmptyRect{width: 20; text_rect: "5" ; color: "white"}
        EmptyRect{width: 20; text_rect: "4" ; color: "white"}
        EmptyRect{width: 20; text_rect: "3" ; color: "white"}
        EmptyRect{width: 20; text_rect: "2" ; color: "white"}
        EmptyRect{width: 20; text_rect: "1" ; color: "white"}
        EmptyRect{width: 20;  height: 20; color: "white"}
    }

    Row{
        id: row_top
        spacing: 2
        anchors.margins: 2
        anchors.left: column_left.right
        anchors.top: gridUp.bottom
        //anchors.margins: 2
        EmptyRect{height: 20; text_rect: "A" ; color: "white"}
        EmptyRect{height: 20; text_rect: "B" ; color: "white"}
        EmptyRect{height: 20; text_rect: "C" ; color: "white"}
        EmptyRect{height: 20; text_rect: "D" ; color: "white"}
        EmptyRect{height: 20; text_rect: "E" ; color: "white"}
        EmptyRect{height: 20; text_rect: "F" ; color: "white"}
        EmptyRect{height: 20; text_rect: "G" ; color: "white"}
        EmptyRect{height: 20; text_rect: "H" ; color: "white"}
    }
    Row{
        id: row_botom

        spacing: 2
        anchors.left: column_left.right
        anchors.bottom: gridDown.top
        anchors.margins: 2
        EmptyRect{height: 20; text_rect: "A" ; color: "white"}
        EmptyRect{height: 20; text_rect: "B" ; color: "white"}
        EmptyRect{height: 20; text_rect: "C" ; color: "white"}
        EmptyRect{height: 20; text_rect: "D" ; color: "white"}
        EmptyRect{height: 20; text_rect: "E" ; color: "white"}
        EmptyRect{height: 20; text_rect: "F" ; color: "white"}
        EmptyRect{height: 20; text_rect: "G" ; color: "white"}
        EmptyRect{height: 20; text_rect: "H" ; color: "white"}
    }

    Grid {
        id: gridDown
        columns: 10
        rows: 2
        anchors.top: column_left.bottom
        anchors.left: parent.left
        anchors.margins: 2
        spacing: 2
        EmptyRect{width: 20; color: "lightgray"}


        Repeater{
            model: 8
            delegate: EmptyRect{}
        }
        EmptyRect{width: 20; color: "lightgray"}
        EmptyRect{width: 20; color: "lightgray"}
        Repeater{
            model: 8
            delegate: EmptyRect{}
        }
        EmptyRect{width: 20; color: "lightgray"}


    }


    Grid {
        id:gridUp
        columns: 10
        rows: 2
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 2
        spacing: 2
        EmptyRect{width: 20; color: "lightgray"}
        Repeater{
            model: 8
            delegate: EmptyRect{}
        }
        EmptyRect{width: 20; color: "lightgray"}
        EmptyRect{width: 20; color: "lightgray"}
        Repeater{
            model: 8
            delegate: EmptyRect{}
        }
        EmptyRect{width: 20; color: "lightgray"}

    }

    Grid{
        id: pole
        anchors.margins: 2
        columns: 8
        anchors.left: column_left.right
        anchors.top: row_top.bottom
        spacing: 2
        Repeater{
            model: 64
            delegate: EmptyRect{color: ( (Math.floor(modelData/8) + modelData + 1) % 2)  ? "white" : "black" }
        }
    }

    Component{
        id:figura
        MouseArea {
            id:mouse_area_figura
            width: 42
            height: 42
            drag.target: image_figura
            onReleased:{
                console.error("indexindexStarted " + grid_view.indexStarted)
                console.error("indexEnded " + grid_view.indexEnded)
                controller_main.move(grid_view.indexStarted, grid_view.indexEnded);
            }
            onPressed:{
                grid_view.indexStarted = index
                console.error("indexStarted" + grid_view.indexStarted)
            }
            Image {
                id:image_figura
                scale: 0.5
                source: model.urlChess
                //source: sourceImageChess
                smooth: true
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                Drag.active: mouse_area_figura.drag.active
                Drag.source: mouse_area_figura
                Drag.hotSpot.x: 21
                Drag.hotSpot.y: 21
                states: [
                    State {
                        when : image_figura.Drag.active
                        AnchorChanges{
                            target: image_figura
                            anchors.verticalCenter: undefined
                            anchors.horizontalCenter: undefined
                        }
                    }
                ]
            }
            DropArea{
                anchors.fill: parent
                onEntered: {
                    console.error("onEntered " + index)
                    grid_view.indexEnded = index
                }
            }
       }
    }

    GridView{
        id:grid_view
        height: 336
        width: 336
        cellWidth: 42
        cellHeight: 42

        property int indexStarted: -1
        property int indexEnded: -1

        anchors.top: pole.top
        anchors.left: pole.left
        model: chessList //{id: listChess}
        delegate: figura
    }
}


