#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QDialog>

#include "ibanksystemmodel.h"

class QLineEdit;
class ClientPersonalAccountWindow;
class ManagerPersonalAccountWindow;
class SignupWindow;

class AuthorizationWindow : public QDialog
{
    Q_OBJECT
public:
    AuthorizationWindow(IBankSystemModel *bankSystem, QWidget *parent = nullptr);
    ~AuthorizationWindow();

    void setBankName(const QString bank);

private slots:
    void enter();
    void signup();

private:
    QString bankName = "";
    IBankSystemModel *bankSystemModel;
    QLineEdit *loginLine, *passwordLine;
};

#endif // AUTHORIZATIONWINDOW_H
