#include <QString>

class Task final {
 public:
    using class_name = Task;


 public:
    explicit Task(QString const& question, QString const& answer1, QString const& answer2, QString const& answer3) noexcept
        : m_question(question)
        , m_answer1(answer1)
        , m_answer2(answer2)
        , m_answer3(answer3) {
    }
    QString const& question() const noexcept {
        return m_question;
    }
    void setQuestion(QString const& question) noexcept {
        m_question = question;
    }
    QString const& answer1() const noexcept {
        return m_answer1;
    }
    void setAnswer1(QString const& answer1) noexcept {
        m_answer1 = answer1;
    }
    QString const& answer2() const noexcept {
        return m_answer2;
    }
    void setAnswer2(QString const& answer2) noexcept {
        m_answer2 = answer2;
    }
    QString const& answer3() const noexcept {
        return m_answer3;
    }
    void setAnswer3(QString const& answer3) noexcept {
        m_answer3 = answer3;
    }
    friend bool operator==(class_name const& lhs, class_name const& rhs) noexcept {
        return lhs.m_question == rhs.m_question
            && lhs.m_answer1  == rhs.m_answer1 
            && lhs.m_answer2  == rhs.m_answer2 
            && lhs.m_answer3  == rhs.m_answer3 
           ;
    }
    friend bool operator!=(class_name const& lhs, class_name const& rhs) noexcept {
        return !(lhs == rhs);
    }

 private: 
    QString m_question;
    QString m_answer1;
    QString m_answer2;
    QString m_answer3;
};
