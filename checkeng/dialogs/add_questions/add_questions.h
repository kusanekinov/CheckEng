#pragma once
#include "add_questinons_pch.h"
#include "add_questinons_global.h"

namespace Ui {
    class Add_questinons;
}

class ADD_QUESTIONS_DIALOG_SHARED_EXPORT Add_questinonsDialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Add_questinonsDialog)

public:
    using class_name = add_AuestinonsDialog;
    using inherited  = QDialog;

public:
    explicit Add_questinonsDialog(QWidget* parent = nullptr);
    ~Add_questinonsDialog() override;

private:
    Ui::Add_questinons* ui = nullptr;
};
