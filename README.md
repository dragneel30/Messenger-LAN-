# Messenger-LAN-
A simple LAN (Local Area Network) messenger written in C++ using QT framework for GUI and SFML for network

# How to run the project in QT creator
Download the project.zip file

Open the .pro file of both server and client side with QT creator

Note: 

change the port on servermanager.h to any available port.

Example: server.listen(5000) where 5000 is the available port on my computer(my server)

change the port and address on clientmanager.h to any available port and address of server.

Example: client.connect("192.168.1.101",5000) where 5000 is the available port on my computer(my server) and "192.168.1.1" is the
remote address of my computer(my server)



