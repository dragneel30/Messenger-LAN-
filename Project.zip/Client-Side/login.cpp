#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
QString Login::name;
/*
QString Login::getName()
{
    return name;
}
*/
void Login::on_okay_clicked()
{
    name = ui->name->text();
    this->close();
}

void Login::on_cancel_clicked()
{
    this->close();
}
