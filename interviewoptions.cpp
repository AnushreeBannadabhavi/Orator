#include "interviewoptions.h"
#include "ui_interviewoptions.h"
#include "permissionpage.h"

InterviewOptions::InterviewOptions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterviewOptions)
{
    ui->setupUi(this);
    //ui->label->setStyleSheet("QLabel { background-color : black; color : white; }");
    ui->radioButtonEasy->setStyleSheet("QRadioButton { background-color : black; color : white; }");
    ui->radioButtonHard->setStyleSheet("QRadioButton { background-color : black; color : white; }");
    ui->radioButtonMedium->setStyleSheet("QRadioButton { background-color : black; color : white; }");
}

InterviewOptions::~InterviewOptions()
{
    delete ui;
}

void InterviewOptions::on_pushButton_clicked()
{}


void InterviewOptions::on_pushButtonStart_clicked()
{
    // TODO : For any option chosen: Easy, medium, hard it is the same code now. Change this later
    if(ui->radioButtonEasy->isChecked()){
        PermissionPage *permissionPage = new PermissionPage(0, true);
        permissionPage->show();//TODO: add back button
        this->hide();
    }else if(ui->radioButtonMedium->isChecked()){
        PermissionPage *permissionPage = new PermissionPage(0, true);
        permissionPage->show();//TODO: add back button
        this->hide();
    }else if(ui->radioButtonHard->isChecked()){
        PermissionPage *permissionPage = new PermissionPage(0, true);
        permissionPage->show();//TODO: add back button
        this->hide();
    }
}

