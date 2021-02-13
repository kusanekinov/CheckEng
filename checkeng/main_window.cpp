#include "main_window.h"
#include "./ui_main_window.h"
#include <QDebug>
#include "dialogs/about/about.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
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
    QFile file("tests/1/test1.txt");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!file.atEnd())
            {
                QString str = file.readLine();
                qDebug() <<str;
            }

        }
        else
        {
            qDebug()<< "don't open file";
        }
}


