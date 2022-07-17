#include "practiceoptions.h"
#include "ui_practiceoptions.h"

PracticeOptions::PracticeOptions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PracticeOptions)
{
    ui->setupUi(this);
}

PracticeOptions::~PracticeOptions()
{
    delete ui;
}

void PracticeOptions::on_pushButton_clicked() // Should it go to a page by default?
{
}


void PracticeOptions::on_pushButtonSubmit_clicked()
{
    if(ui->radioButtonInt->isChecked()){
        interviewOptions->show();
        this->hide();
    }else if (ui->radioButtonPubSp->isChecked()){
        publicSpeaking->show();
        this->hide();
    }
}

