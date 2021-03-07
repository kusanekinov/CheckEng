#pragma once
#include <QMainWindow>
#include <QList>

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
    void save() noexcept;
    void load() noexcept;

 private:
    Ui::MainWindow* ui = nullptr;
    QString m_name;
};
