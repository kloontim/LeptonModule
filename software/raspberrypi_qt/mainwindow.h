#ifndef MAINWINDOW_H
#define MAINWINDOW_H//Standart Header

#include <QMainWindow>//einbeziehen von QT
#include <QImage>

class QLabel;//erstellen von Classen
class LeptonThread;
class QGridLayout;

class MainWindow : public QMainWindow {//Erstellen von Main Window als kind von Q Main Window
    Q_OBJECT enum { ImageWidth = 320, ImageHeight = 240 };//scheint größe festzulegen

    static int snapshotCount;

    QLabel *imageLabel;//den erstellten Classen die tatsächliche Klasse zuweisen, da nur Pointer
    LeptonThread *thread;
    QGridLayout *layout;

    unsigned short rawMin, rawMax;//erstellen der Werte für das Rendern eines Live bildes
    QVector<unsigned short> rawData;
    QImage rgbImage;

public:
    explicit MainWindow(QWidget *parent = 0);//killt vermutlich start Fenster umn öffnet neues

public slots:
    void saveSnapshot();//provides functions for functionality
    void updateImage(unsigned short *, int, int);
};

#endif // MAINWINDOW_H
