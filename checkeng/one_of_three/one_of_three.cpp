#include "one_of_three.h"
#include "ui_one_of_three.h"

OneOfThree::OneOfThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OneOfThree)
{
    ui->setupUi(this);
}

OneOfThree::~OneOfThree()
{
    delete ui;
}
