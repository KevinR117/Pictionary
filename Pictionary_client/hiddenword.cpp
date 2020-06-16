#include "hiddenword.h"

HiddenWord::HiddenWord()
{
    m_hiddenWordLayout = new QGridLayout();
    m_hiddenWord = new QLineEdit();
    m_hiddenWord->setAlignment(Qt::AlignHCenter);
    m_hiddenWord->setReadOnly(true);

    m_hiddenWordLayout->addWidget(m_hiddenWord, 0, 0);

    m_choseWordLayout = new QGridLayout();
    m_choseWord = new QLineEdit();
    m_choseWord->setReadOnly(true);
    m_choseWord->setPlaceholderText("Choisir un mot");
    m_choseButton = new QPushButton("Choisir");
    m_choseButton->setEnabled(false);

    m_choseWordLayout->addWidget(m_choseWord, 0, 0, 1, 2);
    m_choseWordLayout->addWidget(m_choseButton, 0, 2, 1, 1);

}

QGridLayout* HiddenWord::getHiddenWordLayout() const
{
    return this->m_hiddenWordLayout;
}

QGridLayout* HiddenWord::getChoseWordLayout() const
{
    return this->m_choseWordLayout;
}

QPushButton* HiddenWord::getChoseButton() const
{
    return this->m_choseButton;
}

QLineEdit* HiddenWord::getChoseWord() const
{
    return this->m_choseWord;
}

QLineEdit* HiddenWord::getHiddenWord() const
{
    return this->m_hiddenWord;
}

void HiddenWord::enableChose()
{
    this->m_choseWord->setReadOnly(false);
    this->m_choseButton->setEnabled(true);
}

void HiddenWord::disableChose()
{
    this->m_choseWord->setReadOnly(true);
    this->m_choseButton->setEnabled(false);
}
