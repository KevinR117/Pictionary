#ifndef CHAT_H
#define CHAT_H

#include <QtWidgets>

class Chat : public QWidget
{

    Q_OBJECT

public:
    Chat();

    //Return the chat Layout
    QGridLayout* getChatLayout() const;

    //Return the send button
    QPushButton* getSendButton() const;

    //Return the message which have to be sent to the server
    QLineEdit* getMyMessage() const;

    //Return the lists of messages already sent before
    QTextEdit* getMessages() const;

private:
    QGridLayout *m_chatLayout;
    QTextEdit *m_messages;
    QLineEdit *m_myMessage;
    QPushButton *m_sendButton;
};

#endif // CHAT_H
