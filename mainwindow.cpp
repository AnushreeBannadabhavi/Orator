#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "practiceoptions.h"

//#include <QAudioInput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_takeImageButton = new QPushButton("Take Image");
    m_audioInput.reset(new QAudioInput);
    m_captureSession.setAudioInput(m_audioInput.get());
    ui->textEditName->setTextColor( QColor( "white" ) );
    ui->textEditEmail->setTextColor( QColor( "white" ) );
    ui->label->setStyleSheet("QLabel { background-color : black; color : white; }");
    ui->label_2->setStyleSheet("QLabel { background-color : black; color : white; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // TODO: This function must be removed. But throws error when removed
{}


void MainWindow::on_pushButtonSubmit_clicked()
{
    if(!ui->textEditName->toPlainText().isEmpty() && !ui->textEditEmail->toPlainText().isEmpty()){
        pracOptions->show();
        this->hide();
    }

}

