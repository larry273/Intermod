/********************************************************************************
** Form generated from reading UI file 'IntermodGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERMODGUI_H
#define UI_INTERMODGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntermodClass
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionPrint;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QLineEdit *searchLine;
    QLabel *searchWindowLabel;
    QComboBox *orderBox;
    QLabel *cutoffLabel;
    QLabel *toleranceLabel;
    QTableWidget *tableWidget;
    QPushButton *calculateButton;
    QPushButton *clearButton;
    QPushButton *helpButton;
    QLabel *titleLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *IntermodClass)
    {
        if (IntermodClass->objectName().isEmpty())
            IntermodClass->setObjectName(QString::fromUtf8("IntermodClass"));
        IntermodClass->resize(836, 664);
        IntermodClass->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{\n"
"	background-color: #5a5c5e;\n"
"}\n"
"\n"
"QLabel{\n"
"	Font: 14pt \"Arial\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton{\n"
"	font: 14pt \"Arial\";\n"
"	color: white;\n"
"	background-color: #282c30;\n"
"	border-radius: 5px;\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: #577590; \n"
"}\n"
"\n"
"QLineEdit{\n"
"	font: 14pt \"Arial\";\n"
"	background-color: #282c30;\n"
"	border-radius: 5px;\n"
"	color: white;\n"
"	padding-left: 10;\n"
"}\n"
"\n"
"QComboBox{\n"
"	font: 14pt \"Arial\";\n"
"	color: white;\n"
"	background-color: #282c30;\n"
"	border-radius: 5px;\n"
"	padding-left: 30px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	width: 20;\n"
"}\n"
"\n"
"QMessageBox {\n"
"	background-color: #0D1218;\n"
"	Font: 14pt \"Arial\";\n"
"}\n"
"QMessageBox QPushButton {\n"
"	font: 14pt \"Arial\";\n"
"	color: white;\n"
"	background-color: #1e2733    ;\n"
"	border-radius: 5px;\n"
"	height: 40;\n"
"	width: 100;\n"
"}\n"
"\n"
"/*TABLE VIEW */\n"
"QTableView{\n"
"	border-radius: 8;\n"
"	backgr"
                        "ound-color: #3f464d   ;\n"
"	Font: 14pt;\n"
"	color: white;\n"
"	gridline-color: #1C2321;\n"
"}\n"
"\n"
"QTableView:item:selected:focus {background-color: #577590 ;}\n"
"QTableView:item:selected {background-color: #577590 ;}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"	border-top-left-radius: 8;\n"
"	background-color: #5F6366;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background-color: #282c30   ;\n"
"	color: white;\n"
"	font: Bold 14pt;\n"
"	padding: 5;\n"
"	padding-left: 4px;\n"
"	border: 1px solid #6c6c6c;\n"
"}\n"
"QHeaderView::section:checked\n"
"{\n"
"	background-color:#0D1218   ;\n"
"}\n"
"\n"
""));
        actionSave = new QAction(IntermodClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen = new QAction(IntermodClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionPrint = new QAction(IntermodClass);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        centralWidget = new QWidget(IntermodClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        searchLine = new QLineEdit(centralWidget);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        searchLine->setMinimumSize(QSize(0, 35));
        searchLine->setMaximumSize(QSize(150, 16777215));
        searchLine->setFrame(false);
        searchLine->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(searchLine, 1, 1, 1, 1);

        searchWindowLabel = new QLabel(centralWidget);
        searchWindowLabel->setObjectName(QString::fromUtf8("searchWindowLabel"));
        searchWindowLabel->setMinimumSize(QSize(160, 0));
        searchWindowLabel->setMaximumSize(QSize(160, 16777215));

        gridLayout_3->addWidget(searchWindowLabel, 1, 0, 1, 1);

        orderBox = new QComboBox(centralWidget);
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->setObjectName(QString::fromUtf8("orderBox"));
        orderBox->setMinimumSize(QSize(0, 35));
        orderBox->setFrame(false);

        gridLayout_3->addWidget(orderBox, 2, 1, 1, 1);

        cutoffLabel = new QLabel(centralWidget);
        cutoffLabel->setObjectName(QString::fromUtf8("cutoffLabel"));
        cutoffLabel->setMinimumSize(QSize(160, 0));

        gridLayout_3->addWidget(cutoffLabel, 2, 0, 1, 1);

        toleranceLabel = new QLabel(centralWidget);
        toleranceLabel->setObjectName(QString::fromUtf8("toleranceLabel"));

        gridLayout_3->addWidget(toleranceLabel, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_3, 3, 0, 1, 5);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 350));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->horizontalHeader()->setDefaultSectionSize(225);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(45);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 6);

        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setMinimumSize(QSize(180, 60));

        gridLayout->addWidget(calculateButton, 4, 5, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(150, 60));

        gridLayout->addWidget(clearButton, 4, 4, 1, 1);

        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(helpButton, 4, 0, 1, 1);

        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("Font: Bold 18pt;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 6);


        gridLayout_2->addLayout(gridLayout, 2, 0, 2, 2);

        IntermodClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IntermodClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 836, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        IntermodClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionPrint);

        retranslateUi(IntermodClass);

        QMetaObject::connectSlotsByName(IntermodClass);
    } // setupUi

    void retranslateUi(QMainWindow *IntermodClass)
    {
        IntermodClass->setWindowTitle(QCoreApplication::translate("IntermodClass", "RF Intermodulation Calculator", nullptr));
        actionSave->setText(QCoreApplication::translate("IntermodClass", "Save       Ctrl-S", nullptr));
        actionOpen->setText(QCoreApplication::translate("IntermodClass", "Open     Ctrl-O", nullptr));
        actionPrint->setText(QCoreApplication::translate("IntermodClass", "Print       Ctrl-P", nullptr));
        searchLine->setText(QCoreApplication::translate("IntermodClass", "500", nullptr));
        searchWindowLabel->setText(QCoreApplication::translate("IntermodClass", "Search Window:", nullptr));
        orderBox->setItemText(0, QCoreApplication::translate("IntermodClass", "3rd Order", nullptr));
        orderBox->setItemText(1, QCoreApplication::translate("IntermodClass", "5th Order", nullptr));
        orderBox->setItemText(2, QCoreApplication::translate("IntermodClass", "7th Order", nullptr));
        orderBox->setItemText(3, QCoreApplication::translate("IntermodClass", "9th Order", nullptr));
        orderBox->setItemText(4, QCoreApplication::translate("IntermodClass", "11th Order", nullptr));

        cutoffLabel->setText(QCoreApplication::translate("IntermodClass", "Calculation Cutoff:", nullptr));
        toleranceLabel->setText(QCoreApplication::translate("IntermodClass", "\302\261 kHz", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("IntermodClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("IntermodClass", "Transmit Freq (MHz)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("IntermodClass", "Recieve Freq (MHz)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("IntermodClass", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("IntermodClass", "New Row", nullptr));
        calculateButton->setText(QCoreApplication::translate("IntermodClass", "Calculate", nullptr));
        clearButton->setText(QCoreApplication::translate("IntermodClass", "Clear", nullptr));
        helpButton->setText(QCoreApplication::translate("IntermodClass", "Help", nullptr));
        titleLabel->setText(QCoreApplication::translate("IntermodClass", "RF Intermodulation Calculator", nullptr));
        menuFile->setTitle(QCoreApplication::translate("IntermodClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntermodClass: public Ui_IntermodClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERMODGUI_H
