#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "clientmanager.h"
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
    ClientManager* client;

    sf::Thread thread;


    void receiveMessage();
private slots:
    void sendMessage();
    void displayMessage(sf::Packet&);

    void dc();



};

#endif // MAINWINDOW_H
