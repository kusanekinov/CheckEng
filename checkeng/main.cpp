#include "main_window.h"
#include <QApplication>
#include "login/login.h"
#include <cstdlib>

void init()
{
    QCoreApplication::setOrganizationName("CheckEng");
    QCoreApplication::setOrganizationDomain("checkeng.org");
    QCoreApplication::setApplicationName("CheckEng");
    QCoreApplication::setApplicationVersion("1.0");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
}
int main(int argc, char *argv[])
{
    std::srand(std::time(nullptr));

    QApplication a(argc, argv);
    init();
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted) {
        MainWindow w;
        w.setName(dlg.name());
        w.show();
        return a.exec();
    }
}
