#ifndef MYDB_H
#define MYDB_H

#include <QObject>
<<<<<<< HEAD
//#include "webrequest.h"
=======
>>>>>>> 4cea3968911170e48f6dd686bfaf35ca1046a38c

class MyDB : public QObject
{
	Q_OBJECT
public:
	explicit MyDB(QObject *parent = 0);

<<<<<<< HEAD

	Q_INVOKABLE QString getName() { return "MyDB Class";}
	Q_INVOKABLE int getResult(int seed) { return seed *2;}
signals:

public slots:

private:
	//WebRequest req;
};

#endif // MYDB_H
=======
signals:

public slots:
};

#endif // MYDB_H
>>>>>>> 4cea3968911170e48f6dd686bfaf35ca1046a38c
