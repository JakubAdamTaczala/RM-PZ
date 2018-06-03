#include "mainwindow.h"
#include "opcjepomiarow.h"
#include "ui_mainwindow.h"



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
    progressBars.append(ui->progressBara);
    progressBars.append(ui->progressBarb);
    progressBars.append(ui->progressBarc);
    progressBars.append(ui->progressBard);
    progressBars.append(ui->progressBare);
    progressBars.append(ui->progressBarf);
    progressBars.append(ui->progressBarg);
    progressBars.append(ui->progressBarh);
    progressBars.append(ui->progressBari);
    progressBars.append(ui->progressBarj);

    timeLabel = new QLabel(QTime::currentTime().toString("hh:mm:ss:zzz"), this);
    ui->statusBar->addWidget(timeLabel);
    communicationOn = false;


    fingerSettings = /*new */QVector<Finger>(5);

    connect(ui->actionUstawienia_pomiar_w, &QAction::triggered,
            [=](){
        OpcjePomiarow pomiary(fingerSettings);
        if(0==pomiary.exec())
        {
            for(int i = 0; i<5; i++)
            {
                progressBars.at(2*i)->setMaximum(fingerSettings.at(i).maxPressure);
                progressBars.at(2*i)->setMinimum(fingerSettings.at(i).minPressure);
                progressBars.at(2*i+1)->setMaximum(fingerSettings.at(i).maxTensure);
                progressBars.at(2*i+1)->setMinimum(fingerSettings.at(i).minTensure);
            }
        }
    });
}

QVector<QString> ToSave;

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
    QString timeStr;

    uint16_t * data = (uint16_t*)network.data().data();
    if(!communicationOn && *((char*)data) == 's')
    {
        setProgressBarToZero();
        return;
    }
    qDebug() << "New data:";
    for(int i = 0 ;i <10; i++)
    {
        ToSave<<QString("%1").arg(data[i]);
        qDebug() <<  i << "  " <<  data[i];
    }

    timeLabel->setText(timeStr= QTime::currentTime().toString("hh:mm:ss:zzz"));
    ToSave<<timeStr;

    const int MAX_12BIT = 4096;
    for(int i = 0; i<10; i++)
    {
        if(1 == i%2)
        {
            progressBars.at(i)->setValue(MAX_12BIT - data[i]);
        }
        else
        {
            progressBars.at(i)->setValue(data[i]);
        }
    }

}

void MainWindow::startConnection()
{
    QByteArray array;
    array.append('a');
    if(udpSocket->writeDatagram(array, motherAddress, 8080))
    {
        communicationOn = true;
    }
}

void MainWindow::stopConnection()
{
    const char data = 's';
    if(udpSocket->writeDatagram(&data, 1, motherAddress, 8080))
    {
        communicationOn = false;
    }
}

void MainWindow::setProgressBarToZero()
{
    for(int i = 0 ; i < 10; i++)
    {
        progressBars.at(i)->setValue(0);
    }
}


void MainWindow::on_actionZapisz_pomiary_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Biorękawiczka - Zapisz jako",
                                                    "C:/",                                  // C:/Users/*/Documents
                                                    "Text Files (*.txt);;All Files (*.*)");
    if(!fileName.isEmpty()){
        curFile = fileName;
        saveFile();
    }
}

void MainWindow::saveFile(){
    QFile file(curFile);
    QTextStream out(&file);

    if(file.open(QFile::WriteOnly)){
        for(int i=0; i<ToSave.size(); i++){
            out << ToSave[i] << " ";
            if((i+1)%11==0) out << "\n";
        }
    }
    else{
        QMessageBox::warning(this,
                             "Biorękawiczka",
                             tr("Błąd zapisu")
                             .arg(curFile)
                             .arg(file.errorString()));
    }
}
