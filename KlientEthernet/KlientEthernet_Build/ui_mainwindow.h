/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "rotate.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionZapisz_pomiary;
    QAction *actionUstawienia_pomiar_w;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBara;
    QProgressBar *progressBarb;
    QProgressBar *progressBarc;
    QProgressBar *progressBard;
    QProgressBar *progressBare;
    QProgressBar *progressBarf;
    QProgressBar *progressBarg;
    QProgressBar *progressBarh;
    QProgressBar *progressBari;
    QProgressBar *progressBarj;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    rotate *label_9;
    rotate *label;
    rotate *label_5;
    rotate *label_8;
    rotate *label_2;
    rotate *label_6;
    rotate *label_3;
    rotate *label_10;
    rotate *label_4;
    rotate *label_7;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuOpcje;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1826, 612);
        actionZapisz_pomiary = new QAction(MainWindow);
        actionZapisz_pomiary->setObjectName(QStringLiteral("actionZapisz_pomiary"));
        actionUstawienia_pomiar_w = new QAction(MainWindow);
        actionUstawienia_pomiar_w->setObjectName(QStringLiteral("actionUstawienia_pomiar_w"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        progressBara = new QProgressBar(widget);
        progressBara->setObjectName(QStringLiteral("progressBara"));
        progressBara->setMinimum(0);
        progressBara->setMaximum(4096);
        progressBara->setValue(0);
        progressBara->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBara);

        progressBarb = new QProgressBar(widget);
        progressBarb->setObjectName(QStringLiteral("progressBarb"));
        progressBarb->setMaximum(2100);
        progressBarb->setValue(0);
        progressBarb->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBarb);

        progressBarc = new QProgressBar(widget);
        progressBarc->setObjectName(QStringLiteral("progressBarc"));
        progressBarc->setMinimum(0);
        progressBarc->setMaximum(4096);
        progressBarc->setValue(0);
        progressBarc->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBarc);

        progressBard = new QProgressBar(widget);
        progressBard->setObjectName(QStringLiteral("progressBard"));
        progressBard->setMaximum(2100);
        progressBard->setValue(0);
        progressBard->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBard);

        progressBare = new QProgressBar(widget);
        progressBare->setObjectName(QStringLiteral("progressBare"));
        progressBare->setMaximum(4096);
        progressBare->setValue(0);
        progressBare->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBare);

        progressBarf = new QProgressBar(widget);
        progressBarf->setObjectName(QStringLiteral("progressBarf"));
        progressBarf->setMinimum(0);
        progressBarf->setMaximum(2100);
        progressBarf->setValue(0);
        progressBarf->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBarf);

        progressBarg = new QProgressBar(widget);
        progressBarg->setObjectName(QStringLiteral("progressBarg"));
        progressBarg->setMaximum(4096);
        progressBarg->setValue(0);
        progressBarg->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBarg);

        progressBarh = new QProgressBar(widget);
        progressBarh->setObjectName(QStringLiteral("progressBarh"));
        progressBarh->setMinimum(0);
        progressBarh->setMaximum(2100);
        progressBarh->setValue(0);
        progressBarh->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBarh);

        progressBari = new QProgressBar(widget);
        progressBari->setObjectName(QStringLiteral("progressBari"));
        progressBari->setMaximum(4096);
        progressBari->setValue(0);
        progressBari->setTextVisible(true);
        progressBari->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBari);

        progressBarj = new QProgressBar(widget);
        progressBarj->setObjectName(QStringLiteral("progressBarj"));
        progressBarj->setMaximum(2100);
        progressBarj->setValue(0);
        progressBarj->setTextVisible(true);
        progressBarj->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(progressBarj);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new rotate(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_9);

        label = new rotate(widget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        label_5 = new rotate(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        label_8 = new rotate(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_8);

        label_2 = new rotate(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        label_6 = new rotate(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        label_3 = new rotate(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        label_10 = new rotate(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10->setWordWrap(false);

        horizontalLayout_2->addWidget(label_10);

        label_4 = new rotate(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        label_7 = new rotate(widget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);


        verticalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1826, 26));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        menuOpcje = new QMenu(menuBar);
        menuOpcje->setObjectName(QStringLiteral("menuOpcje"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuOpcje->menuAction());
        menuPlik->addAction(actionZapisz_pomiary);
        menuOpcje->addAction(actionUstawienia_pomiar_w);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionZapisz_pomiary->setText(QApplication::translate("MainWindow", "Zapisz pomiary", Q_NULLPTR));
        actionUstawienia_pomiar_w->setText(QApplication::translate("MainWindow", "Ustawienia pomiar\303\263w", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Kciuk - Czujnik nacisku", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Kciuk - Czujnik zgi\304\231cia", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Palec wskazuj\304\205cy - Czujnik nacisku", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Palec wskazuj\304\205cy - Czujnik zgi\304\231cia", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Palec \305\233rodkowy - Czujnik nacisku", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Palec \305\233rodkowy - Czujnik zgi\304\231cia", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Palec serdeczny - Czujnik nacisku", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Palec serdeczny - Czujnik zgi\304\231cia", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Ma\305\202y palec - Czujnik nacisku", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Ma\305\202y palec - czujnik zgi\304\231cia", Q_NULLPTR));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", Q_NULLPTR));
        menuOpcje->setTitle(QApplication::translate("MainWindow", "Opcje", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
