#pragma once
#include "test1_pch.h"
#include "test1_global.h"
#include <QList>
#include <QLabel>
#include "task.h"
#include "include/answer.h"

namespace Ui {
    class Test1;
}

class TEST1_DIALOG_SHARED_EXPORT Test1Dialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Test1Dialog)

public:
    using class_name = Test1Dialog;
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
    explicit Test1Dialog(QString const& file, QString const& name, QWidget* parent = nullptr);
    ~Test1Dialog() override;
    void start();

private:
    Ui::Test1* ui = nullptr;
    QString m_filename;
    QString m_name;
    tasts_t m_tasks;
    int m_index = 0;
    int m_right = 0;
    QVector<Answer> m_answers;
};
