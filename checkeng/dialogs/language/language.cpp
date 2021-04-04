#include "language.h"
#include "ui_language.h"
#include "include/checkbox_algo.h"
#include "include/language.h"

LanguageDialog::LanguageDialog(uint current, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Language)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);

    ui->m_language->addItem(tr("Russian"), russianId());
    ui->m_language->addItem(tr("English"), englishId());
    gt::cb::setCurrent(ui->m_language, current);
}
LanguageDialog::~LanguageDialog()
{
    delete ui;
}
uint LanguageDialog::current() const
{
    return gt::cb::current<uint>(ui->m_language);
}
void LanguageDialog::onChangeClicked()
{
    ui->b_apply->setDisabled(current() == m_current);
}
