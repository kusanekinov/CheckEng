#include <QUuid>
#include <QMessageBox>
#include <QFile>
#include "add_tasks.h"
#include "ui_add_tasks.h"
#include "include/checker.h"
#include "include/program.h"

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
   if(!onChanged())
       return (void) QMessageBox::warning(this,  program::fullName(), tr("Enter a vaid data!"), QMessageBox::Ok);

   QFile file(program::paths::test1() + m_file);
       if (!file.open(QIODevice::Append | QIODevice::Text))
           return (void) QMessageBox::warning(this, program::fullName(), tr("Cannot open the file %1!").arg(m_file), QMessageBox::Ok);

   QTextStream out(&file);
   out << ui->le_task->text() << "\n";
   out << ui->le_answer1->text() << "\n";
   out << ui->le_answer2->text() << "\n";
   out << ui->le_answer3->text() << "\n\n";
}
void AddTasksDialog::onFinishClicked() noexcept
{
    if(!onChanged()) {
        QMessageBox::warning(this, tr("CheckEng"),
                                       tr("Enter a vaid data!"), QMessageBox::Ok);
        return;
    }
}

