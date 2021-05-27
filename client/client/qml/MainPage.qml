import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle{
    id: _root

    width: 550
    height: 580
    anchors.centerIn: parent

    color: "#6B6765"

    signal toAccount();
    signal toCall();
    signal toGame();
    signal toStatistic();
    signal toExit();

    ColumnLayout{
        anchors.fill: parent
        MouseArea{
            id: _to_account
            width: 100
            height: 50
            anchors.top: parent.top
            onClicked: {
                toAccount();

            }

            RowLayout{
                Rectangle{
                    id: _bg_icon
                    color: "#524F4E"
                    width: 50
                    height: 50
                    anchors.left: parent.left
                    anchors.top: parent.top
                    Rectangle{
                        id: _circle
                        width: _bg_icon.width*0.618
                        height: _bg_icon.height*0.618
                        anchors.centerIn: _bg_icon
                        radius: _bg_icon.width / 2
                        color: "#7A7777"
                        Text{
                            anchors.centerIn: _circle
                            text: "N"
                            color: "#ffffff"
                            font.pointSize: 13
                        }
                    }

                }
                Text{
                    id: _percent
                    height: _bg_icon.height
                    anchors.left: _bg_icon.verticalCenter
                    text: "15%"
                    font.pointSize: 12
                    color: "#ffffff"
                }
            }


        }
        ColumnLayout{
            anchors.centerIn: parent

//            MyButton{
//                text: "Пригласить"

//                onClicked: {
//                    _root.toCall();
//                }
//            }
//            MyButton{
//                text: "Играть"

//                onClicked: {
//                    _root.toGame();
//                }
//            }
//            MyButton{
//                text: "Рейтинг"

//                onClicked: {
//                    _root.toStatistic();
//                }
//            }
//            MyButton{
//                text: "Выйти"

//                onClicked: {
//                    _root.toExit();
//                    _root.color = "#000000"
//                }

//            }
            Rectangle{
                id: _button_sign_up
                width: 140
                height: 40
                color: "#968F8D"


                MouseArea{
                    id: _sing_up
                    anchors.fill: parent

                    onClicked: {
                        _root.toCall();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Пригласить"
                        font.pointSize: 14
                        anchors.centerIn: parent
                    }
                }

            }


            Rectangle{

                width: 140
                height: 40
                color: "#968F8D"

                MouseArea{

                    anchors.fill: parent

                    onClicked: {
                        _root.toGame();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Играть"
                        font.pointSize: 14
                        anchors.centerIn: parent
                    }
                }

            }

            Rectangle{

                width: 140
                height: 40
                color: "#968F8D"

                MouseArea{

                    anchors.fill: parent

                    onClicked: {
                        _root.toStatistic();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Рейтинг"
                        font.pointSize: 14
                        anchors.centerIn: parent
                    }
                }

            }


            Rectangle{

                width: 140
                height: 40
                color: "#968F8D"


                MouseArea{

                    anchors.fill: parent

                    onClicked: {
                        _root.toExit();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Выйти"
                        font.pointSize: 14
                        anchors.centerIn: parent
                    }
                }

            }
        }
    }

}
