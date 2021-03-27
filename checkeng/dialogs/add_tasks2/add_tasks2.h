#pragma once
#include <QTextStream>
#include "add_tasks2_pch.h"
#include "include/typedefs.h"
#include "add_tasks2_global.h"
#include "include/program.h"

GT_UI(AddTasks2)

class ADD_TASKS2_DIALOG_SHARED_EXPORT AddTasks2Dialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(AddTasks2Dialog)

 public:
    using class_name = AddTasks2Dialog;
    using inherited  = QDialog;

 private:
    QString indexFile() const noexcept {
        return dirName() + QStringLiteral("index.txt");
    }
    QString dirName() const noexcept {
        return QStringLiteral("%1/%2/").arg(program::paths::test2(), m_dir);
    }

 public:
    explicit AddTasks2Dialog(QWidget* parent = nullptr);
    ~AddTasks2Dialog() override;

 private slots:
    bool onChanged() noexcept;
    void onNextClicked() noexcept;
    void onFinishClicked() noexcept;
    bool writeToFile() noexcept;
    void onCancel() noexcept;
    int writeRightAnswer(QTextStream &out) noexcept;
    void save() noexcept;
    void load() noexcept;
    void onAddAudio() noexcept;

 private:
    Ui::AddTasks2* ui = nullptr;
    QString m_dir;
    bool m_is_next = false;
    int m_cx = 0;
};
