#include "pubspstart.h"
#include "ui_pubspstart.h"
#include <QMediaDevices>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QFile>
#include <iostream>
#include <QDebug>
#include <QImageReader>

PubSpStart::PubSpStart(QWidget *parent, bool isRecord) :
    QMainWindow(parent),
    ui(new Ui::PubSpStart)
{
    ui->setupUi(this);
    m_isRecord = isRecord;
    //ui->label->setText("1:00");
    //timer = new QTimer();
    m_time.setHMS(0,0,0);
    connect(m_timer, &QTimer::timeout, this, &PubSpStart::updateTime);
    ui->label->setText(m_time.toString("m:ss"));
    m_audioInput.reset(new QAudioInput);
    m_recordingSession->setAudioInput(m_audioInput.get());

    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    for (const QCameraDevice &cameraDevice : cameras) {
        //if (cameraDevice.description() == "mycamera")
            m_camera = new QCamera(cameraDevice);
    }

    m_recordingSession->setCamera(m_camera);
    m_recordingSession->setRecorder(&m_recorder);
    m_recorder.setQuality(QMediaRecorder::HighQuality);
    //m_recorder.setOutputLocation(QUrl::fromLocalFile("D:/UBC_Coursework/Summer/SpeakingSimulator/Recordings/test.mp4"));
    m_recorder.setOutputLocation(QUrl::fromLocalFile("C:/work/QT/InterviewVideos/Recordings/test.mp4"));
}

PubSpStart::~PubSpStart()
{
    delete ui;
}

void PubSpStart::updateTime(){
    if(m_time.toString("m:ss") == "0:08"){
        //view->hide();
    }
    if(m_time.toString("m:ss") == "10:00"){ // Specify time here
        m_timer->stop();
        if(m_isRecord){
            m_recorder.stop();
        }
        ui->label->setText(m_time.toString("m:ss"));
        showThankYouScreen();
    } else{
        m_time=m_time.addSecs(1);
        ui->label->setText(m_time.toString("m:ss"));
    }
}

void PubSpStart::on_pushButton_clicked() // TODO: Remove this
{}


void PubSpStart::on_pushButtonStart_clicked()
{
    if (ui->pushButtonStart->text() == "Start"){
        if(m_isRecord){
            m_camera->start();
            m_recorder.record();
        }
        m_timer->start(1000);

        /*QImage testimage(64,64,QImage::Format_RGB32);
        QImageReader reader("D:/Personal/Photo/DSC_0624.JPG");

        if(reader.read(&testimage))
        {
            std::cout << "OK file" << std::endl;
        }
        QString error = reader.errorString();

        qDebug() << error;

        //QString filename = ":/img/Class.png";
        QFile filename(":/img/Class.jpg");
        //if(filename.isEmpty())
        //{std::cout << "Empty image file" << std::endl;}
        //QImage image(filename);
        QImage *image = new QImage("D:/UBC_Coursework/Summer/SpeakingSimulator/ClassRoomPictures/Class.bmp");
        if(image->isNull()){
            std::cout << "NULL image" << std::endl;
        }
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
        scene->addItem(item);
        view->show();

        //QPixmap pix("D:/UBC_Coursework/Summer/SpeakingSimulator/ClassRoomPictures/Class.bmp");
        //ui->label_2->setPixmap(pix);*/

        ui->pushButtonStart->setText("Stop");
    }else if (ui->pushButtonStart->text() == "Stop"){
        m_timer->stop();
        m_recorder.stop();
        ui->label->setText(m_time.toString("m:ss"));
        showThankYouScreen();
    }
}


void PubSpStart::on_pushButtonStop_clicked() // TODO: Remove this
{}

void PubSpStart::showThankYouScreen()
{
    m_endScreen->show();
    this->hide();
}

