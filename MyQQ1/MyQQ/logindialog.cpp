#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//清空
void LoginDialog::on_pb_clear_clicked()
{
    ui->le_name->setText("");
    ui->le_password->setText("");
}

//清空
void LoginDialog::on_pb_register_clear_clicked()
{
    ui->le_register_name->setText("");
    ui->le_register_password->setText("");
    ui->le_register_confirm->setText("");
}

#include<QMessageBox>
//登录提交
void LoginDialog::on_pb_commit_clicked()
{
    //验证 合法性
    QString name = ui->le_name->text();
    QString password = ui->le_password->text();

    //1非空 去掉空格后
    if(name.isEmpty() || name.remove(" ").isEmpty() || password.isEmpty())
    {
        QMessageBox::about(this,"提示","用户名或密码为空");
        return;
    }

    //name a-z A-Z 0-9 长度10个以内
    QRegExp reg("[a-zA-Z0-9]{1,10}");
    bool res = reg.exactMatch(name);
    if(!res)
    {
        QMessageBox::about(this,"提示","用户名非法");
        return;
    }
    if(name.length()>10 || password.length()>20)
    {
        QMessageBox::about(this,"提示","用户名或密码过长");
        return;
    }

    //获取用户名密码后发送信号交给网络部分
    Q_EMIT SIG_LoginCommit(name,password);
    //Q_EMIT SIG_RegisterCommit(name,password);
}

//注册提交
void LoginDialog::on_pb_register_commit_clicked()
{
    //验证 合法性
    QString name = ui->le_register_name->text();
    QString password = ui->le_register_password->text();
    QString confirm = ui->le_register_confirm->text();

    //1非空 去掉空格后
    if(name.isEmpty() || name.remove(" ").isEmpty() || password.isEmpty())
    {
        QMessageBox::about(this,"提示","用户名或密码为空");
        return;
    }

    //name a-z A-Z 0-9 长度10个以内
    QRegExp reg("[a-zA-Z0-9]{1,10}");
    bool res = reg.exactMatch(name);
    if(!res)
    {
        QMessageBox::about(this,"提示","用户名非法");
        return;
    }
    if(name.length()>10 || password.length()>20)
    {
        QMessageBox::about(this,"提示","用户名或密码过长");
        return;
    }

    if(password != confirm)
    {
        QMessageBox::about(this,"提示","两次密码不一致");
        return;
    }

    //获取用户名密码后发送信号交给网络部分
    Q_EMIT SIG_RegisterCommit(name,password);
}
