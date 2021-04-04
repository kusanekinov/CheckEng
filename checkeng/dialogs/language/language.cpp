#include "language.h"
#include "ui_language.h"

LanguageDialog::LanguageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Language)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);

    ui->m_language->addItem(("Russian"));
    ui->m_language->addItem(("English"));

}
LanguageDialog::~LanguageDialog()
{
    delete ui;
}
void LanguageDialog::onChangeClicked()
{
    //ui->b_apply->setDisabled(current() == m_current);
}
