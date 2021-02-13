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
    void setName(QString const& name) noexcept;

 private slots:
    void onAboutClick();
    void onStart();

 private:
    Ui::MainWindow* ui = nullptr;
    QString m_name;
};
