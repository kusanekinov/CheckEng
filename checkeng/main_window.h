#pragma once
#include <QMainWindow>
#include <QList>
#include <QPushButton>
#include "task.h"

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

 public:
    using tasts_t = QList<Task>;

private:
   void answer(QPushButton* btn);
   void nextTask();
   void randomize(QString const& first, QString const& second, QString const& third);

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setName(QString const& name) noexcept;

 private slots:
    void onAboutClick();
    void onStart();
    void onFirstAnswerClick();
    void onSecondAnswerClick();
    void onThirdAnswerClick();
    void save() noexcept;
    void load() noexcept;

 private:
    Ui::MainWindow* ui = nullptr;
    QString m_name;
    tasts_t m_tasks;
    int m_index;
    int m_right = 0;
};
