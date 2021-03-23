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
    load();
}
AddTasksDialog::~AddTasksDialog()
{
    save();
    delete ui;
}
bool AddTasksDialog::onChanged() noexcept
{
    auto const is = gt::checker::textSize(ui->le_task,1,256) &&
            gt::checker::textSize(ui->le_answer1,1,256) &&
            gt::checker::textSize(ui->le_answer2,1,256) &&
            gt::checker::textSize(ui->le_answer3,1,256);
    ui->pb_finish->setEnabled(is || m_is_next);
    ui->pb_nexttask->setEnabled(is);
    return is;
}
void AddTasksDialog::onNextClicked() noexcept
{
    if(!writeToFile())
        return;

    ui->le_task->setText("");
    ui->le_answer1->setText("");
    ui->le_answer2->setText("");
    ui->le_answer3->setText("");

    onChanged();
}
void AddTasksDialog::onFinishClicked() noexcept
{
    if(onChanged())
        writeToFile();

    inherited::accept();
}
bool AddTasksDialog::writeToFile() noexcept
{
   if(!onChanged()) {
       QMessageBox::warning(this,  program::fullName(), tr("Enter a vaid data!"), QMessageBox::Ok);
       return false;
   }

   QFile file(program::paths::test1() + GT_STR("/") + m_file );
   if (!file.open(QIODevice::Append | QIODevice::Text)) {
       QMessageBox::warning(this, program::fullName(), tr("Cannot open the file %1!").arg(m_file), QMessageBox::Ok);
       return false;
   }

   QTextStream out(&file);
   out << gt::trim(ui->le_task->text()) << "\n";
   auto const res = writeRightAnswer(out);
   if(res == 1) {
       out << '-' << gt::trim(ui->le_answer2->text()) << "\n";
       out << '-' << gt::trim(ui->le_answer3->text()) << "\n\n";
   }
   else if(res == 2) {
       out << '-' << gt::trim(ui->le_answer1->text()) << "\n";
       out << '-' << gt::trim(ui->le_answer3->text()) << "\n\n";
   }
   else {
       out << '-' << gt::trim(ui->le_answer1->text()) << "\n";
       out << '-' << gt::trim(ui->le_answer2->text()) << "\n\n";
   }

   m_is_next = true;
   return true;
}
void AddTasksDialog::onCancel() noexcept
{
    QFile file(program::paths::test1() + GT_STR("/") + m_file);
    if(file.exists())
        file.remove();
    reject();
}
int AddTasksDialog::writeRightAnswer(QTextStream &out) noexcept
{
    if(ui->rb_answer1->isChecked()){
        out << '-' << gt::trim(ui->le_answer1->text()) << "\n";
        return 1;
    }
    else if(ui->rb_answer2->isChecked()){
        out << '-' << gt::trim(ui->le_answer2->text()) << "\n";
        return 2;
    }
    out << '-' << gt::trim(ui->le_answer3->text()) << "\n";
    return 3;
}
void AddTasksDialog::save() noexcept
{
    auto const& group = QStringLiteral("dialogs/add_tasks/");
    QSettings settings;
    settings.beginGroup(group);
    settings.setValue(QStringLiteral("geometry"), saveGeometry());
    settings.endGroup();
}
void AddTasksDialog::load() noexcept
{
    auto const& group = QStringLiteral("dialogs/add_tasks/");
    QSettings settings;
    settings.beginGroup(group);
    restoreGeometry(settings.value(QStringLiteral("geometry")).toByteArray());
    settings.endGroup();
}

