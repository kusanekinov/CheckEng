#pragma once
#include <QMainWindow>
#include <QList>
#include "task.h"

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

 public:
    using tasts_t = QList<Task>;

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
    tasts_t m_tasks;
    int m_index;
};
