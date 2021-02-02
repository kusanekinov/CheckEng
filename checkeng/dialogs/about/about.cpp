#include "about.h"
#include "ui_about.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent, Qt::FramelessWindowHint)
    , ui(new Ui::About)
{
    ui->setupUi(this);    
  //  ui->l_verInfo->setText(program::fullVersion());
}
AboutDialog::~AboutDialog()
{
    delete ui;
}
