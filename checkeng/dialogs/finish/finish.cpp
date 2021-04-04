#include "finish.h"
#include "ui_finish.h"

FinishDialog::FinishDialog(QString const& name, int right, int total, QVector<Answer> const& answers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Finish)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    ui->m_name->setText(name);
    ui->m_correct->setText(QString::number(right));
    ui->m_total->setText(QString::number(total));
    ui->m_incorrect->setText(QString::number(total-right));
    ui->m_percent->setText(QStringLiteral("%1%").arg(right*100 / total));
    printAnswers(answers);
}
FinishDialog::~FinishDialog()
{
    delete ui;
}
void FinishDialog::printAnswers(QVector<Answer> const& answers) noexcept
{
    int cx = 0;
    for(auto const& i : answers) {
        auto w = new QWidget(this);
        w->setObjectName("answers1");
        auto l = new QGridLayout(w);
        auto q = new QLabel(i.question(), this);
        auto r = new QLabel(tr("Right Answer: ") + i.right(), this);
        r->setStyleSheet("QLabel { background-color: rgb(195, 255, 192); color: black;border-radius: 5px; margin-left: 6px; min-height: 27px; }");
        auto a = new QLabel(tr("Your Answer: ") + i.answer(), this);
        if(i.right() == i.answer())
            a->setStyleSheet("QLabel { background-color: rgb(195, 255, 192);color: black;border-radius: 5px; margin-left: 6px; min-height: 27px; }");
        else
            a->setStyleSheet("QLabel { background-color: rgb(255, 181, 191);color: black;border-radius: 5px; margin-left: 6px;  min-height: 27px; }");
        l->addWidget(q, cx, 0);
        l->addWidget(r, cx++, 1);
        l->addWidget(a, cx++, 1);
        ui->w_tasks->addWidget(w);
    }
}
