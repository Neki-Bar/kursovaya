import QtQuick 2.0
import CustControll 1.0

Rectangle{
    id: root
    color: "#5F5B5A"

    width: parent.width
    height: parent.height
    Rectangle{
        color: "#6B6765"
        width: parent.height
        height: parent.height
        anchors.left: root.left
        anchors.verticalCenter: root.verticalCenter

        GridView{
            id: _grid
            model: controll.model()

            width: parent.height - 20
            height: parent.height - 20
            cellWidth: width / 10
            cellHeight: height / 10
            anchors.centerIn: parent
            delegate: Item{
                id: _tile_wrapper
                width: _grid.cellWidth
                height: _grid.cellHeight

                visible: !model.voidcell
                MouseArea{
                    hoverEnabled: true
                    width: _tile_wrapper.width
                    height: _tile_wrapper.height

                    onClicked: {
                        controll.setCell(index);
                        if (controll.isChoosed(index)) _bg_tile.color = "#333333";
                    }

                    Rectangle{
                        id: _bg_tile
                        color: "#968F8D"
                        anchors.centerIn: _tile_wrapper

                        width: _tile_wrapper.width - 2
                        height: _tile_wrapper.height - 2

                        Text {
                            id: name
                            text: model.rang
                            color: "#ffffff"
                            anchors.centerIn: parent
                        }
                    }
                }
            }
        }


    }
    AppController{
        id: controll
    }
}


