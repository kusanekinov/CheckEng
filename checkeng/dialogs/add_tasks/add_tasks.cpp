#include "add_tasks.h"
#include "ui_add_tasks.h"

AddTasksDialog::AddTasksDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTasks)
{
    ui->setupUi(this);    
  //  ui->l_verInfo->setText(program::fullVersion());
}
AddTasksDialog::~AddTasksDialog()
{
    delete ui;
}
