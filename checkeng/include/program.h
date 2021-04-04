#pragma once
#include <QDir>
#include <QDate>
#include <QSettings>
#include <QFileInfo>
#include <QCoreApplication>
#include "typedefs.h"
#include <QLocale>

#define HOME_PATH(str) program::homeFolder() + GT_STR(str);
/**
 * \code
 *      program::fullName();
 * \endcode
**/
namespace program {
    inline QString setupName() noexcept {
        return GT_STR("checkeng.exe");
    }
    inline QString name() noexcept {
        return GT_STR("CheckEng");
    }
    inline QString regName() noexcept {
        return GT_STR("CheckEng");
    }
    inline QString productName() noexcept {
        return GT_STR("CheckEng");
    }
    inline QString build() noexcept {
        return GT_STR("5678");
    }
    inline QString version() noexcept {
        return QStringLiteral("%1.%2")
                .arg(1)
                .arg(1);
    }
    inline QString fullProductName() noexcept {
        return GT_STR("%1 %2 %3")
               .arg(productName())
               .arg(version())
               .arg(build());
    }
    inline QString fullName() noexcept {
        return GT_STR("%1 %2")
               .arg(name())
               .arg(version());
    }
    inline QString date() noexcept {
        return GT_STR(__DATE__);
       // return QDate::fromString(QString::fromUtf8(__DATE__), GT_STR("MMM dd yyyy")).toString(Qt::ISODate);
    }
    inline QString fullVersion() noexcept {
        return GT_STR("%1 %2, build %3 (%4)")
                .arg(name())
                .arg(version())
                .arg(build())
                .arg(date());
    }
    inline QString organizationName() noexcept {
        return GT_STR("CheckEng");
    }
    inline QString organizationDomain() noexcept {
        return GT_STR("checkeng.ru");
    }
    inline QString homeFolder() noexcept {
        return QDir::home().absolutePath() + GT_STR("/checkeng_tests");
    }
    inline QString help() noexcept {
        return GT_APP_PATH("/Help/Help.chm")
    }
    inline QString author() noexcept {
        return GT_STR("Vlad Panin");
    }
    inline QString copyright() noexcept {
        return GT_STR("Copyright (c) 2018-2021, Vlad panin. All rights reserved.");
    }
    inline QString homepage() noexcept {
        return GT_STR("ya.ru");
    }
    inline QString logFile() noexcept {
#if defined(Q_OS_LINUX)
        return GT_STR("/var/log/checkeng.log");
#endif
        return HOME_PATH("/log.txt")
    }
    inline QString supportMail() noexcept {
        return GT_STR("suppor@checkeng.ru");
    }
    /** \namespace registry */
    namespace registry {
        inline QString software() noexcept {
            return GT_STR("HKEY_CURRENT_USER\\SOFTWARE");
        }
    } // end namespace registry
    namespace paths {
        inline auto langs() noexcept -> QString {
            return GT_APP_PATH("/langs");
        }
        inline auto translations() noexcept -> QString {
            return GT_APP_PATH("/translations")
        }
        inline auto test1() noexcept -> QString {
            return HOME_PATH("/test1");
        }
        inline auto test2() noexcept -> QString {
            return HOME_PATH("/test2");
        }
    }
}
