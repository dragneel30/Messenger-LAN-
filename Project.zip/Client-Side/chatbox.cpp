#include "chatbox.h"

ChatBox::ChatBox(QWidget* widget)
    : QTextEdit(widget)
{
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

void ChatBox::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter ) // 16777220 || 16777221
    {
        if ( toPlainText().isEmpty() )
        {
            clear();
        }
        else
        {
            emit readyToSendMessage();
        }
    }
    else
    {
        QTextEdit::keyPressEvent(event);
    }
}

