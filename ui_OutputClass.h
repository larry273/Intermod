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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputClass
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *htmlView;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *printButton;
    QPushButton *emailButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *OutputClass)
    {
        if (OutputClass->objectName().isEmpty())
            OutputClass->setObjectName(QString::fromUtf8("OutputClass"));
        OutputClass->resize(698, 869);
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
"QPushButton:hover:!pressed{\n"
"	background-color: #739bbe; \n"
"}\n"
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
""
                        "}\n"
"\n"
"QDialog {\n"
"	background-color: #0D1218;\n"
"	Font: 14pt \"Arial\";\n"
"}\n"
"QDialog QPushButton {\n"
"	font: 14pt \"Arial\";\n"
"	color: white;\n"
"	background-color: #1e2733    ;\n"
"	border-radius: 5px;\n"
"	height: 40;\n"
"	width: 100;\n"
"	margin-bottom: 10px;\n"
"}\n"
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
""
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
"     background: #0D1218  ;\n"
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
        gridLayout = new QGridLayout(OutputClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        htmlView = new QTextBrowser(OutputClass);
        htmlView->setObjectName(QString::fromUtf8("htmlView"));
        htmlView->setFrameShape(QFrame::NoFrame);
        htmlView->setFrameShadow(QFrame::Plain);
        htmlView->setLineWidth(0);
        htmlView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(htmlView, 2, 0, 1, 6);

        frame_2 = new QFrame(OutputClass);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:#3f464d;\n"
"	border-radius: 5px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(frame_2, 4, 0, 1, 6);

        frame = new QFrame(OutputClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:#3f464d;\n"
"	border-radius: 5px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        saveButton = new QPushButton(frame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(saveButton);

        printButton = new QPushButton(frame);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(printButton);

        emailButton = new QPushButton(frame);
        emailButton->setObjectName(QString::fromUtf8("emailButton"));
        emailButton->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(emailButton);

        horizontalSpacer_2 = new QSpacerItem(409, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        closeButton = new QPushButton(frame);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(255, 255, 255,0);\n"
"}\n"
"QPushButton::pressed{\n"
"	background-color: #577590; \n"
"}\n"
"QPushButton:hover:!pressed{\n"
"	background-color: #739bbe; \n"
"}"));

        horizontalLayout->addWidget(closeButton);


        gridLayout->addWidget(frame, 1, 0, 1, 6);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(OutputClass);

        QMetaObject::connectSlotsByName(OutputClass);
    } // setupUi

    void retranslateUi(QWidget *OutputClass)
    {
        OutputClass->setWindowTitle(QCoreApplication::translate("OutputClass", "RF Intermodulation Output", nullptr));
#if QT_CONFIG(tooltip)
        saveButton->setToolTip(QCoreApplication::translate("OutputClass", "Save report as a file", nullptr));
#endif // QT_CONFIG(tooltip)
        saveButton->setText(QCoreApplication::translate("OutputClass", "Save", nullptr));
#if QT_CONFIG(tooltip)
        printButton->setToolTip(QCoreApplication::translate("OutputClass", "Print output results", nullptr));
#endif // QT_CONFIG(tooltip)
        printButton->setText(QCoreApplication::translate("OutputClass", "Print", nullptr));
        emailButton->setText(QCoreApplication::translate("OutputClass", "Email", nullptr));
#if QT_CONFIG(tooltip)
        closeButton->setToolTip(QCoreApplication::translate("OutputClass", "Exit", nullptr));
#endif // QT_CONFIG(tooltip)
        closeButton->setText(QCoreApplication::translate("OutputClass", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputClass: public Ui_OutputClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTCLASS_H
