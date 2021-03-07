#pragma once
#include <QWidget>
#include "task.h"
#include <QPushButton>

namespace Ui {
    class OneOfThreeWidget;
}

class OneOfThreeWidget: public QWidget {
    Q_OBJECT

public:
   using tasts_t = QList<Task>;

public:
    explicit OneOfThreeWidget(QWidget* parent = nullptr);
    ~OneOfThreeWidget();
    void start(QString const& name);

private:
   void answer(QPushButton* btn);
   void nextTask();
   void randomize(QString const& first, QString const& second, QString const& third);

private:
    void onFirstAnswerClick();
    void onSecondAnswerClick();
    void onThirdAnswerClick();

private:
   Ui::OneOfThreeWidget* ui = nullptr;
   tasts_t m_tasks;
   int m_index = 0;
   int m_right = 0;
   QString m_name;
};

