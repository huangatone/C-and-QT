#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mydb.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	MyDB db;

	engine.rootContext()->setContextProperty("MyDB", &db);

	engine.load(QUrl(QLatin1String("qrc:/main.qml")));

	return app.exec();
}
