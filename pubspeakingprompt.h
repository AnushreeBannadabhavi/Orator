#ifndef PUBSPEAKINGPROMPT_H
#define PUBSPEAKINGPROMPT_H

#include <QMainWindow>
#include "promptscreen.h"

namespace Ui {
class PubSpeakingPrompt;
}

class PubSpeakingPrompt : public QMainWindow
{
    Q_OBJECT

public:
    explicit PubSpeakingPrompt(QWidget *parent = nullptr);
    ~PubSpeakingPrompt();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButtonNo_clicked();

private:
    Ui::PubSpeakingPrompt *ui;
    PromptScreen *promptScreen = new PromptScreen;
};

#endif // PUBSPEAKINGPROMPT_H
