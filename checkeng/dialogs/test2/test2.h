#pragma once
#include "test2_pch.h"
#include "test2_global.h"
#include <QList>
#include <QLabel>
#include "task2.h"

namespace Ui {
    class Test2;
}

class TEST2_DIALOG_SHARED_EXPORT Test2Dialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Test2Dialog)

public:
    using class_name = Test2Dialog;
    using inherited  = QDialog;
    using tasts_t    = QList<Task>;

private:
    void nextTask();
    void onFirstAnswerClick();
    void onSecondAnswerClick();
    void onThirdAnswerClick();
    void answer(QLabel* btn);
    void randomize(QString const& first, QString const& second, QString const& third);
    bool eventFilter(QObject* watched, QEvent* event);

public:
    explicit Test2Dialog(QString const& file, QString const& name, QWidget* parent = nullptr);
    ~Test2Dialog() override;
    void start();

private:
    Ui::Test2* ui = nullptr;
    QString m_filename;
    QString m_name;
    tasts_t m_tasks;
    int m_index = 0;
    int m_right = 0;
};
