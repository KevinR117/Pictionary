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

void HiddenWord::hideWord(const QString &word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if(word[i].isLetter())
        {
            m_hiddenWord->insert("_ ");
        } else if (word[i] == tr(" "))
        {
            m_hiddenWord->insert(tr("   "));
        } else if (word[i] == tr("'"))
        {
            m_hiddenWord->insert(tr("'"));
        } else if (word[i] == "-")
        {
            m_hiddenWord->insert(tr("-"));
        }
    }
}
