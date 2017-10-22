#include <QApplication>//includeieren  von QT

#include "mainwindow.h"//includieren dees eigenen Fensters

int main( int argc, char **argv )
{
    QApplication a(argc, argv);//starten des eigenen Fensters
	
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

	return a.exec();
}

