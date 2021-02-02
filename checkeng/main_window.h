#pragma once
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

 private slots:
    void onAboutClick();

 private:
    Ui::MainWindow* ui = nullptr;
};
