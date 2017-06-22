#ifndef MYDB_H
#define MYDB_H

#include <QObject>
//#include "webrequest.h"

class MyDB : public QObject
{
	Q_OBJECT
public:
	explicit MyDB(QObject *parent = 0);


	Q_INVOKABLE QString getName() { return "MyDB Class";}
	Q_INVOKABLE int getResult(int seed) { return seed *2;}
signals:

public slots:

private:
	//WebRequest req;
};

#endif // MYDB_H
