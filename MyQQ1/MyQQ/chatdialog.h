#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include"customwidget.h"

namespace Ui {
class ChatDialog;
}

class ChatDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

signals:
    void SIG_SendChatMsg(int id,QString content);
public:
    explicit ChatDialog(QWidget *parent = 0);
    ~ChatDialog();

private:
    Ui::ChatDialog *ui;



public:
    int m_id;
    QString m_name;
public slots:
    void on_pb_send_clicked();

    void slot_recvChatMsg(QString content);

    void slot_showOffline();

    void setInfo(int id,QString name);//设置成员
private slots:
    void on_pb_min_clicked();
    void on_pb_max_clicked();
    void on_pb_close_clicked();
};

#endif // CHATDIALOG_H
