#include "chat.h"

Chat::Chat() : QWidget()
{
    m_chatLayout = new QGridLayout();
    m_messages = new QTextEdit();
    m_messages->setReadOnly(true);
    m_myMessage = new QLineEdit();
    m_myMessage->setPlaceholderText(tr("Message"));
    m_sendButton = new QPushButton("Envoyer");

    m_chatLayout->addWidget(m_messages, 0, 0, 9, 3);
    m_chatLayout->addWidget(m_myMessage, 10, 0, 1, 2);
    m_chatLayout->addWidget(m_sendButton, 10, 2, 1, 1);
}

QGridLayout* Chat::getChatLayout() const
{
    return this->m_chatLayout;
}

QPushButton* Chat::getSendButton() const
{
    return this->m_sendButton;
}

QTextEdit* Chat::getMessages() const
{
    return this->m_messages;
}

QLineEdit* Chat::getMyMessage() const
{
    return this->m_myMessage;
}
