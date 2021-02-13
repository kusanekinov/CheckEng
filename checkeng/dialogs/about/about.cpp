#include "about.h"
#include "ui_about.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);    
  //  ui->l_verInfo->setText(program::fullVersion());
}
AboutDialog::~AboutDialog()
{
    delete ui;
}
