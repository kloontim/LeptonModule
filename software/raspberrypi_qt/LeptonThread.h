#ifndef LEPTONTHREAD//Header bla bla
#define LEPTONTHREAD

#define HAVE_LEPTON true //as readme has told, debug option that has to be true when lapton should be used
#define DEBUG_LEPTON false // safes log if I remember corredctly

#include <stdint.h>//including things seems like standrt
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>//solte man nachgehen
#include <fcntl.h>//diesem auch

#if HAVE_LEPTON
#include <sys/ioctl.h>//Wenn Lepton da verschaffe zugriff auf das System
#include <linux/types.h>
#include <linux/spi/spidev.h>
#endif

#if DEBUG_LEPTON//Wenn debug includieren zum Speichern
#include <list>
#include <utility>
#endif

#include <QThread>//seems to work with QT stuff as well
#include <QDebug>
#include <QVector>


class LeptonThread : public QThread {//Creatig class LeptonThread with parrent QThread (shoud we also use that?)
    Q_OBJECT

    QVector<unsigned char> result;//creating two vectors one for input one for out, seems to be connected to Q_object
    QVector<unsigned short> rawData;

#if HAVE_LEPTON//if Lapton available create neccesary variables
    static const char *device;
    static unsigned char mode, bits;
    static unsigned int speed;
    static unsigned short delay;
    static QVector<unsigned char> tx;

    int fd;
    struct spi_ioc_transfer _tr;
#endif

#if DEBUG_LEPTON//more saving stuff
    std::list< std::pair<int, int> > sequence; // ...of packet #'s received from Lepton, for troubleshooting
#endif

    bool initLepton();//function declarations
    int getPacket(int iRow, unsigned char *packetData);

public:
    enum {//creates more variables for Picure recreation
        FrameWidth = 160,
        FrameHeight = 120,
        RowPacketWords = FrameWidth + 2,//HAS TO BE CHEKED HAND MADE FOR WRONG CAMERA MODEL
        RowPacketBytes = 2*RowPacketWords,//HAS TO BE CHEKED HAND MADE FOR WRONG CAMERA MODEL
        FrameWords = FrameWidth*FrameHeight//HAS TO BE CHEKED HAND MADE FOR WRONG CAMERA MODEL
    };//have never seen Enum before, but because there is no name given I would guess, that the name is the Class name

    LeptonThread();//constructor +deconstructor
    ~LeptonThread();

    void run();//more function declarations

signals://google needs to help you later
    void updateImage(unsigned short *, int, int);
};

#endif
