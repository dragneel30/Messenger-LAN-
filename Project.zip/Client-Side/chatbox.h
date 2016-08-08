#ifndef CHATBOX_H
#define CHATBOX_H

#include "QTextEdit"
#include <SFML/Network.hpp>
#include <QString>
#include <QKeyEvent>
#include <QDebug>

class ChatBox : public QTextEdit
{
    Q_OBJECT
public:
    ~ChatBox() {}
    ChatBox(QWidget* widget = 0);
    void keyPressEvent(QKeyEvent *event);

signals:
    void readyToSendMessage();
};
#endif // CHATBOX_H
