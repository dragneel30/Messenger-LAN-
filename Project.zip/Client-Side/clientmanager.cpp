#include "clientmanager.h"
#include <QDebug>

ClientManager::ClientManager()
{


}

ClientManager::~ClientManager()
{
    sf::Packet name;
    name  << 3 << Login::name.toStdString();
    if ( sendMessage(name) )
    {
        qDebug() << "Disconnected!";
    }

}

bool ClientManager::connectToServer()
{
    if ( client.connect("192.168.1.101",5000) == 0 )
    {
        sf::Packet name;
        name  << 0 << Login::name.toStdString();
        if ( sendMessage(name) )
        {

        }
        return true;
    }
    return false;
}


void ClientManager::receiveMessage()
{
    sf::Packet packet;
    if ( client.receive(packet) == 0 )
    {
        emit displayMessage(packet);
    }
}

bool ClientManager::sendMessage(sf::Packet &p)
{
    if ( client.send(p) == 0 )
    {
        return true;
    }
    return false;
}



