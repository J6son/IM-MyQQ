#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

signals:
    void SIG_LoginCommit(QString name,QString password);
    void SIG_RegisterCommit(QString name,QString password);

private slots:
    void on_pb_clear_clicked();

    void on_pb_register_clear_clicked();

    void on_pb_commit_clicked();

    void on_pb_register_commit_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
