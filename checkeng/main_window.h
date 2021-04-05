#pragma once
#include <QMainWindow>
#include <QList>
#include <QVBoxLayout>

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setName(QString const& name) noexcept;
    void deleteName();


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

};
