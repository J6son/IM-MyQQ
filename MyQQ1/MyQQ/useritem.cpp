#include "useritem.h"
#include "ui_useritem.h"
#include<qDebug>
UserItem::UserItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserItem),m_id(0),m_state(0)
{
    ui->setupUi(this);
}

UserItem::~UserItem()
{
    qDebug()<<"~UserItem";
    delete ui;
}

#include<QBitmap>
void UserItem::setInfo(int id, int state, QString name, QString icon, QString feeling)
{
    //设置成员
    m_id = id;
    m_state = state;
    m_name = name;
    m_icon = icon;
    m_feeling = feeling;

    //设置UI
    ui->lb_name->setText(m_name);
    ui->lb_feeling->setText(m_feeling);
    //用户在线 彩色头像
    if(m_state)
    {
        ui->pb_icon->setIcon(QIcon(m_icon));
    }
    //不在线 灰色头像
    else
    {
        QBitmap gray; //QBitmap 灰度图像
        gray.load(m_icon);
        ui->pb_icon->setIcon(gray);
    }
    //repaint()马上重绘 update()放入队列 等显卡刷新再重绘
    this->repaint();
}

//双击
void UserItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_EMIT SIG_ItemClicked();
}

//单击头像
void UserItem::on_pb_icon_clicked()
{
    Q_EMIT SIG_ItemClicked();
}
