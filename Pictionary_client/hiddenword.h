#ifndef HIDDENWORD_H
#define HIDDENWORD_H

#include <QtWidgets>

class HiddenWord : public QObject
{

    Q_OBJECT

public:
    HiddenWord();

    //Return the hidden word Layout
    QGridLayout* getHiddenWordLayout() const;

    //Return the chose word layout
    QGridLayout* getChoseWordLayout() const;

    //Configure the m_hiddenWord attribute with the word choosen by the drawer
    void hideWord(const QString &word);

private:
    QGridLayout *m_hiddenWordLayout;
    QGridLayout *m_choseWordLayout;
    QLineEdit *m_hiddenWord;
    QLineEdit *m_choseWord;
    QPushButton *m_choseButton;
};

#endif // HIDDENWORD_H
