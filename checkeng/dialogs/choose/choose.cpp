#include <QDirIterator>
#include <QDebug>
#include "choose.h"
#include "include/program.h"
#include "ui_choose.h"
#include "dialogs/add_tasks/add_tasks.h"

ChooseDialog::ChooseDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Choose)
{
    ui->setupUi(this);
    loadFiles();
}
ChooseDialog::~ChooseDialog()
{
    delete ui;
}
void ChooseDialog::onAddNewTasksClicked() noexcept
{
    AddTasksDialog dlg;
    dlg.exec();

    loadFiles();
}
void ChooseDialog::loadFiles() noexcept
{
    QStringList filter;
    QDirIterator it(program::paths::test1(), filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QStringList files;
    while (it.hasNext())
        files << it.next();
//    if (!text.isEmpty())
//        files = findFiles(files, text);
//    files.sort();
//    showFiles(files)
    qDebug() << files;
}
