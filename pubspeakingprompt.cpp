#include "pubspeakingprompt.h"
#include "ui_pubspeakingprompt.h"
#include "permissionpage.h"

PubSpeakingPrompt::PubSpeakingPrompt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PubSpeakingPrompt)
{
    ui->setupUi(this);
}

PubSpeakingPrompt::~PubSpeakingPrompt()
{
    delete ui;
}

void PubSpeakingPrompt::on_pushButton_2_clicked()
{
    promptScreen->show();
    this->hide();
}


void PubSpeakingPrompt::on_pushButtonNo_clicked()
{
    PermissionPage *permissionPage = new PermissionPage(0, false);
    permissionPage->show();//TODO: add back button
    this->hide();
}

