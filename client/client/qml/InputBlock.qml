import QtQuick 2.0
import QtQuick.Layouts 1.12

Item {
    id: root
    property string descrip
    property string mode
    property string inputtext
    ColumnLayout{
        Text{
            text: descrip
            font.pointSize: 12
            anchors.left: root.left
            anchors.top: root.top
            color: "#ffffff"

        }
        TextInput{
            id: _textInput_login
            width: 430
            color: "#CCC1BE"
            font.pointSize: 11
            z: -10
            echoMode: root.mode
            onTextChanged: {
                root.inputtext = getText(0, length);
            }

        }
        Rectangle{
            height: 3
            width: 430
            color:"#CCC1BE"
            anchors.top: _textInput_login.bottom
        }
    }
}
