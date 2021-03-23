#pragma once
#include "test1_pch.h"
#include "test1_global.h"
#include <QList>
#include <QResizeEvent>
#include "task.h"

namespace Ui {
    class Test1;
}

class TEST1_DIALOG_SHARED_EXPORT Test1Dialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Test1Dialog)

public:
    using class_name = Test1Dialog;
    using inherited  = QDialog;
    using tasts_t = QList<Task>;

private:
    void start();
    void nextTask();
    void onFirstAnswerClick();
    void onSecondAnswerClick();
    void onThirdAnswerClick();
    void answer(QPushButton* btn);
    void randomize(QString const& first, QString const& second, QString const& third);
    void resizeEvent(QResizeEvent* event) override;

public:
    explicit Test1Dialog(QString const& name, QWidget* parent = nullptr);
    ~Test1Dialog() override;

private:
    Ui::Test1* ui = nullptr;
    QString m_filename;
    tasts_t m_tasks;
    int m_index = 0;
    int m_right = 0;
};
