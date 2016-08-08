#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <SFML/Network.hpp>
#include <vector>

#include <QDebug>
class ServerManager : public QObject
{
    Q_OBJECT
public:
    ServerManager();

    void startServerThread();

private:
    void startServer();
    void acceptClientConnection();
    void receivePacketFromClient(std::vector<sf::TcpSocket*>::iterator);
    void sendPacketToClient(std::vector<sf::TcpSocket*>::iterator&,sf::Packet&);
    void removeDisconnectedClient();
    sf::Thread thread;

    sf::TcpListener server;
    sf::SocketSelector selector;
    std::vector<sf::TcpSocket*> clients;


    void sendPacketToNewClient();


signals:
    void toServer(sf::Packet&);

    void sendClientList(sf::Packet&);
    void sendConversation(sf::Packet&);
};

#endif // SERVERMANAGER_H
