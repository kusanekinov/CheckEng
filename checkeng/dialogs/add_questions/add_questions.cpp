#include "add_questinons.h"
#include "ui_add_questinons.h"

Add_questinonsDialog::Add_questinonsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_questinons)
{
    ui->setupUi(this);    
  //  ui->l_verInfo->setText(program::fullVersion());
}
Add_questinonsDialog::~Add_questinonsDialog()
{
    delete ui;
}
