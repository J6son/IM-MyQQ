#include "videoitem.h"
#include "ui_videoitem.h"
#include<QPainter>

VideoItem::VideoItem(QWidget *parent) :
    QWidget(parent),m_defaultImg(":/tx/12.png"),
    ui(new Ui::VideoItem)
{
    ui->setupUi(this);

    m_timer = new QTime;
    connect(m_timer,SIGNAL(timeout()),
            this,SLOT(slot_CheckTime()));
    m_timer->start(500);
    m_lastTime = QTime::currentTime();
}

VideoItem::~VideoItem()
{
    delete ui;

    if(m_timer)
    {
        m_timer->stop();
        delete m_timer;
    }
}

void VideoItem::setInfo(int id, QString name)
{
    m_id = id;
    m_name = name;

    ui->lb_name->setText(QString("用户:%1").arg(m_name));

}

//设置一帧图片
void VideoItem::slot_setOneImage(QImage img)
{
    m_lastTime = QTime::currentTime();
    m_image = img;

    this->repaint();//重绘->调用绘图事件paintEvent
}

//绘图事件
void VideoItem::paintEvent(QPaintEvent *event)
{
    //画黑背景 图片不够大 多出来的部分用黑色填充
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawRect(0,0,this->width(),this->height());

    //画图片
    if(m_image.size().height()<=0) return;

    //加载图片用QImage 画图用QPixmap
    QPixmap pixmap = QPixmap::fromImage(
                m_image.scaled(this->size(),Qt::KeepAspectRatio,Qt::FastTransformation));

    //画的位置 图片左上角
    int x = this->width() - pixmap.width();
    int y = this->height()-pixmap.height()-ui->lb_name->height();
    x/=2;
    y = ui->lb_name->height()+y/2;

    painter.drawPixmap(QPoint(x,y),pixmap);
}

void VideoItem::mousePressEvent(QMouseEvent *event)
{
    Q_EMIT SIG_itemClicked(m_id);
}

//每半秒检查与上一帧图片时间是否超过3秒 是的话贴上默认图片
void VideoItem::slot_CheckTime()
{
    if(m_lastTime.secsTo(QTime::currentTime())>3)
    {
        m_lastTime = QTime::currentTime();
        m_image = m_defaultImg;
        this->repaint();
    }
}
