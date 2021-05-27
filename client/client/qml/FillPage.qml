import QtQuick 2.0
import CustControll 1.0
import QtQuick.Layouts 1.12

Rectangle{
    id: root
    width: 970
    height: 600
    anchors.centerIn: parent

    color: "#5F5B5A"

    signal toMainPage()
    signal toGamePage()

    ColumnLayout{
        id: wrapper
        anchors.fill: parent

            Rectangle{
                width: 140
                height: 40
                color: "#968F8D"
                anchors{
                    top: wrapper.top
                    left: wrapper.left
                    margins: 20
                }
                MouseArea{
                    id: _to_mainPage
                    anchors.fill: parent

                    onClicked: {
                        toMainPage();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Назад"
                        font.pointSize: 14
                        anchors.centerIn: parent
                    }
                }

            }

            Rectangle{
                id: _list_bg
                width: height * 12 + 20
                height: _grid_bg.height / 4
                color: root.color
                anchors{
                    horizontalCenter: wrapper.horizontalCenter
                }
                ListView{
                    id: _list
                    model: controll.getFmodel();
                    spacing: 2
                    orientation: ListView.Horizontal
                    anchors.fill: parent

                    delegate:Item{
                        id: _fighter_wrapper
                        width: _list.height
                        height: _list.height

                        MouseArea{
                            id: _area_fighter
                            enabled: model.amount === 0 ? false : true
                            hoverEnabled: true
                            width: _fighter_wrapper.width
                            height: _fighter_wrapper.height

                            onClicked: {
                                controll.fighterChoosed(index);

                            }



                            Rectangle{
                                id: _bg_fighter
                                anchors.centerIn: _fighter_wrapper
                                color: model.color
                                width: _fighter_wrapper.width - 2
                                height: _fighter_wrapper.height - 2




                                Text {
                                    font.pointSize: 12
                                    text: model.rang
                                    color: "#ffffff"
                                    anchors.centerIn: parent
                                }

                            }
                        }
                        Text{
                            text: model.amount
                            color: "#ffffff"
                            anchors{
                                top: _area_fighter.bottom
                                horizontalCenter: _area_fighter.horizontalCenter
                                margins: 10
                            }
                            font.pointSize: 12
                        }
                    }
                }
            }

            Rectangle{
                id: _grid_bg
                width: root.width * 0.7
                height: width / 2.5
                color: root.color
                anchors{
                    horizontalCenter: wrapper.horizontalCenter

                }
                GridView{
                    id : _grid
                    model: controll.getmodel()

                    anchors.fill: parent

                    cellWidth: _grid_bg.width / 10
                    cellHeight: _grid_bg.height / 4


                    delegate: Item{
                        id: _tile_wrapper
                        width: _grid.cellWidth
                        height: _grid.cellHeight

                        visible: true //!model.voidcell
                        MouseArea{
                            hoverEnabled: true
                            anchors.fill: parent

                            onClicked: {
                                controll.tileChoosed(index);
                            }

                            onDoubleClicked: {
                                controll.removeTile(index);

                            }

                            Rectangle{
                                id: _bg_tile
                                color: "#968F8D"
                                anchors.centerIn: _tile_wrapper

                                width: _tile_wrapper.width - 2
                                height: _tile_wrapper.height - 2

                                Text {
                                    id: name
                                    color: "#ffffff"
                                    anchors.centerIn: parent
                                    font.pointSize: 12
                                    text: model.rang

                                }
                            }
                        }
                    }
                }
            }

            Rectangle{
                width: 140
                height: 40
                color: "#968F8D"
                anchors{
                    bottom: wrapper.bottom
                    right: wrapper.right
                    margins: 20
                }
                MouseArea{
                    id: _to_gamePage
                    anchors.fill: parent

                    onClicked: {
                        if (controll.isValidModel){
                            app_controll.moveModel();
                            toGamePage();
                        }
                    }

                    Text{
                        color: "#ffffff"
                        text: "Играть"
                        font.pointSize: 14
                        anchors.centerIn: parent

                    }
                }

            }



    }
    FillController{
        id: controll
    }

    AppController{
        id: app_controll
    }
}
