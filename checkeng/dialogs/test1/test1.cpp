#include "test1.h"
#include "ui_test1.h"
#include "task.h"
#include "dialogs/finish/finish.h"

#include <QFile>
#include <QList>
#include <QDebug>
#include <QPushButton>

Test1Dialog::Test1Dialog(QString const& filename, QString const& name, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Test1)
    , m_filename(filename)
    , m_name(name)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    ui->l_first->installEventFilter(this);
    ui->l_second->installEventFilter(this);
    ui->l_third->installEventFilter(this);
    ui->pb_answer->setEnabled(false);
    start();
}
Test1Dialog::~Test1Dialog()
{
    delete ui;
}
void Test1Dialog::start()
{
    QFile file(m_filename);
    if(!file.open(QIODevice::ReadOnly |QIODevice::Text))
        return;

    QString q, a1, a2, a3;
    int cx = 0;

    while(!file.atEnd()) {
        auto str = file.readLine().trimmed();
        if(str.isEmpty())
            continue;

        if(str[0] != char('-')){
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
    m_answers.clear();
    nextTask();
}
void Test1Dialog::nextTask()
{
    if(m_index >= m_tasks.size()) {
        FinishDialog dlg(m_right, m_tasks.size(), m_answers, m_name);
        dlg.exec();
        close();

        return;
    }
    auto task = m_tasks[m_index];
    ui->l_question->setText(task.question());
    QString allQ = QString::number(m_tasks.size());
    ui->l_all->setText(allQ);
    randomize(task.answer1(), task.answer2(), task.answer3());
    QString leftQ = QString::number(m_tasks.size() - m_index);
    ui->l_left->setText(leftQ);
    m_answers.push_back(Answer(task.question(), task.answer1(), task.answer1()));
}
void Test1Dialog::onAnswerClicked()
{
    switch (num)
    {
    case 1: {
        ui->l_first->setStyleSheet("QLabel { background-color : #5b6881; }");
        answer(ui->l_first);
        break;
        }
    case 2: {
        ui->l_second->setStyleSheet("QLabel { background-color : #5b6881; }");
        answer(ui->l_second);
        break;
        }
    case 3: {
        ui->l_third->setStyleSheet("QLabel { background-color : #5b6881; }");
        answer(ui->l_third);
        break;
        }
    }
}
void Test1Dialog::answer(QLabel* btn)
{
    if(m_index >= m_tasks.size())
        return;

    auto task = m_tasks[m_index];
    if(task.answer1() == btn->text())
        ++m_right;
    ++m_index;
    m_answers.back().setAnswer(btn->text());
    ui->pb_answer->setEnabled(false);
    num = 0;
    nextTask();
}
bool Test1Dialog::eventFilter(QObject* watched, QEvent* event)
{
    if(event->type() != QEvent::MouseButtonPress)
        return false;

    if(watched == ui->l_first){
        if(num == 1){
            ui->pb_answer->setEnabled(false);
            ui->l_first->setStyleSheet("QLabel { background-color : #5b6881; }");
            num = 0;
        }
        else{
            ui->l_third->setStyleSheet("QLabel { background-color : #5b6881; }");
            ui->l_second->setStyleSheet("QLabel { background-color : #5b6881; }");
            ui->l_first->setStyleSheet("QLabel { background-color : #4478B7; }");
            ui->pb_answer->setEnabled(true);
            num = 1;
        }
    }
    else if(watched == ui->l_second){
        if(num == 2){
            ui->pb_answer->setEnabled(false);
            ui->l_second->setStyleSheet("QLabel { background-color : #5b6881; }");
            num = 0;
        }
        else{
            ui->l_first->setStyleSheet("QLabel { background-color : #5b6881; }");
            ui->l_third->setStyleSheet("QLabel { background-color : #5b6881; }");
            ui->l_second->setStyleSheet("QLabel { background-color : #4478B7; }");
            ui->pb_answer->setEnabled(true);
           num = 2;
        }
    }
    else {
        if(num == 3){
            ui->pb_answer->setEnabled(false);
            ui->l_third->setStyleSheet("QLabel { background-color : #5b6881; }");
            num = 0;
        }
        else {
            ui->l_first->setStyleSheet("QLabel { background-color : #5b6881; }");
            ui->l_second->setStyleSheet("QLabel { background-color : #5b6881; }");
            ui->l_third->setStyleSheet("QLabel { background-color : #4478B7; }");
            ui->pb_answer->setEnabled(true);
            num = 3;
        }
    }
    return true;
}
void Test1Dialog::randomize(QString const& first, QString const& second, QString const& third)
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
