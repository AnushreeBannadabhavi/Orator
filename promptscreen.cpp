#include "promptscreen.h"
#include "ui_promptscreen.h"
#include "permissionpage.h"
#include <random>

PromptScreen::PromptScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PromptScreen)
{
    ui->setupUi(this);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,prompts.size()-1);
    ui->label->setText(prompts[uni(rng)]);
    ui->label->setStyleSheet("QLabel { background-color : black; color : white; }");
}

PromptScreen::~PromptScreen()
{
    delete ui;
}


void PromptScreen::on_pushButtonBegin_clicked()
{
    PermissionPage *permissionPage = new PermissionPage(0, false);
    permissionPage->show();
    //publicSpeakingStart->show(); //TODO: add back button
    this->hide();
}

