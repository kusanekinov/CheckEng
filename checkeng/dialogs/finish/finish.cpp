#include "finish.h"
#include "ui_finish.h"

FinishDialog::FinishDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Finish)
{
    ui->setupUi(this);    
  //  ui->l_verInfo->setText(program::fullVersion());
}
FinishDialog::~FinishDialog()
{
    delete ui;
}
