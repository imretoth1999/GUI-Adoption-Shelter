/********************************************************************************
** Form generated from reading UI file 'LAB_12_14.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB_12_14_H
#define UI_LAB_12_14_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LAB_12_14Class
{
public:
    QWidget *centralWidget;
    QTabWidget *myTab;
    QWidget *tab;
    QLabel *label;
    QPushButton *usergo;
    QPushButton *admingo;
    QWidget *tab_2;
    QPushButton *goback;
    QListWidget *listaadmin;
    QPushButton *deleteDog;
    QPushButton *adaugafra;
    QPushButton *updateDog;
    QLineEdit *Name;
    QLineEdit *Breed;
    QLineEdit *Link;
    QSpinBox *Age;
    QSpinBox *Weight;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *Error;
    QComboBox *comboBox;
    QWidget *tab_3;
    QListWidget *listaadopt;
    QPushButton *goback_2;
    QListWidget *Adopt;
    QPushButton *get;
    QPushButton *next;
    QLineEdit *minw;
    QSpinBox *Ag;
    QPushButton *filter;
    QPushButton *gow;
    QPushButton *HTML;
    QPushButton *CSV;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LAB_12_14Class)
    {
        if (LAB_12_14Class->objectName().isEmpty())
            LAB_12_14Class->setObjectName(QStringLiteral("LAB_12_14Class"));
        LAB_12_14Class->resize(600, 418);
        centralWidget = new QWidget(LAB_12_14Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        myTab = new QTabWidget(centralWidget);
        myTab->setObjectName(QStringLiteral("myTab"));
        myTab->setGeometry(QRect(0, -20, 611, 381));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 50, 301, 71));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        usergo = new QPushButton(tab);
        usergo->setObjectName(QStringLiteral("usergo"));
        usergo->setGeometry(QRect(120, 170, 101, 51));
        admingo = new QPushButton(tab);
        admingo->setObjectName(QStringLiteral("admingo"));
        admingo->setGeometry(QRect(300, 170, 121, 41));
        myTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        goback = new QPushButton(tab_2);
        goback->setObjectName(QStringLiteral("goback"));
        goback->setGeometry(QRect(30, 20, 75, 23));
        listaadmin = new QListWidget(tab_2);
        listaadmin->setObjectName(QStringLiteral("listaadmin"));
        listaadmin->setGeometry(QRect(10, 40, 341, 192));
        deleteDog = new QPushButton(tab_2);
        deleteDog->setObjectName(QStringLiteral("deleteDog"));
        deleteDog->setGeometry(QRect(390, 50, 141, 41));
        adaugafra = new QPushButton(tab_2);
        adaugafra->setObjectName(QStringLiteral("adaugafra"));
        adaugafra->setGeometry(QRect(390, 110, 141, 51));
        updateDog = new QPushButton(tab_2);
        updateDog->setObjectName(QStringLiteral("updateDog"));
        updateDog->setGeometry(QRect(390, 170, 141, 61));
        Name = new QLineEdit(tab_2);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(50, 240, 171, 20));
        Breed = new QLineEdit(tab_2);
        Breed->setObjectName(QStringLiteral("Breed"));
        Breed->setGeometry(QRect(50, 260, 171, 20));
        Link = new QLineEdit(tab_2);
        Link->setObjectName(QStringLiteral("Link"));
        Link->setGeometry(QRect(50, 320, 291, 20));
        Age = new QSpinBox(tab_2);
        Age->setObjectName(QStringLiteral("Age"));
        Age->setGeometry(QRect(50, 280, 42, 22));
        Weight = new QSpinBox(tab_2);
        Weight->setObjectName(QStringLiteral("Weight"));
        Weight->setGeometry(QRect(50, 300, 42, 22));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 240, 47, 13));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 260, 47, 13));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 280, 47, 13));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 300, 47, 13));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 320, 47, 13));
        Error = new QLabel(tab_2);
        Error->setObjectName(QStringLiteral("Error"));
        Error->setGeometry(QRect(30, 360, 481, 16));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 20, 69, 22));
        myTab->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        listaadopt = new QListWidget(tab_3);
        listaadopt->setObjectName(QStringLiteral("listaadopt"));
        listaadopt->setGeometry(QRect(10, 40, 256, 192));
        goback_2 = new QPushButton(tab_3);
        goback_2->setObjectName(QStringLiteral("goback_2"));
        goback_2->setGeometry(QRect(10, 10, 75, 23));
        Adopt = new QListWidget(tab_3);
        Adopt->setObjectName(QStringLiteral("Adopt"));
        Adopt->setGeometry(QRect(310, 40, 231, 31));
        get = new QPushButton(tab_3);
        get->setObjectName(QStringLiteral("get"));
        get->setGeometry(QRect(320, 100, 75, 23));
        next = new QPushButton(tab_3);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(450, 100, 75, 23));
        minw = new QLineEdit(tab_3);
        minw->setObjectName(QStringLiteral("minw"));
        minw->setGeometry(QRect(10, 240, 113, 20));
        Ag = new QSpinBox(tab_3);
        Ag->setObjectName(QStringLiteral("Ag"));
        Ag->setGeometry(QRect(140, 240, 42, 22));
        filter = new QPushButton(tab_3);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(10, 270, 75, 23));
        gow = new QPushButton(tab_3);
        gow->setObjectName(QStringLiteral("gow"));
        gow->setGeometry(QRect(120, 270, 111, 23));
        HTML = new QPushButton(tab_3);
        HTML->setObjectName(QStringLiteral("HTML"));
        HTML->setGeometry(QRect(270, 210, 151, 111));
        CSV = new QPushButton(tab_3);
        CSV->setObjectName(QStringLiteral("CSV"));
        CSV->setGeometry(QRect(450, 210, 131, 111));
        myTab->addTab(tab_3, QString());
        LAB_12_14Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LAB_12_14Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        LAB_12_14Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LAB_12_14Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LAB_12_14Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LAB_12_14Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LAB_12_14Class->setStatusBar(statusBar);

        retranslateUi(LAB_12_14Class);

        myTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LAB_12_14Class);
    } // setupUi

    void retranslateUi(QMainWindow *LAB_12_14Class)
    {
        LAB_12_14Class->setWindowTitle(QApplication::translate("LAB_12_14Class", "LAB_12_14", nullptr));
        label->setText(QApplication::translate("LAB_12_14Class", "What are you?", nullptr));
        usergo->setText(QApplication::translate("LAB_12_14Class", "ADMIN", nullptr));
        admingo->setText(QApplication::translate("LAB_12_14Class", "USER", nullptr));
        myTab->setTabText(myTab->indexOf(tab), QApplication::translate("LAB_12_14Class", "Tab 1", nullptr));
        goback->setText(QApplication::translate("LAB_12_14Class", "Goback", nullptr));
        deleteDog->setText(QApplication::translate("LAB_12_14Class", "Delete a dog", nullptr));
        adaugafra->setText(QApplication::translate("LAB_12_14Class", "Add dog", nullptr));
        updateDog->setText(QApplication::translate("LAB_12_14Class", "Update Dog", nullptr));
        label_2->setText(QApplication::translate("LAB_12_14Class", "Name", nullptr));
        label_3->setText(QApplication::translate("LAB_12_14Class", "Breed", nullptr));
        label_4->setText(QApplication::translate("LAB_12_14Class", "Age", nullptr));
        label_5->setText(QApplication::translate("LAB_12_14Class", "Weight", nullptr));
        label_6->setText(QApplication::translate("LAB_12_14Class", "link", nullptr));
        Error->setText(QString());
        comboBox->setItemText(0, QApplication::translate("LAB_12_14Class", "Detailed", nullptr));
        comboBox->setItemText(1, QApplication::translate("LAB_12_14Class", "Short", nullptr));

        myTab->setTabText(myTab->indexOf(tab_2), QApplication::translate("LAB_12_14Class", "Tab 2", nullptr));
        goback_2->setText(QApplication::translate("LAB_12_14Class", "Goback", nullptr));
        get->setText(QApplication::translate("LAB_12_14Class", "Adopt", nullptr));
        next->setText(QApplication::translate("LAB_12_14Class", "Next", nullptr));
        filter->setText(QApplication::translate("LAB_12_14Class", "Filter", nullptr));
        gow->setText(QApplication::translate("LAB_12_14Class", "Return to adoption", nullptr));
        HTML->setText(QApplication::translate("LAB_12_14Class", "HTML", nullptr));
        CSV->setText(QApplication::translate("LAB_12_14Class", "CSV", nullptr));
        myTab->setTabText(myTab->indexOf(tab_3), QApplication::translate("LAB_12_14Class", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LAB_12_14Class: public Ui_LAB_12_14Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB_12_14_H
