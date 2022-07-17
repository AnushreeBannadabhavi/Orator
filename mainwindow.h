#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QCamera>
//#include <QCameraInfo> QCameraDevice
#include <QMediaCaptureSession>
#include <QAction>
#include <QImageCapture>
//#include <QCameraViewFinder>
#include <QPushButton>
#include <QAudioInput>
#include "practiceoptions.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCameraAction(QAction *camera_action);
    //void set_camera(const QCameraInfo &camera_info);

private slots:
    void on_pushButton_clicked();

    void on_pushButtonSubmit_clicked();

private:
    Ui::MainWindow *ui;
    void setup_ui();
    void setup_camera_devices();

    QScopedPointer<QCamera> m_camera;
    QScopedPointer<QImageCapture> m_imageCapture;
    QScopedPointer<QAudioInput> m_audioInput;
    QMediaCaptureSession m_captureSession;
    QWidget *m_centralWidget;
    QPushButton *m_takeImageButton;
    PracticeOptions *pracOptions = new PracticeOptions;
};
#endif // MAINWINDOW_H
