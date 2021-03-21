
#pragma once
#include <QValidator>
#include "integer.h"

/** \namespace gt */
namespace gt {

/**
 * \code
    ui->m_login->setValidator(new gt::StrongIntValidator(ui->m_login));
 * \endcode
 **/
class StrongIntValidator: public QValidator {
 public:
    using class_name = StrongIntValidator;
    using inherited  = QValidator;

 public:
    static inline auto isValid(QString const& value, int min, int max) noexcept {
        auto const val = convert::toInt(value);
        return min <= val && val < max;
    }
    static inline auto isValid(QVariant const& value, int min, int max) noexcept {
        return isValid(value.toString(), min, max);
    }

 public:
    explicit StrongIntValidator(int min, int max, QObject* parent = nullptr) noexcept
        : inherited(parent)
        , m_min(min)
        , m_max(max){
    }
    explicit StrongIntValidator(QObject* parent = nullptr) noexcept
        : inherited(parent) {
    }
    virtual State validate(QString& str, int&) const override final {
        if(str.isEmpty())
            return QValidator::Intermediate;

        return isValid(str, m_min, m_max)
              ? QValidator::Acceptable
              : QValidator::Invalid;
    }

 private:
    int m_min = 0;
    int m_max = std::numeric_limits<int>::max();

};
}  // end namespace gt
