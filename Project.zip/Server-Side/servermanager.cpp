#include "servermanager.h"


ServerManager::ServerManager()
    :thread(&startServer,this),server(),selector(),clients()
{
    if ( server.listen(5000) == sf::Socket::Done )
    {
        selector.add(server);
        thread.launch();
    }
}


void ServerManager::startServer()
{
    while(true)
    {
        if ( selector.wait() )
        {
            if ( selector.isReady(server) )
            {
                acceptClientConnection();
                receivePacketFromClient(clients.end()-1);
                if ( clients.size() > 1 )
                    sendPacketToNewClient();
            }
            else
            {
                receivePacketFromClient(clients.begin());
                removeDisconnectedClient();
            }
        }
    }
}

void ServerManager::acceptClientConnection()
{
    sf::TcpSocket* newClient = new sf::TcpSocket;
    if ( server.accept(*newClient) == sf::Socket::Done )
    {
        clients.push_back(newClient);
        selector.add(*newClient);

    }
    else
    {
        delete newClient;
        newClient = nullptr;
    }
}

void ServerManager::receivePacketFromClient(std::vector<sf::TcpSocket*>::iterator iter_start)
{
    for ( std::vector<sf::TcpSocket*>::iterator iter = iter_start; iter != clients.end(); iter++ )
    {
        if ( selector.isReady(**iter) )
        {
            sf::Packet packet;
            if ( (*iter)->receive(packet) == sf::Socket::Done )
            {
                emit toServer(packet);
                sendPacketToClient(iter,packet);
            }
            return;
        }
    }
}

void ServerManager::sendPacketToClient(std::vector<sf::TcpSocket*>::iterator& sender,sf::Packet& packet)
{

    for ( std::vector<sf::TcpSocket*>::iterator iter = clients.begin(); iter != clients.end(); iter++ )
    {
            if ( sender != iter )
            {
                if ( (*iter)->send(packet) == sf::Socket::Done )
                {

                }
            }
    }
}

void ServerManager::removeDisconnectedClient()
{
    sf::Packet packet;
    packet << 5;
    for ( unsigned a = 0; a < clients.size(); a++ )
    {
        if ( clients[a]->send(packet) == sf::Socket::Disconnected )
        {
            selector.remove(*clients[a]);
            delete clients[a];
            clients[a] = nullptr;
            clients.erase(clients.begin()+a);
        }
    }
}

void ServerManager::sendPacketToNewClient()
{
        std::array<sf::Packet,2> packets;
        emit sendConversation(packets[0]);
        emit sendClientList(packets[1]);
        for ( unsigned a = 0; a < packets.size(); a++ )
        {
            if ( clients[clients.size()-1]->send(packets[a]) == sf::Socket::Done )
            {
            }
        }
}




