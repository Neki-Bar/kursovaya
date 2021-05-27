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

    signal logIn();
    signal toSignUp();
    ColumnLayout {

        anchors.fill: parent
        anchors.margins: 60


        Rectangle{
            id: _button_to_sign_up
            width: 90
            height: 30
            anchors.right: parent.right
            anchors.top: parent.top
            color: "#968F8D"
                MouseArea{
                    id: _to_sign_up
                    anchors.fill: parent

                    onClicked: {
                        toSignUp();
                    }

                    Text{
                        color: "#ffffff"
                        text: "Регистрация"
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
            id: _login_input
            descrip: "Логин"
            width: parent.width
            height: 50
        }
        InputBlock{
            id: _password_input
            descrip: "Пароль"
            width: parent.width
            height: 50
            mode: "Password"
        }

        Text{
            id : _alert
            visible: false
            text: "Неправильный логин или пароль."
            anchors.left: _password_input.left
            anchors.top: _password_input.bottom
        }

        Rectangle{
            width: 140
            height: 40
            color: "#968F8D"

            anchors.right: parent.right
            anchors.bottom: parent.bottom
            MouseArea{
                id: _log_in
                anchors.fill: parent

                onClicked: {

                    if (controll.logIn(_login_input.inputtext, _password_input.inputtext))
                       { _form_wrapper.logIn();}
                    else{
                        _alert.visible = true;
                    }
                }

                Text{
                    color: "#ffffff"
                    text: "Войти"
                    font.pointSize: 14
                    anchors.centerIn: parent
                }
            }

        }
    }
    AppController{
        id: controll
    }
}
