#ifndef PUBSPSTART_H
#define PUBSPSTART_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMediaCaptureSession>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QCamera>
//#include <QGraphicsScene>
//#include <QGraphicsView>
#include "thankyouscreen.h"

namespace Ui {
class PubSpStart;
}

class PubSpStart : public QMainWindow
{
    Q_OBJECT

public:
    PubSpStart(QWidget *parent = nullptr);
    PubSpStart(QWidget *parent = nullptr, bool isRecord = false);
    ~PubSpStart();
    void updateTime();
    void showThankYouScreen();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::PubSpStart *ui;
    QTime m_time;
    QTimer *m_timer = new QTimer(this);
    ThankYouScreen *m_endScreen = new ThankYouScreen;
    QMediaCaptureSession *m_recordingSession = new QMediaCaptureSession;
    //QAudioInput *audioInput = new QAudioInput;
    QMediaRecorder m_recorder;
    QCamera *m_camera;// = new QCamera;
    QScopedPointer<QAudioInput> m_audioInput;
    bool m_isRecord = false;
    //QGraphicsScene* scene = new QGraphicsScene();
    //QGraphicsView* view = new QGraphicsView(scene);
};

#endif // PUBSPSTART_H
