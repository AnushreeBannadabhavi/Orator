#ifndef PERMISSIONPAGE_H
#define PERMISSIONPAGE_H

#include <QMainWindow>
#include "pubspstart.h"

namespace Ui {
class PermissionPage;
}

class PermissionPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit PermissionPage(QWidget *parent = nullptr);
    PermissionPage(QWidget *parent = nullptr, bool isInterview = false);
    ~PermissionPage();

private slots:
    void on_IAgree_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PermissionPage *ui;
    bool m_isInterview = false;
};

#endif // PERMISSIONPAGE_H
