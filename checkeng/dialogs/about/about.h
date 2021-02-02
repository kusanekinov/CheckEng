#pragma once
#include "about_pch.h"
#include "about_global.h"

namespace Ui {
    class About;
}

class ABOUT_DIALOG_SHARED_EXPORT AboutDialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(AboutDialog)

public:
    using class_name = AboutDialog;
    using inherited  = QDialog;

public:
    explicit AboutDialog(QWidget* parent = nullptr);
    ~AboutDialog() override;

private:
    Ui::About* ui = nullptr;
};
