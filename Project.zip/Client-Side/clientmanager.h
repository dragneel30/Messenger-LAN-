#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <SFML/Network.hpp>
#include "login.h"
class ClientManager : public QObject
{
    Q_OBJECT
public:
    ClientManager();
    ~ClientManager();

    bool connectToServer();
    void receiveMessage();

    bool sendMessage(sf::Packet& p);

private:
    sf::TcpSocket client;

signals:
    void displayMessage(sf::Packet&);

};

#endif // CLIENTMANAGER_H
