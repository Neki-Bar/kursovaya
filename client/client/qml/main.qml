import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.15
import CustControll 1.0


ApplicationWindow{
    id: _root
    width: 970
    height: 600
    visible: true
    title: qsTr("Stratego")
    Rectangle{
        id: _bg
        anchors.fill: parent
        color: "#5F5B5A"


        StackView{
            id: _stack
            anchors.fill: parent

            Component.onCompleted :{
                if (controll.isAutorisated()){
                    _stack.push(_mainPage);
                    _mainPage.visible = true;

                }else{
                    _stack.push(_loginPage);
                    _loginPage.visible = true;
                }
            }

            MainPage{
                id: _mainPage
                visible: false
                onToAccount: {

                }
                onToCall: {

                }
                onToExit: {

                    Qt.quit();

                }
                onToGame: {
                    _stack.push(_fillPage);
                }
                onToStatistic: {

                }


            }

            LoginPage{
                id: _loginPage
                visible: false
                onToSignUp: {
                    _stack.replace(_signupPage);
                }
                onLogIn: {

                    _stack.push(_mainPage);


                }
            }

            SignupPage{
                id: _signupPage
                visible: false
                onSignUp: {
                    _stack.push(_mainPage);
                }
                onToLogIn: {
                    _stack.replace(_loginPage);

                }
            }

            GamePage{
                id: _gamePage
                visible: false
            }

            FillPage{
                id: _fillPage
                visible: false
                onToMainPage: {
                    _stack.pop(_mainPage)
                }

                onToGamePage: {
                    _stack.push(_gamePage);
                }
            }


        }

        AppController{
            id : controll
        }
    }
}
