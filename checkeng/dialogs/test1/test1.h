#pragma once
#include "test1_pch.h"
#include "test1_global.h"

namespace Ui {
    class Test1;
}

class TEST1_DIALOG_SHARED_EXPORT Test1Dialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Test1Dialog)

public:
    using class_name = Test1Dialog;
    using inherited  = QDialog;

public:
    explicit Test1Dialog(QString const& name, int right, int total, QWidget* parent = nullptr);
    ~Test1Dialog() override;

private:
    Ui::Test1* ui = nullptr;
};
