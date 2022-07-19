#include "interviewstart.h"
#include "ui_interviewstart.h"
#include <stdlib.h>
#include <iostream>
#include <random>
#include <QMediaDevices>

#define MAX_INTRO_QUESTIONS 3
#define MAX_QUAL_QUESTIONS 13
#define MAX_SIT_QUESTIONS 18
#define MAX_RAND_QUESTIONS 20

InterviewStart::InterviewStart(QWidget *parent, bool isRecord) :
    QMainWindow(parent),
    ui(new Ui::InterviewStart)
{
    ui->setupUi(this);
    m_isRecord = isRecord;
    m_time.setHMS(0,3,0);
    connect(m_timer, &QTimer::timeout, this, &InterviewStart::updateTime);
    ui->label->setText(m_time.toString("m:ss"));
    chooseInterviewQuestions();
    m_videoFilePath = "D:/UBC_Coursework/Summer/SpeakingSimulator/InterviewVideos/";
    //m_videoFilePath = "C:/work/QT/InterviewVideos/";
    m_player->setVideoOutput(m_videoWidget);
    m_player->setAudioOutput(m_audioOutput);
    m_audioOutput->setVolume(100);

    m_audioInput.reset(new QAudioInput);
    m_recordingSession->setAudioInput(m_audioInput.get());

    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    for (const QCameraDevice &cameraDevice : cameras) {
        //if (cameraDevice.description() == "mycamera")
            m_camera = new QCamera(cameraDevice);
            std::cout << "hi" << std::endl;
    }

    m_recordingSession->setCamera(m_camera);
    m_recordingSession->setRecorder(&m_recorder);
    m_recorder.setQuality(QMediaRecorder::HighQuality);
    m_recorder.setOutputLocation(QUrl::fromLocalFile("D:/UBC_Coursework/Summer/SpeakingSimulator/Recordings/testInterview.mp4"));
    //m_recorder.setOutputLocation(QUrl::fromLocalFile("C:/work/QT/InterviewVideos/Recordings/testInterview.mp4"));

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &InterviewStart::statusChanged);
    ui->label->setStyleSheet("QLabel { background-color : black; color : white; }");
}

InterviewStart::~InterviewStart()
{
    delete ui;
}

void InterviewStart::updateTime(){
    if(m_time.toString("m:ss") == "0:00"){ // Specify time here
        m_timer->stop();
        ui->label->setText(m_time.toString("m:ss"));
        if (m_questionCount < 3){
            ui->pushButtonStartStop->setText("Next Question");
            if(m_questionCount == 2){
                //std::cout << "2222 m_questionCount" << m_questionCount << std::endl;
                ui->pushButtonStartStop->setText("Finish");
            }
            showNextQuestion();
        }
        else{
            m_videoWidget->close();
            if(m_isRecord){
                m_recorder.stop();
            }
            showThankYouScreen();
        }
    } else{
        m_time=m_time.addSecs(-1);
        ui->label->setText(m_time.toString("m:ss"));
    }
}

void InterviewStart::showThankYouScreen()
{
    m_endScreen->show();
    this->hide();
}


void InterviewStart::on_pushButtonStartStop_clicked()
{
    if(!recordingStarted){
        std::cout << recordingStarted << std::endl;
        if(m_isRecord){
            m_camera->start();
            m_recorder.record();
        }
        recordingStarted = true;
    }
    if (m_questionCount < 3){
        //std::cout << "m_questionCount" << m_questionCount << std::endl;
        ui->pushButtonStartStop->setText("Next Question");
        if(m_questionCount == 2){
            //std::cout << "22221111 m_questionCount" << m_questionCount << std::endl;
            ui->pushButtonStartStop->setText("Finish");
        }
        m_timer->stop();
        showNextQuestion();
    }else if (ui->pushButtonStartStop->text() == "Finish" && m_questionCount == 3){
        m_timer->stop();
        if(m_isRecord){
            m_recorder.stop();
        }
        ui->label->setText(m_time.toString("m:ss"));
        m_videoWidget->close();
        showThankYouScreen();
    }
}

void InterviewStart::showNextQuestion(){
    m_time.setHMS(0,3,0);
    ui->label->setText(m_time.toString("m:ss"));
    std::string audioFile = m_videoFilePath + std::to_string(m_questionIndex[m_questionCount]) + ".mp4";
    m_player->setSource(QUrl(QString::fromStdString((audioFile))));
    m_questionCount++;
    m_videoWidget->showFullScreen();
    m_player->play();
}

void InterviewStart::on_pushButton_clicked(){} // TODO: remove this

void InterviewStart::chooseInterviewQuestions()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(1,MAX_INTRO_QUESTIONS);
    m_questionIndex.push_back(uni(rng));
    std::uniform_int_distribution<int> uni2(4,MAX_QUAL_QUESTIONS);
    m_questionIndex.push_back(uni2(rng));
    std::uniform_int_distribution<int> uni3(14,MAX_SIT_QUESTIONS);
    m_questionIndex.push_back(uni3(rng));
    std::uniform_int_distribution<int> uni4(19,MAX_RAND_QUESTIONS);
    m_questionIndex.push_back(uni4(rng));
    std::cout << m_questionIndex[0] << " " << m_questionIndex[1] << " " << m_questionIndex[2] << " " << m_questionIndex[3] << std::endl;
}

void InterviewStart::statusChanged(QMediaPlayer::MediaStatus status){
    switch (status) {
    case QMediaPlayer::EndOfMedia:
        m_timer->start(1000);
        m_player->stop();
        m_videoWidget->showMinimized();
        //m_videoWidget->close();
        break;
    }
}

