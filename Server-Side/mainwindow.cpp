#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),server()
{
    ui->setupUi(this);

    connect(&server,SIGNAL(toServer(sf::Packet&)),this,SLOT(display(sf::Packet&)),Qt::BlockingQueuedConnection);
    connect(&server,SIGNAL(sendClientList(sf::Packet&)),this,SLOT(getClientList(sf::Packet&)),Qt::BlockingQueuedConnection);
    connect(&server,SIGNAL(sendConversation(sf::Packet&)),this,SLOT(getConversation(sf::Packet&)),Qt::BlockingQueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(sf::Packet& packet)
{
    std::string m;
    sf::Int32 i;
    packet >> i >> m;
    if ( i == 0 )
    {
        ui->clientList->addItem(QString::fromStdString(m));
    }
    else if ( i == 1 )
    {
        ui->chatWindow->append(QString::fromStdString(m));
    }
    else if ( i == 3 )
    {
        qDeleteAll(ui->clientList->findItems(QString::fromStdString(m), Qt::MatchCaseSensitive));
        ui->chatWindow->append(QString::fromStdString(m) + " has left the room");
    }
    packet << i << m;
}

void MainWindow::getClientList(sf::Packet& packet)
{
    packet << 4;
    for ( int a = 0; a < ui->clientList->count(); a++ )
    {
       packet << ui->clientList->item(a)->text().toStdString();
    }
}

void MainWindow::getConversation(sf::Packet& packet)
{
    if ( !ui->chatWindow->toPlainText().isEmpty() )
    {
        packet << 1;
        packet << ui->chatWindow->toPlainText().toStdString();
    }
    else
        packet << 5;
}
