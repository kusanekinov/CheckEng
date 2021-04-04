#pragma once
#include <QTranslator>
#include <QApplication>
#include "language.h"
#include "settings.h"
#include "program.h"
#include <QDebug>

class App final: public QApplication {
public:
    using class_name = App;
    using inherited  = QApplication;

public:
    static void setLanguage(uint lang) noexcept {
        gt::options::Language::setCurrent(lang);
        instanceLanguage();
    }
    static void instanceLanguage() noexcept {
        auto&& lang = gt::options::Language::currentBcp47Name();
        inherited::removeTranslator(tr());
        if(!tr()->load(lang, program::paths::langs()))
            qDebug() << "Can't load translation file" << lang << "from a directory" << program::paths::langs();
        inherited::installTranslator(tr());
        QLocale::setDefault(gt::options::Language::current().lang());
    }

public:
    explicit App(int& argc, char** argv) noexcept
        :inherited(argc, argv) {
        init();
        instanceLanguage();
    }
    void init() {
        QCoreApplication::setOrganizationName(program::organizationName());
        QCoreApplication::setOrganizationDomain(program::organizationDomain());
        QCoreApplication::setApplicationName(program::regName());
        QCoreApplication::setApplicationVersion(program::version());
    }
    static QTranslator* tr() noexcept {
        static QTranslator tr;
        return &tr;
    }
    static gt::Settings* settings() noexcept {
        static gt::Settings settings;
        return &settings;
    }
    static void exit() noexcept {
        inherited::exit();
    }
    static void quit() noexcept {
        inherited::instance()->quit();
    }
    static QString exeName() noexcept {
        auto const& data = inherited::arguments();
        return data.first();
    }
};
