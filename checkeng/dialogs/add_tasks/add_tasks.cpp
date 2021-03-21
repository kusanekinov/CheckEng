#include <QUuid>
#include "add_tasks.h"
#include "ui_add_tasks.h"
#include "include/checker.h"

AddTasksDialog::AddTasksDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddTasks)
{
    ui->setupUi(this);
    m_file = QUuid::createUuid().toString();
}
AddTasksDialog::~AddTasksDialog()
{
    delete ui;
}
bool AddTasksDialog::onChanged() noexcept
{
    auto const is = gt::checker::textSize(ui->le_task,1,256) &&
            gt::checker::textSize(ui->le_answer1,1,256) &&
            gt::checker::textSize(ui->le_answer2,1,256) &&
            gt::checker::textSize(ui->le_answer3,1,256);
    ui->pb_finish->setEnabled(is);
    ui->pb_nexttask->setEnabled(is);
    return is;
}
void AddTasksDialog::onNextClicked() noexcept
{
   qDebug()<<m_file;
}
void AddTasksDialog::onFinishClicked() noexcept
{

}

