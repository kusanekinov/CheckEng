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
        auto a = new QLabel(tr("Your Answer: ") + i.answer(), this);
        l->addWidget(q, cx, 0);
        l->addWidget(r, cx++, 1);
        l->addWidget(a, cx++, 1);
        ui->w_tasks->addWidget(w);
    }
}
