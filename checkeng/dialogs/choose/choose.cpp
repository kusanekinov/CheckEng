#include "choose.h"
#include "ui_choose.h"
#include "dialogs/add_tasks/add_tasks.h"

ChooseDialog::ChooseDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Choose)
{
    ui->setupUi(this);    
}
ChooseDialog::~ChooseDialog()
{
    delete ui;
}
void ChooseDialog::onAddNewTasksClicked() noexcept
{
    AddTasksDialog dlg;
    if(dlg.exec() == QDialog::Accepted) {

    }
}
