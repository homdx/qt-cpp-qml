#include "backend.h"
#include <QDebug>
#include "downloadmanager.h"
using namespace std;
    DownloadManager manager;


BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{

}

QString BackEnd::userName()
{
    return m_userName;
}

void BackEnd::setUserName(const QString &userName)
{

    qDebug() << userName;
    qDebug() << m_userName;

    if (userName == m_userName)
        return;
    ;
    //    manager.append(arguments);
    manager.append(userName);

    m_userName = userName;
    emit userNameChanged();
}
