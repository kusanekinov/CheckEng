#ifndef ONE_OF_THREE_H
#define ONE_OF_THREE_H

#include <QWidget>

namespace Ui {
class OneOfThree;
}

class OneOfThree : public QWidget
{
    Q_OBJECT

public:
    explicit OneOfThree(QWidget *parent = nullptr);
    ~OneOfThree();

private:
    Ui::OneOfThree *ui;
};

#endif // ONE_OF_THREE_H
