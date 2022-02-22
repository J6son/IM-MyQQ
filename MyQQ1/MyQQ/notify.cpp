#include "notify.h"
#include "ui_notify.h"
#include<QDesktopWidget>
#include <QDesktopServices>
#include<QScreen>
#include"windows.h"

Notify::Notify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Notify),m_id(0)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint*/);

    this->setAttribute(Qt::WA_DeleteOnClose, true);

    timerShow=new QTimer(this);

    connect(timerShow,SIGNAL(timeout()),this,SLOT(myMove()));

    timerStay=new QTimer(this);

    connect(timerStay,SIGNAL(timeout()),this,SLOT(myStay()));

    timerClose=new QTimer(this);

    connect(timerClose,SIGNAL(timeout()),this,SLOT(myClose()));

    this ->hide();

}

Notify::~Notify()
{
    delete ui;
}


void Notify::on_pb_show_clicked()
{
    emit SIG_showChatDlg(m_id);
}

void Notify::on_CloseWnd_clicked()
{
    this->close();
}

void Notify::setInfo(const QString &name, quint32 id)
{
    m_name = name;
    m_id = id;
    ui->lb_content->setText(QString("%1\n发来一则消息").arg(name));
}

void Notify::setMsg(const QString &name, quint32 id , QString msg)
{
    m_name = name;
    m_id = id;
    ui->lb_content->setText(  msg );
}


void Notify::showAsQQ()
{
    QDesktopWidget *deskTop=QApplication::desktop();
    deskRect=deskTop->screenGeometry();

    APPBARDATA ad;
    ZeroMemory( &ad,sizeof(APPBARDATA) );
    ad.cbSize=sizeof (APPBARDATA);
    SHAppBarMessage(ABM_GETTASKBARPOS, &ad);

    if(ad.uEdge == ABE_RIGHT)
        normalPoint.setX( ( deskRect.width()-this->width() - ( ad.rc.right -ad.rc.left) /*sizeHint().width()*/-1 ) );
    else
        normalPoint.setX( ( deskRect.width()-this->width()/*sizeHint().width()*/-1 ) );

    if( ad.uEdge == ABE_BOTTOM)
        normalPoint.setY(deskRect.height()-this->height() -( ad.rc.bottom - ad.rc.top )/*sizeHint().height()*/);
    else
        normalPoint.setY(deskRect.height()-this->height()/*sizeHint().height()*/);

    move(normalPoint.x(),deskRect.height()+this->height());
    show();
    timerShow->start(5);

}


//平滑显示出来

void Notify::myMove()
{
    static int beginY= normalPoint.y()+ this->height()/*sizeHint().height()*/  ;
    beginY -= 3 ;
    move(normalPoint.x(),beginY);
//    move(0,beginY);
    if(beginY<= normalPoint.y())
    {
        timerShow->stop();
        timerStay->start(1000);
        beginY=normalPoint.y()+ this->height() ;
    }
}

//停留显示

void Notify::myStay()
{
    static int timeCount=0;
    timeCount++;
    if(timeCount>=/*6*/9)
    {
        timerStay->stop();
        timeCount=0;
        timerClose->start(200);
    }
}

//自动关闭时实现淡出效果

void Notify::myClose()

{
    static double tran=1.0;
    if(isEnter)
    {
        tran = 1.0;
        setWindowOpacity(tran);
        return;
    }
    tran-=0.1;
    if(tran<=0.0)
    {
        timerClose->stop();
        this->close();
    }
    else
        setWindowOpacity(tran);
}



void Notify::enterEvent(QEvent *)
{
    isEnter = true;
}

void Notify::leaveEvent(QEvent *)
{
    isEnter = false;
}
