#ifndef INTERVIEWSTART_H
#define INTERVIEWSTART_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <vector>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QCamera>
#include <QMediaCaptureSession>
#include "thankyouscreen.h"

namespace Ui {
class InterviewStart;
}

class InterviewStart : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterviewStart(QWidget *parent = nullptr);
    InterviewStart(QWidget *parent = nullptr, bool isRecord = false);
    ~InterviewStart();
    void updateTime();
    void showThankYouScreen();
    void chooseInterviewQuestions();
    void statusChanged(QMediaPlayer::MediaStatus status);
    void showNextQuestion();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonStartStop_clicked();

private:
    Ui::InterviewStart *ui;
    QTime m_time;
    QTimer *m_timer = new QTimer(this);
    ThankYouScreen *m_endScreen = new ThankYouScreen;
    std::vector<int> m_questionIndex;
    QMediaPlayer *m_player = new QMediaPlayer;
    QVideoWidget *m_videoWidget = new QVideoWidget;
    QAudioOutput *m_audioOutput = new QAudioOutput;
    std::string m_videoFilePath;
    int m_questionCount = 0;
    QMediaRecorder m_recorder;
    QCamera *m_camera;// = new QCamera;
    QScopedPointer<QAudioInput> m_audioInput;
    QMediaCaptureSession *m_recordingSession = new QMediaCaptureSession;
    bool recordingStarted = false;
    bool m_isRecord = false;
};

#endif // INTERVIEWSTART_H
