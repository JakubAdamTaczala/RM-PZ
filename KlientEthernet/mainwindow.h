#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void receiveDatagram();

    void printData(const QNetworkDatagram &network);

    void startConnection();

    void stopConnection();

private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
    QHostAddress myAddress;
    QHostAddress motherAddress;
};

#endif // MAINWINDOW_H
