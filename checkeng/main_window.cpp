#include <QFile>
#include <QDebug>
#include <QSettings>
#include "main_window.h"
#include "ui_main_window.h"
#include "dialogs/about/about.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
void MainWindow::setName(QString const& name) noexcept
{
    m_name=name;
}
void MainWindow::onStart()
{

}
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
