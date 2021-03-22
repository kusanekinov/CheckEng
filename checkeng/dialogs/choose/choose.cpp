#include <QDirIterator>
#include <QDebug>
#include <QToolButton>
#include <QInputDialog>
#include <QMessageBox>
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
    int cx = 1;
    while (it.hasNext()) {
        auto const& name = it.next();
        auto v = new QHBoxLayout();
        auto btn = new QPushButton(GT_STR("Text Task %1").arg(cx++));
        btn->setProperty("file", name);
        v->addWidget(btn);

        auto btn1 = new QToolButton();
        btn1->setText(GT_STR("Edit"));
        QObject::connect(btn1, &QToolButton::clicked, [cx, name] () {
            bool ok;
            auto const& text = QInputDialog::getText(nullptr, program::fullProductName(),
                                                      tr("Enter a new name:"), QLineEdit::Normal,
                                                      GT_STR("Text Task %1").arg(cx), &ok);
            if (ok && !text.isEmpty())
                QFile::rename(name, GT_STR("%1/%2").arg(QFileInfo(name).absolutePath()).arg(text));
        });
        v->addWidget(btn1);

        auto btn2 = new QToolButton();
        btn2->setText(GT_STR("Delete"));
        QObject::connect(btn2, &QToolButton::clicked, [name] () {
            int ret = QMessageBox::information(nullptr, program::fullProductName(),
                                           tr("Do you really want to delete test?"),
                                            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if (ret == QMessageBox::Yes)
                QFile::remove(name);
        });
        v->addWidget(btn2);

        ui->vl_2->addLayout(v);
    }

}
