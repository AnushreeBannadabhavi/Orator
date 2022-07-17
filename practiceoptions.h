#ifndef PRACTICEOPTIONS_H
#define PRACTICEOPTIONS_H

#include <QMainWindow>
#include "publicspeaking.h"
#include "interviewoptions.h"

namespace Ui {
class PracticeOptions;
}

class PracticeOptions : public QMainWindow
{
    Q_OBJECT

public:
    explicit PracticeOptions(QWidget *parent = nullptr);
    ~PracticeOptions();

private slots:
    void on_pushButton_clicked();
    void on_pushButtonSubmit_clicked();

private:
    Ui::PracticeOptions *ui;
    PublicSpeaking *publicSpeaking = new PublicSpeaking;
    InterviewOptions *interviewOptions = new InterviewOptions;
};

#endif // PRACTICEOPTIONS_H
