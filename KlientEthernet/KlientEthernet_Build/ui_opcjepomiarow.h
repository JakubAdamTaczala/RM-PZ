/********************************************************************************
** Form generated from reading UI file 'opcjepomiarow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPCJEPOMIAROW_H
#define UI_OPCJEPOMIAROW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpcjePomiarow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpinBox *maxN2;
    QLabel *label_2;
    QSpinBox *maxN1;
    QLabel *p3L;
    QLabel *label;
    QLabel *n2L;
    QSpinBox *minN3;
    QSpinBox *minN2;
    QSpinBox *maxN3;
    QLabel *n4L;
    QSpinBox *minN4;
    QSpinBox *maxN4;
    QLabel *n1L;
    QSpinBox *minN1;
    QSpinBox *minN0;
    QSpinBox *maxN0;
    QLabel *n0L;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QSpinBox *maxZ3;
    QSpinBox *maxZ0;
    QSpinBox *minZ4;
    QSpinBox *maxZ1;
    QSpinBox *maxZ2;
    QSpinBox *maxZ4;
    QLabel *z2L;
    QLabel *z3L;
    QLabel *z4L;
    QLabel *z0L;
    QLabel *z1L;
    QSpinBox *minZ1;
    QSpinBox *minZ2;
    QSpinBox *minZ0;
    QSpinBox *minZ3;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *OpcjePomiarow)
    {
        if (OpcjePomiarow->objectName().isEmpty())
            OpcjePomiarow->setObjectName(QStringLiteral("OpcjePomiarow"));
        OpcjePomiarow->resize(660, 280);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        OpcjePomiarow->setPalette(palette);
        widget = new QWidget(OpcjePomiarow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(380, 220, 260, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(110, 30));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(110, 30));

        horizontalLayout->addWidget(pushButton);

        groupBox = new QGroupBox(OpcjePomiarow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 300, 200));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        maxN2 = new QSpinBox(groupBox);
        maxN2->setObjectName(QStringLiteral("maxN2"));
        maxN2->setMaximum(4096);
        maxN2->setValue(4096);

        gridLayout->addWidget(maxN2, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        maxN1 = new QSpinBox(groupBox);
        maxN1->setObjectName(QStringLiteral("maxN1"));
        maxN1->setMaximum(4096);
        maxN1->setValue(4096);

        gridLayout->addWidget(maxN1, 2, 2, 1, 1);

        p3L = new QLabel(groupBox);
        p3L->setObjectName(QStringLiteral("p3L"));

        gridLayout->addWidget(p3L, 4, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        n2L = new QLabel(groupBox);
        n2L->setObjectName(QStringLiteral("n2L"));

        gridLayout->addWidget(n2L, 3, 0, 1, 1);

        minN3 = new QSpinBox(groupBox);
        minN3->setObjectName(QStringLiteral("minN3"));
        minN3->setMaximum(4096);

        gridLayout->addWidget(minN3, 4, 1, 1, 1);

        minN2 = new QSpinBox(groupBox);
        minN2->setObjectName(QStringLiteral("minN2"));
        minN2->setMaximum(4096);

        gridLayout->addWidget(minN2, 3, 1, 1, 1);

        maxN3 = new QSpinBox(groupBox);
        maxN3->setObjectName(QStringLiteral("maxN3"));
        maxN3->setMaximum(4096);
        maxN3->setValue(4096);

        gridLayout->addWidget(maxN3, 4, 2, 1, 1);

        n4L = new QLabel(groupBox);
        n4L->setObjectName(QStringLiteral("n4L"));

        gridLayout->addWidget(n4L, 5, 0, 1, 1);

        minN4 = new QSpinBox(groupBox);
        minN4->setObjectName(QStringLiteral("minN4"));
        minN4->setMaximum(4096);

        gridLayout->addWidget(minN4, 5, 1, 1, 1);

        maxN4 = new QSpinBox(groupBox);
        maxN4->setObjectName(QStringLiteral("maxN4"));
        maxN4->setMaximum(4096);
        maxN4->setValue(4096);

        gridLayout->addWidget(maxN4, 5, 2, 1, 1);

        n1L = new QLabel(groupBox);
        n1L->setObjectName(QStringLiteral("n1L"));

        gridLayout->addWidget(n1L, 2, 0, 1, 1);

        minN1 = new QSpinBox(groupBox);
        minN1->setObjectName(QStringLiteral("minN1"));
        minN1->setMaximum(4096);

        gridLayout->addWidget(minN1, 2, 1, 1, 1);

        minN0 = new QSpinBox(groupBox);
        minN0->setObjectName(QStringLiteral("minN0"));
        minN0->setMaximum(4096);

        gridLayout->addWidget(minN0, 1, 1, 1, 1);

        maxN0 = new QSpinBox(groupBox);
        maxN0->setObjectName(QStringLiteral("maxN0"));
        maxN0->setMaximum(4096);
        maxN0->setValue(4096);

        gridLayout->addWidget(maxN0, 1, 2, 1, 1);

        n0L = new QLabel(groupBox);
        n0L->setObjectName(QStringLiteral("n0L"));

        gridLayout->addWidget(n0L, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(OpcjePomiarow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(340, 20, 300, 200));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        groupBox_3->setPalette(palette1);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        maxZ3 = new QSpinBox(groupBox_3);
        maxZ3->setObjectName(QStringLiteral("maxZ3"));
        maxZ3->setMaximum(4096);
        maxZ3->setValue(4096);

        gridLayout_2->addWidget(maxZ3, 4, 2, 1, 1);

        maxZ0 = new QSpinBox(groupBox_3);
        maxZ0->setObjectName(QStringLiteral("maxZ0"));
        maxZ0->setMaximum(4096);
        maxZ0->setValue(4096);

        gridLayout_2->addWidget(maxZ0, 1, 2, 1, 1);

        minZ4 = new QSpinBox(groupBox_3);
        minZ4->setObjectName(QStringLiteral("minZ4"));
        minZ4->setMaximum(4096);

        gridLayout_2->addWidget(minZ4, 5, 1, 1, 1);

        maxZ1 = new QSpinBox(groupBox_3);
        maxZ1->setObjectName(QStringLiteral("maxZ1"));
        maxZ1->setMaximum(4096);
        maxZ1->setValue(4096);

        gridLayout_2->addWidget(maxZ1, 2, 2, 1, 1);

        maxZ2 = new QSpinBox(groupBox_3);
        maxZ2->setObjectName(QStringLiteral("maxZ2"));
        maxZ2->setMaximum(4096);
        maxZ2->setValue(4096);

        gridLayout_2->addWidget(maxZ2, 3, 2, 1, 1);

        maxZ4 = new QSpinBox(groupBox_3);
        maxZ4->setObjectName(QStringLiteral("maxZ4"));
        maxZ4->setMaximum(4096);
        maxZ4->setValue(4096);

        gridLayout_2->addWidget(maxZ4, 5, 2, 1, 1);

        z2L = new QLabel(groupBox_3);
        z2L->setObjectName(QStringLiteral("z2L"));

        gridLayout_2->addWidget(z2L, 3, 0, 1, 1);

        z3L = new QLabel(groupBox_3);
        z3L->setObjectName(QStringLiteral("z3L"));

        gridLayout_2->addWidget(z3L, 4, 0, 1, 1);

        z4L = new QLabel(groupBox_3);
        z4L->setObjectName(QStringLiteral("z4L"));

        gridLayout_2->addWidget(z4L, 5, 0, 1, 1);

        z0L = new QLabel(groupBox_3);
        z0L->setObjectName(QStringLiteral("z0L"));

        gridLayout_2->addWidget(z0L, 1, 0, 1, 1);

        z1L = new QLabel(groupBox_3);
        z1L->setObjectName(QStringLiteral("z1L"));

        gridLayout_2->addWidget(z1L, 2, 0, 1, 1);

        minZ1 = new QSpinBox(groupBox_3);
        minZ1->setObjectName(QStringLiteral("minZ1"));
        minZ1->setMaximum(4096);

        gridLayout_2->addWidget(minZ1, 2, 1, 1, 1);

        minZ2 = new QSpinBox(groupBox_3);
        minZ2->setObjectName(QStringLiteral("minZ2"));
        minZ2->setMaximum(4096);

        gridLayout_2->addWidget(minZ2, 3, 1, 1, 1);

        minZ0 = new QSpinBox(groupBox_3);
        minZ0->setObjectName(QStringLiteral("minZ0"));
        minZ0->setMaximum(4096);

        gridLayout_2->addWidget(minZ0, 1, 1, 1, 1);

        minZ3 = new QSpinBox(groupBox_3);
        minZ3->setObjectName(QStringLiteral("minZ3"));
        minZ3->setMaximum(4096);

        gridLayout_2->addWidget(minZ3, 4, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);


        retranslateUi(OpcjePomiarow);

        QMetaObject::connectSlotsByName(OpcjePomiarow);
    } // setupUi

    void retranslateUi(QDialog *OpcjePomiarow)
    {
        OpcjePomiarow->setWindowTitle(QApplication::translate("OpcjePomiarow", "Dialog", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("OpcjePomiarow", "Anuluj", Q_NULLPTR));
        pushButton->setText(QApplication::translate("OpcjePomiarow", "Zachowaj", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("OpcjePomiarow", "Czujniki nacisku", Q_NULLPTR));
        label_2->setText(QApplication::translate("OpcjePomiarow", "max", Q_NULLPTR));
        p3L->setText(QApplication::translate("OpcjePomiarow", "Palec serdeczny", Q_NULLPTR));
        label->setText(QApplication::translate("OpcjePomiarow", "min", Q_NULLPTR));
        n2L->setText(QApplication::translate("OpcjePomiarow", "Palec \305\233rodkowy", Q_NULLPTR));
        n4L->setText(QApplication::translate("OpcjePomiarow", "Ma\305\202y palec", Q_NULLPTR));
        n1L->setText(QApplication::translate("OpcjePomiarow", "Palec wskazuj\304\205cy", Q_NULLPTR));
        n0L->setText(QApplication::translate("OpcjePomiarow", "Kciuk", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("OpcjePomiarow", "Czujniki zgiecia", Q_NULLPTR));
        z2L->setText(QApplication::translate("OpcjePomiarow", "Palec \305\233rodkowy", Q_NULLPTR));
        z3L->setText(QApplication::translate("OpcjePomiarow", "Palec serdeczny", Q_NULLPTR));
        z4L->setText(QApplication::translate("OpcjePomiarow", "Ma\305\202y palec", Q_NULLPTR));
        z0L->setText(QApplication::translate("OpcjePomiarow", "Kciuk", Q_NULLPTR));
        z1L->setText(QApplication::translate("OpcjePomiarow", "Palec wskazuj\304\205cy", Q_NULLPTR));
        label_3->setText(QApplication::translate("OpcjePomiarow", "min", Q_NULLPTR));
        label_4->setText(QApplication::translate("OpcjePomiarow", "max", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OpcjePomiarow: public Ui_OpcjePomiarow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPCJEPOMIAROW_H
