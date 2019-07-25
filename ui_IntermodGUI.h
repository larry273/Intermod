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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QPushButton *calculateButton;
    QGridLayout *gridLayout_3;
    QLabel *toleranceLabel;
    QLabel *cutoffLabel;
    QLineEdit *searchLine;
    QSpacerItem *horizontalSpacer;
    QLabel *searchWindowLabel;
    QComboBox *orderBox;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_2;
    QPushButton *helpButton;
    QPushButton *clearButton;
    QFrame *TitleBanner;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *titleLabel;
    QPushButton *minButton;
    QPushButton *maxButton;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *IntermodClass)
    {
        if (IntermodClass->objectName().isEmpty())
            IntermodClass->setObjectName(QString::fromUtf8("IntermodClass"));
        IntermodClass->resize(784, 617);
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
"QPushButton:hover:!pressed{\n"
"	background-color: #739bbe; \n"
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
"	width: 25;\n"
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
""
                        "\n"
"/*TABLE VIEW */\n"
"QTableView{\n"
"	border-radius: 8;\n"
"	background-color: #3f464d   ;\n"
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
"/*SCROLL BAR*/\n"
"QScrollBar:vertical {\n"
"     background:white;\n"
"     width: 10;\n"
"     margin: 0px 0 0px 0;\n"
"	 border-radius: 2;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background: #0D1218        ;\n"
"     min-height: 30px;\n"
"	border-radius: 2;\n"
" }\n"
"QScrollBar::add-line:vertical {\n"
"     background"
                        ": #0D1218  ;\n"
"     height: 0px;\n"
"     subcontrol-position: bottom;\n"
"     subcontrol-origin: margin;\n"
" }\n"
"\n"
" QScrollBar::sub-line:vertical {\n"
"     background: #0D1218  ;\n"
"     height: 0px;\n"
"     subcontrol-position: top;\n"
"     subcontrol-origin: margin;\n"
" }\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"     background: none;\n"
" }\n"
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
        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setMinimumSize(QSize(180, 50));

        gridLayout->addWidget(calculateButton, 6, 4, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toleranceLabel = new QLabel(centralWidget);
        toleranceLabel->setObjectName(QString::fromUtf8("toleranceLabel"));

        gridLayout_3->addWidget(toleranceLabel, 1, 4, 1, 1);

        cutoffLabel = new QLabel(centralWidget);
        cutoffLabel->setObjectName(QString::fromUtf8("cutoffLabel"));

        gridLayout_3->addWidget(cutoffLabel, 1, 5, 1, 1);

        searchLine = new QLineEdit(centralWidget);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        searchLine->setMinimumSize(QSize(0, 35));
        searchLine->setMaximumSize(QSize(150, 16777215));
        searchLine->setFrame(false);
        searchLine->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(searchLine, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        searchWindowLabel = new QLabel(centralWidget);
        searchWindowLabel->setObjectName(QString::fromUtf8("searchWindowLabel"));

        gridLayout_3->addWidget(searchWindowLabel, 1, 1, 1, 1);

        orderBox = new QComboBox(centralWidget);
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->addItem(QString());
        orderBox->setObjectName(QString::fromUtf8("orderBox"));
        orderBox->setMinimumSize(QSize(0, 35));
        orderBox->setFrame(false);

        gridLayout_3->addWidget(orderBox, 1, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 8, 1, 1);


        gridLayout->addLayout(gridLayout_3, 4, 0, 1, 5);

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

        gridLayout->addWidget(tableWidget, 2, 0, 1, 5);

        verticalSpacer_2 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(helpButton, 6, 0, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(clearButton, 6, 3, 1, 1);

        TitleBanner = new QFrame(centralWidget);
        TitleBanner->setObjectName(QString::fromUtf8("TitleBanner"));
        TitleBanner->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:#282c30;\n"
"	border-radius: 5px;\n"
"}"));
        TitleBanner->setFrameShape(QFrame::StyledPanel);
        TitleBanner->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(TitleBanner);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 8, -1, 8);
        horizontalSpacer_3 = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        titleLabel = new QLabel(TitleBanner);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("Font: Bold 18pt;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(titleLabel);

        minButton = new QPushButton(TitleBanner);
        minButton->setObjectName(QString::fromUtf8("minButton"));
        minButton->setMinimumSize(QSize(35, 35));
        minButton->setMaximumSize(QSize(35, 35));
        minButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: #577590; \n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
" background-color:#739bbe;\n"
"}"));

        horizontalLayout->addWidget(minButton);

        maxButton = new QPushButton(TitleBanner);
        maxButton->setObjectName(QString::fromUtf8("maxButton"));
        maxButton->setMinimumSize(QSize(35, 35));
        maxButton->setMaximumSize(QSize(35, 35));
        maxButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: #577590; \n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
