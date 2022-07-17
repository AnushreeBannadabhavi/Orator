#ifndef INTERVIEWOPTIONS_H
#define INTERVIEWOPTIONS_H

#include <QMainWindow>

namespace Ui {
class InterviewOptions;
}

class InterviewOptions : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterviewOptions(QWidget *parent = nullptr);
    ~InterviewOptions();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonStart_clicked();

private:
    Ui::InterviewOptions *ui;
};

#endif // INTERVIEWOPTIONS_H
