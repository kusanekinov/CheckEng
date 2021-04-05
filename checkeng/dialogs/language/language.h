#pragma once
#include "language_pch.h"
#include "language_global.h"

namespace Ui {
    class Language;
}

class LANGUAGE_DIALOG_SHARED_EXPORT LanguageDialog final: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(LanguageDialog)

public:
    using class_name = LanguageDialog;
    using inherited  = QDialog;

public:
    explicit LanguageDialog(uint current, QWidget* parent = nullptr);
    ~LanguageDialog() override;
    uint current() const;

private slots:
    void onChangeClicked();

private:
    Ui::Language* ui = nullptr;
    uint m_current;
};
