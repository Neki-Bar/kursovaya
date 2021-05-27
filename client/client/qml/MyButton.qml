import QtQuick 2.0

Item{
    id: _root

    property string color : "#968F8D"
    property string textColor: "#ffffff"
    property string text


    width: 200
    height: 30
    signal clicked();
    Rectangle{
        id: bg
        width: _root.width
        height: _root.height
        anchors.fill: parent
        color: _root.color


            Text{
                color: _root.textColor
                text: _root.text
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onCanceled: {
                    _root.clicked();
                    bg.color = "#000000"
           }
        }
    }
}
