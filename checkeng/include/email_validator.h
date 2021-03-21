#pragma once
#include <QRegExp>
#include <QRegExpValidator>

/** \namespace gt */
namespace gt {

class EmailValidator : public QRegExpValidator {
public:
    using class_name = EmailValidator;
    using inherited  = QRegExpValidator;

public:
    static inline QString email() noexcept {
        return QStringLiteral("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    }
    static inline auto emailReg() noexcept {
        QRegExp reg(email());
        reg.setCaseSensitivity(Qt::CaseInsensitive);
        reg.setPatternSyntax(QRegExp::RegExp);
        return reg;
    }
    static inline auto isValid(QString const& value) noexcept {
        auto const& reg = emailReg();
        return reg.exactMatch(value);
    }
    static inline auto isValid(QVariant const& value) noexcept {
        return isValid(value.toString());
    }

public:
    explicit EmailValidator(QObject* parent = nullptr) noexcept
        : inherited(emailReg(), parent) {
    }
}; 
} // end namespace gt
