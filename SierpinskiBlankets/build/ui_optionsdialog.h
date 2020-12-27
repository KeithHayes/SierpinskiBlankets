/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QRadioButton *butnGasket;
    QRadioButton *btnCarpet;
    QPushButton *btnDraw;
    QPushButton *btnClear;
    QRadioButton *butnReverseGasket;
    QRadioButton *butnReverseCarpet;
    QRadioButton *butnCircle;
    QSpinBox *spinBox;
    QLabel *label;
    QRadioButton *butnStar;
    QRadioButton *butnReverseStar;
    QRadioButton *butnReverseCircle;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(350, 300);
        butnGasket = new QRadioButton(OptionsDialog);
        butnGasket->setObjectName(QString::fromUtf8("butnGasket"));
        butnGasket->setGeometry(QRect(40, 160, 79, 28));
        btnCarpet = new QRadioButton(OptionsDialog);
        btnCarpet->setObjectName(QString::fromUtf8("btnCarpet"));
        btnCarpet->setGeometry(QRect(40, 202, 78, 28));
        btnDraw = new QPushButton(OptionsDialog);
        btnDraw->setObjectName(QString::fromUtf8("btnDraw"));
        btnDraw->setGeometry(QRect(190, 20, 91, 31));
        btnClear = new QPushButton(OptionsDialog);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(190, 70, 92, 31));
        butnReverseGasket = new QRadioButton(OptionsDialog);
        butnReverseGasket->setObjectName(QString::fromUtf8("butnReverseGasket"));
        butnReverseGasket->setGeometry(QRect(171, 160, 138, 28));
        butnReverseCarpet = new QRadioButton(OptionsDialog);
        butnReverseCarpet->setObjectName(QString::fromUtf8("butnReverseCarpet"));
        butnReverseCarpet->setGeometry(QRect(171, 202, 137, 28));
        butnCircle = new QRadioButton(OptionsDialog);
        butnCircle->setObjectName(QString::fromUtf8("butnCircle"));
        butnCircle->setGeometry(QRect(40, 118, 75, 28));
        butnCircle->setChecked(true);
        spinBox = new QSpinBox(OptionsDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(60, 40, 49, 31));
        spinBox->setMaximum(9);
        spinBox->setValue(2);
        label = new QLabel(OptionsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 40, 67, 31));
        butnStar = new QRadioButton(OptionsDialog);
        butnStar->setObjectName(QString::fromUtf8("butnStar"));
        butnStar->setGeometry(QRect(40, 244, 65, 28));
        butnReverseStar = new QRadioButton(OptionsDialog);
        butnReverseStar->setObjectName(QString::fromUtf8("butnReverseStar"));
        butnReverseStar->setGeometry(QRect(171, 244, 124, 28));
        butnReverseCircle = new QRadioButton(OptionsDialog);
        butnReverseCircle->setObjectName(QString::fromUtf8("butnReverseCircle"));
        butnReverseCircle->setGeometry(QRect(171, 118, 135, 28));
        butnReverseCircle->setChecked(false);

        retranslateUi(OptionsDialog);

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QCoreApplication::translate("OptionsDialog", "Dialog", nullptr));
        butnGasket->setText(QCoreApplication::translate("OptionsDialog", "Gasket", nullptr));
        btnCarpet->setText(QCoreApplication::translate("OptionsDialog", "Carpet", nullptr));
        btnDraw->setText(QCoreApplication::translate("OptionsDialog", "Draw", nullptr));
        btnClear->setText(QCoreApplication::translate("OptionsDialog", "Clear", nullptr));
        butnReverseGasket->setText(QCoreApplication::translate("OptionsDialog", "Reverse Gasket", nullptr));
        butnReverseCarpet->setText(QCoreApplication::translate("OptionsDialog", "Reverse Carpet", nullptr));
        butnCircle->setText(QCoreApplication::translate("OptionsDialog", "Circles", nullptr));
        label->setText(QCoreApplication::translate("OptionsDialog", "levels", nullptr));
        butnStar->setText(QCoreApplication::translate("OptionsDialog", "Stars", nullptr));
        butnReverseStar->setText(QCoreApplication::translate("OptionsDialog", "Reverse Stars", nullptr));
        butnReverseCircle->setText(QCoreApplication::translate("OptionsDialog", "Reverse Circles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
