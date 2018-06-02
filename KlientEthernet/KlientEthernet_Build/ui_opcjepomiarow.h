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
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpinBox *minN3;
    QLabel *p3L;
    QLabel *n0L;
    QLabel *n4L;
    QLabel *n2L;
    QLabel *n1L;
    QSpinBox *minN2;
    QSpinBox *minN0;
    QSpinBox *minN1;
    QSpinBox *minN4;
    QSpinBox *maxN0;
    QSpinBox *maxN1;
    QSpinBox *maxN2;
    QSpinBox *maxN3;
    QSpinBox *maxN4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QSpinBox *minZ3;
    QLabel *z3L;
    QLabel *z0L;
    QLabel *z4L;
    QLabel *z2L;
    QLabel *z1L;
    QSpinBox *minZ2;
    QSpinBox *minZ0;
    QSpinBox *minZ1;
    QSpinBox *minZ4;
    QSpinBox *maxZ0;
    QSpinBox *maxZ1;
    QSpinBox *maxZ2;
    QSpinBox *maxZ3;
    QSpinBox *maxZ4;

    void setupUi(QDialog *OpcjePomiarow)
    {
        if (OpcjePomiarow->objectName().isEmpty())
            OpcjePomiarow->setObjectName(QStringLiteral("OpcjePomiarow"));
        OpcjePomiarow->resize(742, 483);
        widget = new QWidget(OpcjePomiarow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(470, 410, 240, 30));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 110, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(110, 30));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 0, 110, 30));
        pushButton->setMinimumSize(QSize(110, 30));
        groupBox = new QGroupBox(OpcjePomiarow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 70, 261, 221));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        minN3 = new QSpinBox(groupBox);
        minN3->setObjectName(QStringLiteral("minN3"));
        minN3->setMaximum(4096);

        gridLayout->addWidget(minN3, 3, 1, 1, 1);

        p3L = new QLabel(groupBox);
        p3L->setObjectName(QStringLiteral("p3L"));

        gridLayout->addWidget(p3L, 3, 0, 1, 1);

        n0L = new QLabel(groupBox);
        n0L->setObjectName(QStringLiteral("n0L"));

        gridLayout->addWidget(n0L, 0, 0, 1, 1);

        n4L = new QLabel(groupBox);
        n4L->setObjectName(QStringLiteral("n4L"));

        gridLayout->addWidget(n4L, 4, 0, 1, 1);

        n2L = new QLabel(groupBox);
        n2L->setObjectName(QStringLiteral("n2L"));

        gridLayout->addWidget(n2L, 2, 0, 1, 1);

        n1L = new QLabel(groupBox);
        n1L->setObjectName(QStringLiteral("n1L"));

        gridLayout->addWidget(n1L, 1, 0, 1, 1);

        minN2 = new QSpinBox(groupBox);
        minN2->setObjectName(QStringLiteral("minN2"));
        minN2->setMaximum(4096);

        gridLayout->addWidget(minN2, 2, 1, 1, 1);

        minN0 = new QSpinBox(groupBox);
        minN0->setObjectName(QStringLiteral("minN0"));
        minN0->setMaximum(4096);

        gridLayout->addWidget(minN0, 0, 1, 1, 1);

        minN1 = new QSpinBox(groupBox);
        minN1->setObjectName(QStringLiteral("minN1"));
        minN1->setMaximum(4096);

        gridLayout->addWidget(minN1, 1, 1, 1, 1);

        minN4 = new QSpinBox(groupBox);
        minN4->setObjectName(QStringLiteral("minN4"));
        minN4->setMaximum(4096);

        gridLayout->addWidget(minN4, 4, 1, 1, 1);

        maxN0 = new QSpinBox(groupBox);
        maxN0->setObjectName(QStringLiteral("maxN0"));
        maxN0->setMaximum(4096);

        gridLayout->addWidget(maxN0, 0, 2, 1, 1);

        maxN1 = new QSpinBox(groupBox);
        maxN1->setObjectName(QStringLiteral("maxN1"));
        maxN1->setMaximum(4096);

        gridLayout->addWidget(maxN1, 1, 2, 1, 1);

        maxN2 = new QSpinBox(groupBox);
        maxN2->setObjectName(QStringLiteral("maxN2"));
        maxN2->setMaximum(4096);

        gridLayout->addWidget(maxN2, 2, 2, 1, 1);

        maxN3 = new QSpinBox(groupBox);
        maxN3->setObjectName(QStringLiteral("maxN3"));
        maxN3->setMaximum(4096);

        gridLayout->addWidget(maxN3, 3, 2, 1, 1);

        maxN4 = new QSpinBox(groupBox);
        maxN4->setObjectName(QStringLiteral("maxN4"));
        maxN4->setMaximum(4096);

        gridLayout->addWidget(maxN4, 4, 2, 1, 1);

        groupBox_3 = new QGroupBox(OpcjePomiarow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 70, 261, 221));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        minZ3 = new QSpinBox(groupBox_3);
        minZ3->setObjectName(QStringLiteral("minZ3"));
        minZ3->setMaximum(4096);

        gridLayout_2->addWidget(minZ3, 3, 1, 1, 1);

        z3L = new QLabel(groupBox_3);
        z3L->setObjectName(QStringLiteral("z3L"));

        gridLayout_2->addWidget(z3L, 3, 0, 1, 1);

        z0L = new QLabel(groupBox_3);
        z0L->setObjectName(QStringLiteral("z0L"));

        gridLayout_2->addWidget(z0L, 0, 0, 1, 1);

        z4L = new QLabel(groupBox_3);
        z4L->setObjectName(QStringLiteral("z4L"));

        gridLayout_2->addWidget(z4L, 4, 0, 1, 1);

        z2L = new QLabel(groupBox_3);
        z2L->setObjectName(QStringLiteral("z2L"));

        gridLayout_2->addWidget(z2L, 2, 0, 1, 1);

        z1L = new QLabel(groupBox_3);
        z1L->setObjectName(QStringLiteral("z1L"));

        gridLayout_2->addWidget(z1L, 1, 0, 1, 1);

        minZ2 = new QSpinBox(groupBox_3);
        minZ2->setObjectName(QStringLiteral("minZ2"));
        minZ2->setMaximum(4096);

        gridLayout_2->addWidget(minZ2, 2, 1, 1, 1);

        minZ0 = new QSpinBox(groupBox_3);
        minZ0->setObjectName(QStringLiteral("minZ0"));
        minZ0->setMaximum(4096);

        gridLayout_2->addWidget(minZ0, 0, 1, 1, 1);

        minZ1 = new QSpinBox(groupBox_3);
        minZ1->setObjectName(QStringLiteral("minZ1"));
        minZ1->setMaximum(4096);

        gridLayout_2->addWidget(minZ1, 1, 1, 1, 1);

        minZ4 = new QSpinBox(groupBox_3);
        minZ4->setObjectName(QStringLiteral("minZ4"));
        minZ4->setMaximum(4096);

        gridLayout_2->addWidget(minZ4, 4, 1, 1, 1);

        maxZ0 = new QSpinBox(groupBox_3);
        maxZ0->setObjectName(QStringLiteral("maxZ0"));
        maxZ0->setMaximum(4096);

        gridLayout_2->addWidget(maxZ0, 0, 2, 1, 1);

        maxZ1 = new QSpinBox(groupBox_3);
        maxZ1->setObjectName(QStringLiteral("maxZ1"));
        maxZ1->setMaximum(4096);

        gridLayout_2->addWidget(maxZ1, 1, 2, 1, 1);

        maxZ2 = new QSpinBox(groupBox_3);
        maxZ2->setObjectName(QStringLiteral("maxZ2"));
        maxZ2->setMaximum(4096);

        gridLayout_2->addWidget(maxZ2, 2, 2, 1, 1);

        maxZ3 = new QSpinBox(groupBox_3);
        maxZ3->setObjectName(QStringLiteral("maxZ3"));
        maxZ3->setMaximum(4096);

        gridLayout_2->addWidget(maxZ3, 3, 2, 1, 1);

        maxZ4 = new QSpinBox(groupBox_3);
        maxZ4->setObjectName(QStringLiteral("maxZ4"));
        maxZ4->setMaximum(4096);

        gridLayout_2->addWidget(maxZ4, 4, 2, 1, 1);


        retranslateUi(OpcjePomiarow);

        QMetaObject::connectSlotsByName(OpcjePomiarow);
    } // setupUi

    void retranslateUi(QDialog *OpcjePomiarow)
    {
        OpcjePomiarow->setWindowTitle(QApplication::translate("OpcjePomiarow", "Dialog", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("OpcjePomiarow", "Anuluj", Q_NULLPTR));
        pushButton->setText(QApplication::translate("OpcjePomiarow", "Zachowaj", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("OpcjePomiarow", "Czujniki nacisku", Q_NULLPTR));
        p3L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        n0L->setText(QApplication::translate("OpcjePomiarow", "Palec 0", Q_NULLPTR));
        n4L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        n2L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        n1L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("OpcjePomiarow", "Czujniki zgiecia", Q_NULLPTR));
        z3L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        z0L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        z4L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        z2L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
        z1L->setText(QApplication::translate("OpcjePomiarow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OpcjePomiarow: public Ui_OpcjePomiarow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPCJEPOMIAROW_H
