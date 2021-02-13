#pragma once
#include <QDialog>

namespace Ui { class LoginDialog; }

class LoginDialog: public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(LoginDialog)

 public:
    using class_name = LoginDialog;
    using inherited  = QDialog;

 public:
    explicit LoginDialog(QWidget* parent = nullptr);
    virtual ~LoginDialog() override;


 private slots:
    bool onChanged() noexcept;
    void onAccepted() noexcept;

 private:
    std::unique_ptr<Ui::LoginDialog> ui;
};
