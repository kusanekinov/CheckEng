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
    void onAddNewTasksClicked() noexcept;

 private:
    Ui::AddTasks* ui = nullptr;
};
