
#pragma once
#include <QValidator>

/** \namespace gt */
namespace gt {

/**
 * \code
    ui->m_name->setValidator(new gt::PassValidator(ui->m_name));
 * \endcode
 **/
class PassValidator final: public QValidator {
public:
    using class_name = PassValidator;
    using inherited  = QValidator;

public:
    static inline auto isValid(QString const& value) noexcept {
        for(auto const ch: value)
            if(ch.toLatin1() == 0 || ch.isSpace())
                return false;
        return true;
    }
    static inline auto isValid(QVariant const& value) noexcept {
        return isValid(value.toString());
    }

public:
    explicit PassValidator(QObject* parent = nullptr) noexcept
        : inherited(parent) {
    }
    virtual State validate(QString& str, int& pos) const override final {
        if(pos < 0 || pos > str.length())
            return QValidator::Invalid;
        return isValid(str)
              ? QValidator::Acceptable
              : QValidator::Invalid;
    }
};
}  // end namespace gt

