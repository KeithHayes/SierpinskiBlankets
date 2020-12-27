#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(dialogClosed(void)), parent, SLOT(setNoActiveDialog(void)));
    m_options.setType(ShapeType::circle);
    dialogClosed();
}

OptionsDialog::~OptionsDialog() {
    delete ui;
}

void OptionsDialog::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    dialogClosed();
    delete this;
}

void OptionsDialog::on_butnStar_clicked() { m_options.setType(ShapeType::star); }
void OptionsDialog::on_butnReverseStar_clicked() { m_options.setType(ShapeType::reverse_star); }
void OptionsDialog::on_butnCircle_clicked() { m_options.setType(ShapeType::circle); }
void OptionsDialog::on_butnReverseCircle_clicked() { m_options.setType(ShapeType::reverse_circle); }
void OptionsDialog::on_butnGasket_clicked() { m_options.setType(ShapeType::gasket); }
void OptionsDialog::on_butnReverseGasket_clicked() { m_options.setType(ShapeType::reverse_gasket); }
void OptionsDialog::on_btnCarpet_clicked() { m_options.setType(ShapeType::carpet); }
void OptionsDialog::on_butnReverseCarpet_clicked() { m_options.setType(ShapeType::reverse_carpet); }
void OptionsDialog::on_btnDraw_clicked() {
    QSpinBox* spinner = this->findChild<QSpinBox*>("spinBox");
    m_options.setLevel(spinner->value());
    emit dialogPressed(0);
}
void OptionsDialog::on_btnClear_clicked() { emit dialogPressed(1); }
