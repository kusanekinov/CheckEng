#pragma once
#include "finish_pch.h"
#include "finish_global.h"

namespace Ui {
    class Finish;
}

class FINISH_SHARED_EXPORTFinishDialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(FinishDialog)

public:
    using class_name = FinishDialog;
    using inherited  = QDialog;

public:
    explicit FinishDialog(QWidget* parent = nullptr);
    ~FinishDialog() override;

private:
    Ui::Finish* ui = nullptr;
};
