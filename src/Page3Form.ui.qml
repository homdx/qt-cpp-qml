import QtQuick 2.12
import QtQuick.Controls 2.5
import io.qt.examples.backend 1.0

Page {
    id: page
    width: 400
    height: 600

    title: qsTr(Qt.application.version) ? title : qsTr("Home")

    Label {
        text: qsTr("You are on the 3 page.")
        anchors.centerIn: parent
    }

    Text {
        id: versionlbl
        x: 151
        color: "#a40000"
        text: qsTr(Qt.application.version)
        anchors.top: parent.top
        anchors.topMargin: 80
        //qsTr("version")
        font.pixelSize: 12
    }



    TextInput {
        id: textInput
        x: 78
        y: 155
        width: 80
        height: 20
        text: qsTr("https://ya.ru")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 181
        y: 145
        text: qsTr("Button")
    }

    BackEnd {
          id: backend
      }

    Button {
      text: "Start download cpp"
      onClicked: {
          console.log('start cpp')
          backend.userName = textInput.text
  console.log('changed')
    }
     }

    Connections {
        target: button
        onClicked: { print(textInput.text)
        }
    }

}


