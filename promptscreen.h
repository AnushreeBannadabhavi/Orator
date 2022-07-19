#ifndef PROMPTSCREEN_H
#define PROMPTSCREEN_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class PromptScreen;
}

class PromptScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit PromptScreen(QWidget *parent = nullptr);
    ~PromptScreen();

private slots:
    void on_pushButtonBegin_clicked();

private:
    Ui::PromptScreen *ui;
    std::vector<QString> prompts = {
        "In what situation is lying a good idea?",
        "Ignorance is bliss",
        "The world is a smaller place these days",
        "If I ruled the world..."
    };
};

#endif // PROMPTSCREEN_H
