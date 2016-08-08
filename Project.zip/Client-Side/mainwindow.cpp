#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),client(new ClientManager),thread(&receiveMessage,this)
{
    ui->setupUi(this);

    Login login;
    login.exec();

    if ( client->connectToServer() )
    {
        connect(ui->disconnect,SIGNAL(pressed()),this,SLOT(dc()));
        connect(client,SIGNAL(displayMessage(sf::Packet&)),this,SLOT(displayMessage(sf::Packet&)),Qt::BlockingQueuedConnection);
        connect(ui->messageBox,SIGNAL(readyToSendMessage()),this,SLOT(sendMessage()));

        ui->clientList->addItem(Login::name);
    }


    thread.launch();



}

MainWindow::~MainWindow()
{
    delete client;
    client = nullptr;
    delete ui;
}




void MainWindow::sendMessage()
{
   sf::Packet packet;
   std::string message = Login::name.toStdString() + ": " + ui->messageBox->toPlainText().toStdString();
   ui->chatWindow->append(QString::fromStdString(message));
   packet << 1 << message;
   ui->messageBox->clear();
   client->sendMessage(packet);

}

void MainWindow::receiveMessage()
{
    while(true)
    {
        client->receiveMessage();
    }
}

void MainWindow::displayMessage(sf::Packet& packet)
{
    std::string message;
    sf::Int32 identifier;
    packet >> identifier;
    if ( identifier != 5 )
    qDebug() << identifier;
    if ( identifier == 4 ) /// for new client
    {
        while(packet >> message)
        {
            ui->clientList->insertItem(ui->clientList->count()-1,QString::fromStdString(message));
        }

    }
    else
    {
        packet >> message;
        if ( identifier == 0 ) /// someone joins the room
        {
            ui->clientList->addItem(QString::fromStdString(message));
        }
        else if ( identifier == 1 ) /// message
        {
            ui->chatWindow->append(QString::fromStdString(message));
        }
        else if ( identifier == 3 ) /// someone left the room
        {
            ui->chatWindow->append(QString::fromStdString(message) + " has left the room");
            qDeleteAll(ui->clientList->findItems(QString::fromStdString(message), Qt::MatchCaseSensitive));

        }
        else if ( identifier == 5 ) // 2
        {
            return;
        }
    }

}

void MainWindow::dc()
{
    thread.terminate();
    //disconnect(ui->disconnect,SIGNAL(pressed()),this,SLOT(dc()));
   // disconnect(client,SIGNAL(displayMessage(sf::Packet&)),this,SLOT(displayMessage(sf::Packet&)));
    //disconnect(ui->messageBox,SIGNAL(readyToSendMessage()),this,SLOT(sendMessage()));
    delete client;
    client = nullptr;
}
