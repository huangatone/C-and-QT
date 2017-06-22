#ifndef MYDB_H
#define MYDB_H

#include <QObject>

class MyDB : public QObject
{
	Q_OBJECT
public:
	explicit MyDB(QObject *parent = 0);

signals:

public slots:
};

#endif // MYDB_H