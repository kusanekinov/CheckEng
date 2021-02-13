#include "login.h"
#include "ui_login.h"
#include <QTimer>
#include <QDate>
/*#include "include/app.h"
#include "src/main_http.h"
#include "src/options/network.h"
#include <gt/settings/settings.h> */

LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}
void LoginDialog::onAccepted() noexcept
{
    ui->m_info->setText({});
    if(onChanged())
        return;

    ui->b_login->setEnabled(false);
    QApplication::processEvents();
}
bool LoginDialog::onChanged() noexcept
{
    auto const is = ui->m_login->text().isEmpty();
    ui->b_login->setDisabled(is);
    return is;
}
LoginDialog::~LoginDialog()
{
}
