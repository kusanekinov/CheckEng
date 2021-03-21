#pragma once
#include "add_tasks_pch.h"
#include "add_tasks_global.h"

namespace Ui {
    class AddTasks;
}

class ADD_TASKS_DIALOG_SHARED_EXPORT AddTasksDialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(AddTasksDialog)

 public:
    using class_name = AddTasksDialog;
    using inherited  = QDialog;

 public:
    explicit AddTasksDialog(QWidget* parent = nullptr);
    ~AddTasksDialog() override;

 private slots:
    bool onChanged() noexcept;
    void onNextClicked() noexcept;
    void onFinishClicked() noexcept;

 private:
    Ui::AddTasks* ui = nullptr;
    QString m_file;
};
