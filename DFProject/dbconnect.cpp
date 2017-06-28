#include "dbconnect.h"

DBConnect::DBConnect()
{
    isconnected = false;
}

bool DBConnect::setStudyNumber(uint snum){
    QByteArray data;
    qDebug() <<"sid:" <<snum;
    if (req.reqSetStudy(snum, data))
    {
        qDebug() <<"get study list in object" << data;
        responseStr = data;

        //emit studiesList(responseStr);
        return true;
    }
    else
    {
        qDebug("setStudyNumber: Are we still logged in?");
        return false;
    }
}

bool DBConnect::getSitesInfoList(){
    QByteArray data;
    if (req.reqCenters(data))
    {
        qDebug() <<"get sites list in object" << data;
        responseStr = data;
        emit sitesInfoList(responseStr);
        return true;
    }
    else
    {
        qDebug("Are we still logged in?");
        return false;
    }
}

bool DBConnect::getStudies()
{
    QByteArray data;
    if (req.reqStudyList(data))
    {
        qDebug() <<"get study list in object";
        responseStr = data;
        emit studiesList(responseStr);
        return true;
    }
    else
    {
        qDebug("Are we still logged in?");
        return false;
    }
}

bool DBConnect::login(const QString &dfserver, const QString &dfuser, const QString &dfpass)
{
    int port = 4433;
    int wait = 30; //seconds
    int dur = 3;
    QString web_svr = "dfws.datafax.com";

    QByteArray data;
    isconnected = false;
    if (!req.reqAuthorize(web_svr, port, wait, dfserver, dfuser, dfpass, dur, data)) {
                if (data.size() == 0) {
                    qDebug("Warning: no response from DFws service\n");
                    return false;
                } else {
                    responseStr = data;
                    emit failure(responseStr);
                    isconnected = true;
                    return true;
                }
    }
    else
    {
            responseStr = data;
            emit connected(responseStr);
            isconnected = true;
            return true;
    }
}

