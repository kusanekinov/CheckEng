#include "add_tasks.h"
#include "ui_add_tasks.h"

AddTasksDialog::AddTasksDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddTasks)
{
    ui->setupUi(this);    
}
AddTasksDialog::~AddTasksDialog()
{
    delete ui;
}
void AddTasksDialog::onAddNewTasksClicked() noexcept
{

}
