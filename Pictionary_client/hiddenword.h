#ifndef HIDDENWORD_H
#define HIDDENWORD_H

#include <QtWidgets>

class HiddenWord : public QWidget
{

    Q_OBJECT

public:
    HiddenWord();

    //Return the hidden word Layout
    QGridLayout* getHiddenWordLayout() const;

    //Return the chose word layout
    QGridLayout* getChoseWordLayout() const;

    //Return the chose button
    QPushButton* getChoseButton() const;

    //Return the chose word QLineEdit
    QLineEdit* getChoseWord() const;

    //Return the hidden word QLineEdit
    QLineEdit* getHiddenWord() const;

    //Enable the ChoseWord Layout to authorize the drawer to chose a word
    void enableChose();

    //Disable the choseWord Layout for guessers
    void disableChose();

private:
    QGridLayout *m_hiddenWordLayout;
    QGridLayout *m_choseWordLayout;
    QLineEdit *m_hiddenWord;
    QLineEdit *m_choseWord;
    QPushButton *m_choseButton;
};

#endif // HIDDENWORD_H
