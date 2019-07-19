/********************************************************************************
** Form generated from reading UI file 'OutputClass.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTCLASS_H
#define UI_OUTPUTCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *htmlView;
    QPushButton *printButton;
    QPushButton *saveButton;
    QPushButton *closeButton;

    void setupUi(QWidget *OutputClass)
    {
        if (OutputClass->objectName().isEmpty())
            OutputClass->setObjectName(QString::fromUtf8("OutputClass"));
        OutputClass->resize(700, 768);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OutputClass->sizePolicy().hasHeightForWidth());
        OutputClass->setSizePolicy(sizePolicy);
        OutputClass->setStyleSheet(QString::fromUtf8("QWidget#OutputClass{\n"
"	background-color: #5a5c5e   ;\n"
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
"	background-color: #282c30    ;\n"
"	border-radius: 5px;\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: #577590; \n"
"}\n"
"\n"
"QLineEdit{\n"
"	font: 14pt \"Arial\";\n"
"	background-color: #282c30    ;\n"
"	border-radius: 5px;\n"
"	color: white;\n"
"	padding-left: 10;\n"
"}\n"
"\n"
"QComboBox{\n"
"	font: 14pt \"Arial\";\n"
"	color: white;\n"
"	background-color: #282c30    ;\n"
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
"	border-radius: 8"
                        ";\n"
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
""));
        gridLayout = new QGridLayout(OutputClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(311, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        htmlView = new QTextBrowser(OutputClass);
        htmlView->setObjectName(QString::fromUtf8("htmlView"));
        htmlView->setFrameShape(QFrame::NoFrame);
        htmlView->setFrameShadow(QFrame::Plain);
        htmlView->setLineWidth(0);
        htmlView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(htmlView, 0, 0, 1, 4);

        printButton = new QPushButton(OutputClass);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setMinimumSize(QSize(100, 60));

        gridLayout->addWidget(printButton, 1, 0, 1, 1);

        saveButton = new QPushButton(OutputClass);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(100, 60));

        gridLayout->addWidget(saveButton, 1, 1, 1, 1);

        closeButton = new QPushButton(OutputClass);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(150, 60));

        gridLayout->addWidget(closeButton, 1, 3, 1, 1);


        retranslateUi(OutputClass);

        QMetaObject::connectSlotsByName(OutputClass);
    } // setupUi

    void retranslateUi(QWidget *OutputClass)
    {
        OutputClass->setWindowTitle(QCoreApplication::translate("OutputClass", "RF Intermodulation Output", nullptr));
        printButton->setText(QCoreApplication::translate("OutputClass", "Print", nullptr));
        saveButton->setText(QCoreApplication::translate("OutputClass", "Save", nullptr));
        closeButton->setText(QCoreApplication::translate("OutputClass", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputClass: public Ui_OutputClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTCLASS_H
