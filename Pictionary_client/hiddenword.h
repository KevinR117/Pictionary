#ifndef HIDDENWORD_H
#define HIDDENWORD_H

#include <QtWidgets>

class HiddenWord : public QObject
{

    Q_OBJECT

public:
    HiddenWord();

private:
    QGridLayout *m_hiddenWordLayout;
    QString m_word;
    QLineEdit *m_hiddenWord;
};

#endif // HIDDENWORD_H
