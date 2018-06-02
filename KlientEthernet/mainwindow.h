#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QProgressBar>
#include <QLabel>
namespace Ui {
class MainWindow;
}

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
};

#endif // MAINWINDOW_H
