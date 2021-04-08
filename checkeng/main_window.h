#pragma once
#include <QMainWindow>
#include <QList>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

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
    void onLanguageClick();
    void onStart();
    void save() noexcept;
    void load() noexcept;
    void onAddNewTasksClicked() noexcept;
    void onAddNewAudioClicked() noexcept;
    void loadFiles() noexcept;
    void loadTasks1(QVBoxLayout* lay) noexcept;
    void loadTasks2(QVBoxLayout* lay) noexcept;
    void handleButton();

 private:
    Ui::MainWindow* ui = nullptr;
    QString m_name;
    QLabel *label = new QLabel("zero");
    QPushButton *pb = new QPushButton("Change Username");

};
