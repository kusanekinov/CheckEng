#include "main_window.h"
#include <QApplication>
#include "login/login.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    std::srand(std::time(nullptr));

    QApplication a(argc, argv);
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted) {
        MainWindow w;
        w.setName(dlg.name());
        w.show();
        return a.exec();
    }
}
