#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QProgressBar>
#include <QLabel>
#include <QPainter>
namespace Ui {
class MainWindow;
}

struct Finger
{
    int maxPressure;
    int minPressure;
    int maxTensure;
    int minTensure;

};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void setProgressBarToZero();
public slots:
    void receiveDatagram();

    void printData(const QNetworkDatagram &network);

    void startConnection();

    void stopConnection();

private:
    QVector<QProgressBar*> progressBars;
    QLabel* timeLabel;
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
    QHostAddress myAddress;
    QHostAddress motherAddress;

    bool communicationOn;

    QVector<Finger> fingerSettings;

};

#endif // MAINWINDOW_H
