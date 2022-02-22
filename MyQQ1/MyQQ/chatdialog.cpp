#include "chatdialog.h"
#include "ui_chatdialog.h"

ChatDialog::ChatDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),
    ui(new Ui::ChatDialog),m_id(0)
{
    ui->setupUi(this);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::setInfo(int id, QString name)
{
    //成员
    m_id = id;
    m_name = name;
    //UI
    ui->lb_title->setText(QString("与[ %1 ]的聊天").arg(m_name));
}

#include<QTime>
//发送聊天内容
void ChatDialog::on_pb_send_clicked()
{
    QString content = ui->te_chat->toHtml();
    if(content.isEmpty()) return;

    //把编辑框的文字添加到聊天窗口 append自动加换行
    ui->tb_chat->append(QString("[ 我 ] %1").arg(QTime::currentTime().toString("hh:mm:ss")));
    ui->tb_chat->append(content);
    //清空编辑框
    ui->te_chat->clear();

    Q_EMIT SIG_SendChatMsg(m_id,content);

}

//接收聊天内容
void ChatDialog::slot_recvChatMsg(QString content)
{
    //把编辑框的文字添加到聊天窗口 append自动加换行
    ui->tb_chat->append(QString("[ %1 ] %2")
                        .arg(m_name).arg(QTime::currentTime().toString("hh:mm:ss")));
    ui->tb_chat->append(content);
}

//对方不在线
void ChatDialog::slot_showOffline()
{
    ui->tb_chat->append(QString("用户[ %1 ]已离线").arg(m_name));
}

void ChatDialog::on_pb_min_clicked()
{
    this->slot_showMin();
}

void ChatDialog::on_pb_max_clicked()
{
    this->slot_showMax();
}

void ChatDialog::on_pb_close_clicked()
{
    this->slot_close();
}
