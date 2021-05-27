import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CustControll 1.0

Rectangle{
    id: _form_wrapper

    width: 550
    height: 580
    anchors.centerIn: parent

    color: "#6B6765"


    signal signUp();
    signal toLogIn();
    ColumnLayout {

        anchors.fill: parent
        anchors.margins: 60


        Rectangle{
            id: _button_to_log_in
            width: 60
            height: 30
            anchors.right: parent.right
            anchors.top: parent.top
            color: "#968F8D"
                MouseArea{
                    id: _to_log_in
                    anchors.fill: parent

                    onClicked: {
                        toLogIn();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Вход"
                        anchors.centerIn: parent
                    }
            }
        }
        Rectangle{
            id: _label
            width: parent.width
            height: 50
            color: "#6B6765"
            Text{
                color: "#ffffff"
                text: "Stratego"
                font.pointSize: 30
                font.bold: true

                anchors.centerIn: parent
            }
        }

        InputBlock{
            id : _login_input
            descrip: "Логин"
            width: parent.width
            height: 50
        }
        InputBlock{
            id : _password_input
            descrip: "Пароль"
            width: parent.width
            height: 50
            mode: "Password"
        }
        InputBlock{
            id: _confirm_input
            descrip: "Повторите пароль"
            width: parent.width
            height: 50
            mode: "Password"
            //visible:
        }

        Rectangle{
            id: _button_sign_up
            width: 200
            height: 40
            color: "#968F8D"

            anchors.right: parent.right
            anchors.bottom: parent.bottom
            MouseArea{
                id: _sing_up
                anchors.fill: parent

                onClicked: {
                    if (controll.signUp(_login_input.inputtext, _password_input.inputtext, _confirm_input.inputtext))
                       { _form_wrapper.signUp();}
                }

                Text{
                    color: "#ffffff"
                    text: "Зарегистрироваться"
                    font.pointSize: 14
                    anchors.centerIn: parent
                }
            }

        }
    }
    AppController{
        id : controll
    }
}
