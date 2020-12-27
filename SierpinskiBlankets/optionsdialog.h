#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include "options.h"
#include <QDialog>

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::OptionsDialog *ui;

    void closeEvent(QCloseEvent *event) override;

public:
    Options m_options;
    
public:
    explicit OptionsDialog(QWidget *parent = nullptr);
    ~OptionsDialog();

signals:
    void dialogPressed(int);
    void dialogClosed(void);

private slots:
    void on_butnStar_clicked();
    void on_butnReverseStar_clicked();
    void on_butnCircle_clicked();
    void on_butnReverseCircle_clicked();
    void on_butnGasket_clicked();
    void on_butnReverseGasket_clicked();
    void on_btnCarpet_clicked();
    void on_butnReverseCarpet_clicked();
    void on_btnDraw_clicked();
    void on_btnClear_clicked();
};

#endif
