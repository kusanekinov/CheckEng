#include "test2.h"
#include "ui_test2.h"
#include "dialogs/test1/task.h"
#include "dialogs/finish/finish.h"
#include "include/answer.h"

#include <QFile>
#include <QList>
#include <QDebug>
#include <QPushButton>
#include <QStringLiteral>
#include <QMediaPlayer>

Test2Dialog::Test2Dialog(QString const& dir, QString const& name, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Test2)
    , m_dir(dir)
    , m_name(name)
    , m_player(new QMediaPlayer)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    ui->l_first->installEventFilter(this);
    ui->l_second->installEventFilter(this);
    ui->l_third->installEventFilter(this);
    ui->tb_play->setProperty("isPlay", false);
    start();
}
Test2Dialog::~Test2Dialog()
{
    delete ui;
    delete m_player;
}
void Test2Dialog::start()
{
    QFile file(m_dir + "/index.txt");
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
void Test2Dialog::nextTask()
{
    m_player->stop();
    ui->tb_play->setIcon(QIcon(QStringLiteral(":/svg/play.png")));
    ui->tb_play->setProperty("isPlay", false);

    if(m_index >= m_tasks.size()) {
        FinishDialog dlg(m_name, m_right, m_tasks.size(), m_answers);
        dlg.exec();
        close();

        return;
    }
    auto task = m_tasks[m_index];
    ui->l_question->setText(task.question());
    randomize(task.answer1(), task.answer2(), task.answer3());
    m_answers.push_back(Answer(task.question(), task.answer1(), task.answer1()));
    m_cx++;
    ui->l_file->setText(QStringLiteral("%1.mp3").arg(m_cx));
}
void Test2Dialog::answer(QLabel* btn)
{
    if(m_index >= m_tasks.size())
        return;

    auto task = m_tasks[m_index];
    if(task.answer1() == btn->text())
        ++m_right;
    ++m_index;
    m_answers.back().setAnswer(btn->text());
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
void Test2Dialog::onPlayClicked() noexcept
{
    if(!ui->tb_play->property("isPlay").toBool()) {
        m_player->setMedia(QUrl::fromLocalFile(m_dir + QStringLiteral("/") + QString::number(m_cx) + QStringLiteral(".mp3")));
        m_player->play();
        ui->tb_play->setIcon(QIcon(QStringLiteral(":/svg/pause.png")));
        ui->tb_play->setProperty("isPlay", true);
    }
    else {
        m_player->stop();
        ui->tb_play->setIcon(QIcon(QStringLiteral(":/svg/play.png")));
        ui->tb_play->setProperty("isPlay", false);
    }
}
