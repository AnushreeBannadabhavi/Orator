#include "permissionpage.h"
#include "ui_permissionpage.h"
#include "interviewstart.h"

PermissionPage::PermissionPage(QWidget *parent, bool isInterview) :
    QMainWindow(parent),
    ui(new Ui::PermissionPage)
{
    ui->setupUi(this);
    m_isInterview = isInterview;
}

PermissionPage::~PermissionPage()
{
    delete ui;
}

void PermissionPage::on_IAgree_clicked()
{
    if(!m_isInterview){
        PubSpStart *publicSpeakingStart = new PubSpStart(0,true);
        publicSpeakingStart->show();
        this->hide();
    } else {
        InterviewStart *interviewStart = new InterviewStart(0, true);
        interviewStart->show();
        this->hide();
    }
}


void PermissionPage::on_pushButton_2_clicked()
{
    if(!m_isInterview){
        PubSpStart *publicSpeakingStart = new PubSpStart(0,false);
        publicSpeakingStart->show();
        this->hide();
    } else {
        InterviewStart *interviewStart = new InterviewStart(0, false);//TODO
        interviewStart->show();
        this->hide();
    }
}

