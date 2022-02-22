#ifndef USERITEM_H
#define USERITEM_H

#include <QWidget>
#include<QMouseEvent>
namespace Ui {
class UserItem;
}

class UserItem : public QWidget
{
    Q_OBJECT

public:
    explicit UserItem(QWidget *parent = 0);
    ~UserItem();

    void setInfo(int id,int state,QString name,
                 QString icon = QString(":/tx/11.png"),
                 QString feeling = QString("比较懒，什么也没写"));
signals:
    void SIG_ItemClicked();//双击用户 或 单击头像
public slots:
    void mouseDoubleClickEvent(QMouseEvent *event);//双击弹出聊天窗口
private:
    Ui::UserItem *ui;
public:
    int m_id;
    int m_state;
    QString m_name;
    QString m_icon;
    QString m_feeling;
private slots:
    void on_pb_icon_clicked();
};

#endif // USERITEM_H
