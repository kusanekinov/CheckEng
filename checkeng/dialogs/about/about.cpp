#include "about.h"
#include "ui_about.h"
#include "include/program.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    ui->productname->setText(program::productName());
    ui->version->setText(program::fullVersion());
    QString author = "Author: " + program::author();
    ui->author->setText(author);
    ui->date->setText(program::date());
}
AboutDialog::~AboutDialog()
{
    delete ui;
}