" background-color:#739bbe;\n"
"}"));

        horizontalLayout->addWidget(maxButton);

        closeButton = new QPushButton(TitleBanner);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(35, 35));
        closeButton->setMaximumSize(QSize(35, 35));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: #577590; \n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
" background-color:#739bbe;\n"
"}"));

        horizontalLayout->addWidget(closeButton);


        gridLayout->addWidget(TitleBanner, 0, 0, 2, 5);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 2, 2);

        IntermodClass->setCentralWidget(centralWidget);

        retranslateUi(IntermodClass);

        QMetaObject::connectSlotsByName(IntermodClass);
    } // setupUi

    void retranslateUi(QMainWindow *IntermodClass)
    {
        IntermodClass->setWindowTitle(QCoreApplication::translate("IntermodClass", "RF Intermodulation Calculator", nullptr));
        actionSave->setText(QCoreApplication::translate("IntermodClass", "Save       Ctrl-S", nullptr));
        actionOpen->setText(QCoreApplication::translate("IntermodClass", "Open     Ctrl-O", nullptr));
        actionPrint->setText(QCoreApplication::translate("IntermodClass", "Print       Ctrl-P", nullptr));
#if QT_CONFIG(tooltip)
        calculateButton->setToolTip(QCoreApplication::translate("IntermodClass", "Run the intermodulation calculation", nullptr));
#endif // QT_CONFIG(tooltip)
        calculateButton->setText(QCoreApplication::translate("IntermodClass", "Calculate", nullptr));
        toleranceLabel->setText(QCoreApplication::translate("IntermodClass", "\302\261 kHz", nullptr));
        cutoffLabel->setText(QCoreApplication::translate("IntermodClass", "Calculation Cutoff:", nullptr));
#if QT_CONFIG(tooltip)
        searchLine->setToolTip(QCoreApplication::translate("IntermodClass", "Search window for hits", nullptr));
#endif // QT_CONFIG(tooltip)
        searchLine->setText(QCoreApplication::translate("IntermodClass", "500", nullptr));
        searchWindowLabel->setText(QCoreApplication::translate("IntermodClass", "Search Window:", nullptr));
        orderBox->setItemText(0, QCoreApplication::translate("IntermodClass", "3rd Order", nullptr));
        orderBox->setItemText(1, QCoreApplication::translate("IntermodClass", "5th Order", nullptr));
        orderBox->setItemText(2, QCoreApplication::translate("IntermodClass", "7th Order", nullptr));
        orderBox->setItemText(3, QCoreApplication::translate("IntermodClass", "9th Order", nullptr));
        orderBox->setItemText(4, QCoreApplication::translate("IntermodClass", "11th Order", nullptr));
        orderBox->setItemText(5, QCoreApplication::translate("IntermodClass", "13th Order", nullptr));
        orderBox->setItemText(6, QCoreApplication::translate("IntermodClass", "15th Order", nullptr));
        orderBox->setItemText(7, QCoreApplication::translate("IntermodClass", "17th Order", nullptr));
        orderBox->setItemText(8, QCoreApplication::translate("IntermodClass", "19th Order", nullptr));
        orderBox->setItemText(9, QCoreApplication::translate("IntermodClass", "21st Order", nullptr));
        orderBox->setItemText(10, QCoreApplication::translate("IntermodClass", "23rd Order", nullptr));
        orderBox->setItemText(11, QCoreApplication::translate("IntermodClass", "25th Order", nullptr));

#if QT_CONFIG(tooltip)
        orderBox->setToolTip(QCoreApplication::translate("IntermodClass", "Calculation order of results", nullptr));
#endif // QT_CONFIG(tooltip)
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
#if QT_CONFIG(tooltip)
        tableWidget->setToolTip(QCoreApplication::translate("IntermodClass", "Enter frequencies for the intermodulation calculation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        helpButton->setToolTip(QCoreApplication::translate("IntermodClass", "Help dialog", nullptr));
#endif // QT_CONFIG(tooltip)
        helpButton->setText(QCoreApplication::translate("IntermodClass", "Help", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("IntermodClass", "Clear table of input values", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("IntermodClass", "Clear", nullptr));
        titleLabel->setText(QCoreApplication::translate("IntermodClass", "RF Intermodulation Calculator", nullptr));
#if QT_CONFIG(tooltip)
        minButton->setToolTip(QCoreApplication::translate("IntermodClass", "Minimize", nullptr));
#endif // QT_CONFIG(tooltip)
        minButton->setText(QString());
#if QT_CONFIG(tooltip)
        maxButton->setToolTip(QCoreApplication::translate("IntermodClass", "Maximize", nullptr));
#endif // QT_CONFIG(tooltip)
        maxButton->setText(QString());
#if QT_CONFIG(tooltip)
        closeButton->setToolTip(QCoreApplication::translate("IntermodClass", "Exit", nullptr));
#endif // QT_CONFIG(tooltip)
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IntermodClass: public Ui_IntermodClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERMODGUI_H
