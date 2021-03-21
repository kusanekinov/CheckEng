#pragma once
#include <QLineEdit>
#include <QTextEdit>
#include <QHostAddress>
#include "string_algo.h"
#include "string.h"
#include "login_validator.h"
#include "english_validator.h"
#include "pass_validator.h"
#include "email_validator.h"
#include "num_validator.h"
#include "port_validator.h"
#include "ip_validator.h"

/** \namespace gt::checker */
namespace gt::checker {
    static inline bool textSize(QString const& text, int min, int max) noexcept {
        auto const s = gt::trim(text).size();
        return min <= s && s <= max;
    }
    template <class T>
    static inline bool textSize(T* e, int min, int max) noexcept {
        auto const s = gt::trim(e).size();
        return min <= s && s <= max;
    }
    template <class T>
    static inline bool Int(T* e, int min, int max) noexcept {
        auto const& s = gt::trim(e);
        auto const val = gt::convert::toInt(s);
        return min <= val && val < max;
    }
    template <class T>
    static inline bool Uint(T* e, int min, int max) noexcept {
        auto const& s = gt::trim(e);
        auto const val = gt::convert::toUint(s);
        return min <= val && val < max;
    }
    template <class T>
    static inline bool Double(T* e, int min, int max) noexcept {
        auto const& s = gt::trim(e);
        auto const val = gt::convert::toDouble(s);
        return min <= val && val < max;
    }
    template <class T>
    static inline bool login(T* e) noexcept {
        return textSize(e, 3, 32)
            && gt::LoginValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool loginEmpty(T* e) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return textSize(e, 0, 32)
            && gt::LoginValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool num(T* e) noexcept {
        return textSize(e, 1, 5)
                && gt::NumValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool name(T* e) noexcept {
        return textSize(e, 3, 64);
    }
    template <class T>
    static inline bool emptyName(T* e) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return textSize(e, 0, 64);
    }
    template <class T>
    static inline bool english(T* e, int min, int max) noexcept {
        return textSize(e, min, max)
                && gt::EnglishValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool englishEmpty(T* e, int max) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return textSize(e, 0, max)
                && gt::EnglishValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool pass(T* e) noexcept {
        return textSize(e, 3, 64) && 
            gt::PassValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool passEmpty(T* e) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return textSize(e, 0, 64) && 
            gt::PassValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool desc(T* e) noexcept {
        return textSize(e, 0, 256);
    }
    template <class T>
    static inline bool email(T* e) noexcept {
        return gt::EmailValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool emailEmpty(T* e) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return gt::EmailValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool ip(T* e) noexcept {
        return gt::IpValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool ipEmpty(T* e) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return gt::IpValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool port(T* e) noexcept {
        return gt::PortValidator::isValid(gt::trim(e));
    }
    template <class T>
    static inline bool portEmpty(T* e) noexcept {
        if(gt::trim(e).isEmpty())
            return true;

        return gt::PortValidator::isValid(gt::trim(e));
    }

}  // end namespace gt::checker
