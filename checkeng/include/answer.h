#pragma once
#include <QString>

class Answer final {
 public:
    using class_name = Answer;
     

 public:
    explicit Answer(QString const& question, QString const& right, QString const& answer) noexcept 
        : m_question(question)
        , m_right(right)
        , m_answer(answer) {
    }
    QString const& question() const noexcept {
        return m_question;
    }
    void setQuestion(QString const& question) noexcept {
        m_question = question;
    }
    void setQuestion(QString&& question) noexcept {
        m_question = qMove(question);
    }
    QString const& right() const noexcept {
        return m_right;
    }
    void setRight(QString const& right) noexcept {
        m_right = right;
    }
    void setRight(QString&& right) noexcept {
        m_right = qMove(right);
    }
    QString const& answer() const noexcept {
        return m_answer;
    }
    void setAnswer(QString const& answer) noexcept {
        m_answer = answer;
    }
    void setAnswer(QString&& answer) noexcept {
        m_answer = qMove(answer);
    }
    friend bool operator==(class_name const& lhs, class_name const& rhs) noexcept {
        return lhs.m_question == rhs.m_question
            && lhs.m_right    == rhs.m_right
            && lhs.m_answer   == rhs.m_answer
           ;
    }
    friend bool operator!=(class_name const& lhs, class_name const& rhs) noexcept {
        return !(lhs == rhs);
    }

 private: 
    QString m_question;
    QString m_right;
    QString m_answer; 
};

