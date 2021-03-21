
#pragma once
#include "strong_int_validator.h"
#include "integer.h"

/** \namespace gt */
namespace gt {

/**
 * \code
    ui->m_name->setValidator(new gt::NumValidator(ui->m_name));
 * \endcode
 **/
class NumValidator final: public StrongIntValidator {
public:
    using class_name = NumValidator;
    using inherited  = StrongIntValidator;

public:
    static inline auto isValid(QString const& value) noexcept {
        return inherited::isValid(value, 1, 10'001);
    }
    static inline auto isValid(QVariant const& value) noexcept {
        return isValid(value.toString());
    }

public:
    explicit NumValidator(QObject* parent = nullptr) noexcept
        : inherited(1, 10'001, parent) {
    }
};
}  // end namespace gt
