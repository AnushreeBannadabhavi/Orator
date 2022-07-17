#include "publicspeaking.h"
#include "ui_publicspeaking.h"

PublicSpeaking::PublicSpeaking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PublicSpeaking)
{
    ui->setupUi(this);
}

PublicSpeaking::~PublicSpeaking()
{
    delete ui;
}

void PublicSpeaking::on_pushButton_clicked()
{
    if(ui->radioButtonAudi->isChecked()){
        publicSpeakingPrompt->show();
        this->hide();
        //TODO : Change output of the projector
    }else if (ui->radioButtonCC->isChecked()){
        publicSpeakingPrompt->show();
        this->hide();
        //TODO : Change output of the projector
    }else if (ui->radioButtonClass->isChecked()){
        publicSpeakingPrompt->show();
        this->hide();
        //TODO : Change output of the projector
    }
}

