#ifndef OPCJEPOMIAROW_H
#define OPCJEPOMIAROW_H

#include <QDialog>
#include <mainwindow.h>
namespace Ui {
class OpcjePomiarow;
}

class OpcjePomiarow : public QDialog
{
    Q_OBJECT

public:
    explicit OpcjePomiarow(QVector<Finger>& set, QWidget *parent = 0);
    ~OpcjePomiarow();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::OpcjePomiarow *ui;
    QVector<Finger>& settings;
};

#endif // OPCJEPOMIAROW_H
