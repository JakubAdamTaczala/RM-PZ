#include "opcjepomiarow.h"
#include "ui_opcjepomiarow.h"

OpcjePomiarow::OpcjePomiarow(QVector<Finger> &set, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpcjePomiarow),
    settings(set)
{
    ui->setupUi(this);

    ui->maxN0->setValue(settings.at(0).maxPressure);
    ui->minN0->setValue(settings.at(0).minPressure);
    ui->maxZ0->setValue(settings.at(0).maxTensure);
    ui->minZ0->setValue(settings.at(0).minTensure);


    ui->maxN1->setValue(settings.at(1).maxPressure);
    ui->minN1->setValue(settings.at(1).minPressure);
    ui->maxZ1->setValue(settings.at(1).maxTensure);
    ui->minZ1->setValue(settings.at(1).minTensure);

    ui->maxN2->setValue(settings.at(2).maxPressure);
    ui->minN2->setValue(settings.at(2).minPressure);
    ui->maxZ2->setValue(settings.at(2).maxTensure);
    ui->minZ2->setValue(settings.at(2).minTensure);

    ui->maxN3->setValue(settings.at(3).maxPressure);
    ui->minN3->setValue(settings.at(3).minPressure);
    ui->maxZ3->setValue(settings.at(3).maxTensure);
    ui->minZ3->setValue(settings.at(3).minTensure);

    ui->maxN4->setValue(settings.at(4).maxPressure);
    ui->minN4->setValue(settings.at(4).minPressure);
    ui->maxZ4->setValue(settings.at(4).maxTensure);
    ui->minZ4->setValue(settings.at(4).minTensure);
}

OpcjePomiarow::~OpcjePomiarow()
{
    delete ui;
}

void OpcjePomiarow::on_pushButton_released()
{
    settings[0].maxPressure = ui->maxN0->value();
    settings[0].minPressure = ui->minN0->value();
    settings[0].maxTensure = ui->maxZ0->value();
    settings[0].minTensure = ui->minZ0->value();

    settings[1].maxPressure = ui->maxN1->value();
    settings[1].minPressure = ui->minN1->value();
    settings[1].maxTensure = ui->maxZ1->value();
    settings[1].minTensure = ui->minZ1->value();

    settings[2].maxPressure = ui->maxN2->value();
    settings[2].minPressure = ui->minN2->value();
    settings[2].maxTensure = ui->maxZ2->value();
    settings[2].minTensure = ui->minZ2->value();

    settings[3].maxPressure = ui->maxN3->value();
    settings[3].minPressure = ui->minN3->value();
    settings[3].maxTensure = ui->maxZ3->value();
    settings[3].minTensure = ui->minZ3->value();

    settings[4].maxPressure = ui->maxN4->value();
    settings[4].minPressure = ui->minN4->value();
    settings[4].maxTensure = ui->maxZ4->value();
    settings[4].minTensure = ui->minZ4->value();

    this->done(0);
}

void OpcjePomiarow::on_pushButton_2_released()
{
    this->done(1);
}
