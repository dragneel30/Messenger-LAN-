#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "servermanager.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ServerManager server;
private slots:
    void display(sf::Packet&);
    void getClientList(sf::Packet&);



    //////////////////



    void getConversation(sf::Packet&);




    ///////////////////





};

#endif // MAINWINDOW_H
