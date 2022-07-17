#include "thankyouscreen.h"
#include "ui_thankyouscreen.h"

ThankYouScreen::ThankYouScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThankYouScreen)
{
    ui->setupUi(this);
}

ThankYouScreen::~ThankYouScreen()
{
    delete ui;
}
