#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    static QString name;
    //static QString getName();
private slots:
    void on_okay_clicked();

    void on_cancel_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
