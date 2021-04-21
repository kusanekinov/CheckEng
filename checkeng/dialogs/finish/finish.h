#pragma once
#include "finish_pch.h"
#include "finish_global.h"
#include "include/answer.h"

namespace Ui {
    class Finish;
}

class FINISH_DIALOG_SHARED_EXPORT FinishDialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(FinishDialog)

public:
    using class_name = FinishDialog;
    using inherited  = QDialog;

public:
    explicit FinishDialog(int right, int total, QVector<Answer> const& answers, QString const& name, QWidget* parent = nullptr);
    ~FinishDialog() override;

private:
    void printAnswers(QVector<Answer> const& answers) noexcept;

private:
    Ui::Finish* ui = nullptr;
};
