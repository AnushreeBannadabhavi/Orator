#ifndef THANKYOUSCREEN_H
#define THANKYOUSCREEN_H

#include <QMainWindow>

namespace Ui {
class ThankYouScreen;
}

class ThankYouScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThankYouScreen(QWidget *parent = nullptr);
    ~ThankYouScreen();

private:
    Ui::ThankYouScreen *ui;
};

#endif // THANKYOUSCREEN_H
