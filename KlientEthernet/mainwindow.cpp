#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkDatagram>
#include <QUdpSocket>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::receiveDatagram);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::startConnection);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::stopConnection);
    motherAddress.setAddress("192.168.0.33");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveDatagram()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram networkDatagram = udpSocket->receiveDatagram();
        printData(networkDatagram);
    }
}

void MainWindow::printData(const QNetworkDatagram& network)
{
    uint8_t * data = (uint8_t*)network.data().data();
    qDebug() << "New data:";
    for(int i = 0 ;i <14; i++)
    {
        qDebug() <<  i << "  " <<  data[i];
    }
    ui->progressBara->setValue(data[0]);
    ui->progressBarb->setValue(data[1]);
    ui->progressBarc->setValue(data[2]);
    ui->progressBard->setValue(data[3]);
    ui->progressBare->setValue(data[4]);
    ui->progressBarf->setValue(data[5]);
    ui->progressBarg->setValue(data[6]);
    ui->progressBarh->setValue(data[7]);
    ui->progressBari->setValue(data[8]);
    ui->progressBarj->setValue(data[9]);
    ui->progressBark->setValue(data[10]);
    ui->progressBarl->setValue(data[11]);
    ui->progressBarm->setValue(data[12]);
    ui->progressBarn->setValue(data[13]);
}

void MainWindow::startConnection()
{
    QByteArray array;
    array.append('a');
    qDebug() << "send start " << udpSocket->writeDatagram(array, motherAddress, 8080);
}

void MainWindow::stopConnection()
{
    const char data = 's';
    qDebug() << "send stop " << udpSocket->writeDatagram(&data, 1, motherAddress, 8080);
}
