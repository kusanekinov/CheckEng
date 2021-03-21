
#pragma once
#include <QLineEdit>
#include <QTextEdit>
#include "string.h"

/** \namespace gt */
namespace gt {
    static inline QString trim(QString const& e) noexcept {
        return e.trimmed();
    }
    static inline QString trim(QLineEdit* e) noexcept {
        return e->text().trimmed();
    }
    static inline QString trim(QTextEdit* e) noexcept {
       return gt::convert::toPlainText(e->toPlainText()).trimmed();
    }

}  // end namespace gt
