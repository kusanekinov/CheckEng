#include "main_window.h"
#include <QApplication>
#include "login/login.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
        return a.exec();
    }
}
