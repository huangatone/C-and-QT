#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QObject>
#include <QDebug>
#include <QString>
#include <QSslConfiguration>
#include <QVariant>

#include "webrequest.h"

class DBConnect : public QObject {

    Q_OBJECT
  //  Q_PROPERTY(QString responseStr author READ author WRITE setAuthor)

public:
    DBConnect();
    bool isConnectedToDB() { return isconnected; }
    QString responseStr;

public slots:
    bool login(const QString &dfserver, const QString &dfuser, const QString &dfpass);
    bool getStudies();
    bool setStudyNumber(uint);
    bool getSitesInfoList();

signals:
    void connected(const QString& result);
    void failure(const QString& result);
    void studiesList(const QString& result);
    void sitesInfoList(const QString & result);



private:
    QString uid;
	//QString responseStr;
    WebRequest req;
    bool isconnected;
};


#endif // DBCONNECT_H
