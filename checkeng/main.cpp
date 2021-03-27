#include <cstdlib>
#include <QApplication>
#include <QDir>
#include "include/program.h"
#include "main_window.h"

#include "login/login.h"
#include "dialogs/add_tasks/add_tasks.h"
#include "dialogs/choose/choose.h"

void init()
{
    QCoreApplication::setOrganizationName("CheckEng");
    QCoreApplication::setOrganizationDomain("checkeng.org");
    QCoreApplication::setApplicationName("CheckEng");
    QCoreApplication::setApplicationVersion("1.0");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QDir dir{program::paths::test1()};
    if(!dir.exists())
        dir.mkpath(program::paths::test1());

    dir.setPath(program::paths::test2());
    if(!dir.exists())
        dir.mkpath(program::paths::test2());
}
int main(int argc, char *argv[])
{
    std::srand(std::time(nullptr));

    QApplication a(argc, argv);
    init();

    ChooseDialog dlg;
    if(dlg.exec() != QDialog::Accepted)
         return EXIT_SUCCESS;


//    LoginDialog dlg;
//    if(dlg.exec() == QDialog::Accepted) {
//        MainWindow w;
//        w.setName(dlg.name());
//        w.show();
//        return a.exec();
//    }
    return EXIT_SUCCESS;
}
