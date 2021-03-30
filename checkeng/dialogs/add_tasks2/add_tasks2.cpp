#include <QUuid>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include "add_tasks2.h"
#include "ui_add_tasks2.h"
#include "include/checker.h"

AddTasks2Dialog::AddTasks2Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddTasks2)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    m_dir = QUuid::createUuid().toString();
    QDir().mkpath(dirName());
    load();
}
AddTasks2Dialog::~AddTasks2Dialog()
{
    save();
    delete ui;
}
bool AddTasks2Dialog::onChanged() noexcept
{
    auto const is = gt::checker::textSize(ui->le_task,1,256) &&
            gt::checker::textSize(ui->le_answer1,1,256) &&
            gt::checker::textSize(ui->le_answer2,1,256) &&
            gt::checker::textSize(ui->le_answer3,1,256) &&
            gt::checker::textSize(ui->le_audio,1,256);

    ui->pb_finish->setEnabled(is || m_is_next);
    ui->pb_nexttask->setEnabled(is);
    return is;
}
void AddTasks2Dialog::onNextClicked() noexcept
{
    if(!writeToFile())
        return;

    ui->le_task->setText("");
    ui->le_answer1->setText("");
    ui->le_answer2->setText("");
    ui->le_answer3->setText("");
    ui->le_audio->setText("");
    m_cx++;

    onChanged();
}
void AddTasks2Dialog::onFinishClicked() noexcept
{
    if(onChanged())
        writeToFile();

    inherited::accept();
}
bool AddTasks2Dialog::writeToFile() noexcept
{
   if(!onChanged()) {
       QMessageBox::warning(this,  program::fullName(), tr("Enter a vaid data!"), QMessageBox::Ok);
       return false;
   }

   QFile file(indexFile());
   if (!file.open(QIODevice::Append | QIODevice::Text)) {
       QMessageBox::warning(this, program::fullName(), tr("Cannot open the file %1!").arg(indexFile()), QMessageBox::Ok);
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
void AddTasks2Dialog::onCancel() noexcept
{
    QDir dir(dirName());
    if(dir.exists())
        dir.removeRecursively();
    close();
}
int AddTasks2Dialog::writeRightAnswer(QTextStream &out) noexcept
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
void AddTasks2Dialog::save() noexcept
{
    auto const& group = QStringLiteral("dialogs/add_tasks/");
    QSettings settings;
    settings.beginGroup(group);
    settings.setValue(QStringLiteral("geometry"), saveGeometry());
    settings.endGroup();
}
void AddTasks2Dialog::load() noexcept
{
    auto const& group = QStringLiteral("dialogs/add_tasks/");
    QSettings settings;
    settings.beginGroup(group);
    restoreGeometry(settings.value(QStringLiteral("geometry")).toByteArray());
    settings.endGroup();
}
void AddTasks2Dialog::onAddAudio() noexcept
{
    auto const& fileName = QFileDialog::getOpenFileName(this,
         tr("Open Audio File"), "", tr("Audio Files (*.mp3)"));
    if(fileName.isEmpty())
        return;
    ui->le_audio->setText(fileName);
    QFile::copy(fileName, dirName() + QString::number(m_cx) + GT_STR(".mp3"));

    onChanged();
}
