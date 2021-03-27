#include "test2.h"
#include "ui_test2.h"
#include "task2.h"
#include "dialogs/finish/finish.h"

#include <QFile>
#include <QList>
#include <QDebug>
#include <QPushButton>

Test2Dialog::Test2Dialog(QString const& filename, QString const& name, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Test2)
    , m_filename(filename)
    , m_name(name)
{
    ui->setupUi(this);
    ui->l_first->installEventFilter(this);
    ui->l_second->installEventFilter(this);
    ui->l_third->installEventFilter(this);
    start();
}
Test2Dialog::~Test2Dialog()
{
    delete ui;
}
void Test2Dialog::start()
{
    QFile file(m_filename);
    if(!file.open(QIODevice::ReadOnly |QIODevice::Text))
        return;

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
    m_right = 0;

    nextTask();
}
void Test2Dialog::nextTask()
{
    if(m_index >= m_tasks.size()) {
        FinishDialog dlg(m_name, m_right, m_tasks.size());
        dlg.exec();
        close();

        return;
    }
    auto task = m_tasks[m_index];
    ui->l_question->setText(task.question());
    randomize(task.answer1(), task.answer2(), task.answer3());
}
void Test2Dialog::answer(QLabel* btn)
{
    if(m_index >= m_tasks.size())
        return;

    auto task = m_tasks[m_index];
    if(task.answer1() == btn->text())
        ++m_right;
    ++m_index;
    nextTask();
}
bool Test2Dialog::eventFilter(QObject* watched, QEvent* event)
{
    if(event->type() != QEvent::MouseButtonPress)
        return false;

    if(watched == ui->l_first)
        answer(ui->l_first);
    else if(watched == ui->l_second)
        answer(ui->l_second);
    else
        answer(ui->l_third);
    return true;
}
void Test2Dialog::randomize(QString const& first, QString const& second, QString const& third)
{
     QVector<QLabel*> V{ui->l_first, ui->l_second, ui->l_third};
     int x = rand()%3;
     V[x]->setText(first);
     V.remove(x);
     x = rand()%2;
     V[x]->setText(second);
     V.remove(x);
     V[0]->setText(third);
}
