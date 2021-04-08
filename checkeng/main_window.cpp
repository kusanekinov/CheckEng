#include <QFile>
#include <QDebug>
#include <QSettings>
#include <QVBoxLayout>
#include "main_window.h"
#include "ui_main_window.h"
#include "dialogs/about/about.h"
#include "dialogs/language/language.h"
#include <QDirIterator>
#include <QDebug>
#include <QToolButton>
#include <QInputDialog>
#include <QMessageBox>
#include "include/program.h"
#include "dialogs/add_tasks/add_tasks.h"
#include "include/context.h"
#include "dialogs/test1/test1.h"
#include "dialogs/test2/test2.h"
#include "dialogs/add_tasks2/add_tasks2.h"
#include "include/language.h"
#include "include/tr.h"
#include "login/login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(pb, SIGNAL (released()),this, SLOT (handleButton()));
    statusBar()->addWidget(label);
    statusBar()->addWidget(pb);
    loadFiles();
    load();
}
MainWindow::~MainWindow()
{
    save();
    delete ui;
}
void MainWindow::onAboutClick()
{
   AboutDialog dlg;
   dlg.exec();
}
void MainWindow::onLanguageClick()
{
    LanguageDialog dlg(gt::options::Language::current().toUint());
    if(dlg.exec() == LanguageDialog::Accepted) {
        gt::options::Language::setCurrent(dlg.current());
        QMessageBox::information(this, iMsg::tr("Information"), iMsg::tr("Language will be changed after the next login!"), QMessageBox::Ok);
    }
}
void MainWindow::setName(QString const& name) noexcept
{
    m_name = name;
    label->setText(tr("Username: ") + m_name + tr(" "));
    pb->setText("Change Username");
    pb->setStyleSheet("QPushButton {min-width:140px; color:white; border-radius: 5px;border: 2px solid #E1DFF1;}");
}
void MainWindow::handleButton()
{
    LoginDialog dlg;
    dlg.exec();
    setName(dlg.name());
}
void MainWindow::onStart(){}
void MainWindow::save() noexcept
{
    auto const& group = QStringLiteral("dialogs/main/");
    QSettings settings;
    settings.beginGroup(group);
    settings.setValue(QStringLiteral("state"), saveState());
    settings.setValue(QStringLiteral("geometry"), saveGeometry());
    settings.endGroup();
}
void MainWindow::load() noexcept
{
    auto const& group = QStringLiteral("dialogs/main/");
    QSettings settings;
    settings.beginGroup(group);
    restoreState(settings.value(QStringLiteral("state")).toByteArray());
    restoreGeometry(settings.value(QStringLiteral("geometry")).toByteArray());
    settings.endGroup();
}
void MainWindow::onAddNewTasksClicked() noexcept
{
    AddTasksDialog dlg;
    dlg.exec();

    loadFiles();
}
void MainWindow::loadFiles() noexcept
{
    gt::removeChildren(ui->w_tasks);
    auto lay = new QVBoxLayout(ui->w_tasks);
    loadTasks1(lay);
    loadTasks2(lay);
}
void MainWindow::loadTasks1(QVBoxLayout* lay) noexcept
{
    QDirIterator it(program::paths::test1(), {}, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    int cx = 1;
    while (it.hasNext()) {
        auto const& name = it.next();
        auto const& filename = QFileInfo(name).fileName()[0] != QChar('{')
            ? QFileInfo(name).fileName()
            : iMsg::tr("Text Task %1").arg(cx++);
        auto w = new QWidget();
        auto v = new QHBoxLayout(w);
        auto btn = new QPushButton(filename);
        QObject::connect(btn, &QToolButton::clicked, [name] () {
            Test1Dialog dlg(name);
            dlg.exec();
        });
        v->addWidget(btn);

        auto btn1 = new QToolButton();
        btn1->setText(iMsg::tr("Edit"));
        QObject::connect(btn1, &QToolButton::clicked, [cx, name, this] () {
            bool ok;
            auto const& text = QInputDialog::getText(nullptr, program::productName(),
                                                      iMsg::tr("Enter a new name:"), QLineEdit::Normal,
                                                      iMsg::tr("Text Task %1").arg(cx), &ok);

            if (ok && !text.isEmpty()) {
                QFile::rename(name, GT_STR("%1/%2").arg(QFileInfo(name).absolutePath()).arg(text));
                this->loadFiles();
            }
        });
        v->addWidget(btn1);

        auto btn2 = new QToolButton();
        btn2->setText(iMsg::tr("Delete"));
        QObject::connect(btn2, &QToolButton::clicked, [name, this] () {
            int ret = QMessageBox::information(nullptr, program::productName(),
                                           iMsg::tr("Do you really want to delete test?"),
                                            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if (ret == QMessageBox::Yes) {
                QFile::remove(name);
                this->loadFiles();
            }
        });
        v->addWidget(btn2);
        lay->addWidget(w);
    }
}
void MainWindow::loadTasks2(QVBoxLayout* lay) noexcept
{
    QDirIterator it(program::paths::test2(), {}, QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    int cx = 1;
    while (it.hasNext()) {
        auto const& name = it.next();
        auto const& filename = QFileInfo(name).fileName()[0] != QChar('{')
            ? QFileInfo(name).fileName()
            : iMsg::tr("Audio Task %1").arg(cx++);
        auto w = new QWidget();
        auto v = new QHBoxLayout(w);
        auto btn = new QPushButton(filename);
        QObject::connect(btn, &QToolButton::clicked, [name] () {
            Test2Dialog dlg(name);
            dlg.exec();
        });
        v->addWidget(btn);

        auto btn1 = new QToolButton();
        btn1->setText(iMsg::tr("Edit"));
        QObject::connect(btn1, &QToolButton::clicked, [cx, name, this] () {
            bool ok;
            auto const& text = QInputDialog::getText(nullptr, program::productName(),
                                                      iMsg::tr("Enter a new name:"), QLineEdit::Normal,
                                                      iMsg::tr("Audio Task %1").arg(cx), &ok);
            if (ok && !text.isEmpty()) {
                QDir().rename(name, GT_STR("%1/%2").arg(QFileInfo(name).absolutePath()).arg(text));
                this->loadFiles();
            }
        });
        v->addWidget(btn1);

        auto btn2 = new QToolButton();
        btn2->setText(iMsg::tr("Delete"));
        QObject::connect(btn2, &QToolButton::clicked, [name, this] () {
            int ret = QMessageBox::information(nullptr, program::productName(),
                                           iMsg::tr("Do you really want to delete test?"),
                                            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if (ret == QMessageBox::Yes) {
                QDir(name).removeRecursively();
                this->loadFiles();
            }
        });
        v->addWidget(btn2);
        lay->addWidget(w);
    }
}
void MainWindow::onAddNewAudioClicked() noexcept
{
    AddTasks2Dialog dlg;
    dlg.exec();

    loadFiles();
}
