#include "choose.h"
#include "ui_choose.h"

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

}
