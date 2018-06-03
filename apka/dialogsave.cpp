#include "dialogsave.h"
#include "ui_dialogsave.h"

dialogsave::dialogsave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogsave)
{
    ui->setupUi(this);
}

dialogsave::~dialogsave()
{
    delete ui;
}
