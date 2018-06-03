#ifndef DIALOGSAVE_H
#define DIALOGSAVE_H

#include <QDialog>

namespace Ui {
class dialogsave;
}

class dialogsave : public QDialog
{
    Q_OBJECT

public:
    explicit dialogsave(QWidget *parent = 0);
    ~dialogsave();

private:
    Ui::dialogsave *ui;
};

#endif // DIALOGSAVE_H
