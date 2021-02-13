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
    if(!file.open(QIODevice::ReadOnly |QIODevice::Text)) {
        qDebug()<< "don't open file";
        return;
    }
    QString q, a1, a2, a3;
    bool newtask = true;
    int cx = 0;

    while(!file.atEnd()) {
        auto str = file.readLine().trimmed();
        if(str.isEmpty())
            continue;

        if(str[0] != char('-')){
            newtask = true;
            q = str;
            cx = 0;
        }
        else if(str[0] == char('-')) {
            str = str.mid(1);
            if(cx == 0)
                a1 = str;
            else if(cx == 1)
                a2 = str;
            else {
                a3 = str;
                m_tasks.push_back(Task(q, a1, a2 ,a3));
            }
            ++cx;
        }
    }

    m_index = 0;

    auto task = m_tasks[m_index];
    ui->l_question->setText(task.question());
    ui->pb_answer1->setText(task.answer1());
    ui->pb_answer2->setText(task.answer2());
    ui->pb_answer3->setText(task.answer3());
}


