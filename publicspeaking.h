#ifndef PUBLICSPEAKING_H
#define PUBLICSPEAKING_H

#include <QMainWindow>
#include "pubspeakingprompt.h"

namespace Ui {
class PublicSpeaking;
}

class PublicSpeaking : public QMainWindow
{
    Q_OBJECT

public:
    explicit PublicSpeaking(QWidget *parent = nullptr);
    ~PublicSpeaking();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PublicSpeaking *ui;
    PubSpeakingPrompt *publicSpeakingPrompt = new PubSpeakingPrompt;
};

#endif // PUBLICSPEAKING_H
