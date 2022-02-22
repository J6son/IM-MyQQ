#include "roomdialog.h"
#include "ui_roomdialog.h"
#include<QMessageBox>

RoomDialog::RoomDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),
    ui(new Ui::RoomDialog)
{
    ui->setupUi(this);

    m_videoList = new IMToolList("房间成员");
    ui->wdg_right->addItem(m_videoList);
    //初始化各个按钮名称
    clear();
}

RoomDialog::~RoomDialog()
{
    delete ui;
}

//离开房间
void RoomDialog::on_pb_quit_clicked()
{
    if(m_roomid == 0)
    {
        QMessageBox::about(this,"提示","还没有加入房间");
        return;
    }
    if(QMessageBox::question(this,"提示","确定离开房间")==QMessageBox::No)
        return;
    //发信号
    Q_EMIT SIG_quitRoom(m_roomid);

    //确认退出 清空
    clear();

    this->hide();
}

//设置信息
void RoomDialog::slot_setInfo(int id)
{
    m_roomid = id;

    //ui
    ui->lb_title->setText(QString("房间号:%1").arg(m_roomid));
}

void RoomDialog::clear()
{
    ui->lb_title->setText("房间号:---");
    //退出后还原按钮名称
    ui->pb_openAudio->setText("打开音频设备");
    ui->pb_openVideo->setText("打开视频设备");

    m_roomid = 0;
}

//点击打开视频
void RoomDialog::on_pb_openVideo_clicked()
{
    if(ui->pb_openVideo->text() == "打开视频设备")
    {
        Q_EMIT SIG_openVideoDev();
        ui->pb_openVideo->setText("关闭视频设备");
    }
    else
    {
        Q_EMIT SIG_closeVideoDev();
        ui->pb_openVideo->setText("打开视频设备");
    }
}

//点击打开音频
void RoomDialog::on_pb_openAudio_clicked()
{
    if(ui->pb_openAudio->text() == "打开音频设备")
    {
        Q_EMIT SIG_openAudioDev();
        ui->pb_openAudio->setText("关闭音频设备");
    }
    else
    {
        Q_EMIT SIG_closeAudioDev();
        ui->pb_openAudio->setText("打开音频设备");
    }
}

void RoomDialog::on_cbx_tuzi_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "无滤镜")
    {
        Q_EMIT SIG_setMoji(0);
    }
    else if(arg1 == "兔耳朵")
    {
        Q_EMIT SIG_setMoji(1);
    }
    else if(arg1 == "圣诞帽")
    {
        Q_EMIT SIG_setMoji(2);
    }
}

void RoomDialog::on_pb_close_clicked()
{
    on_pb_quit_clicked();
}

//添加一栏视频项
void RoomDialog::slot_addVideoItem(VideoItem *item)
{
    m_videoList->addItem(item);
}

//移除一栏视频项
void RoomDialog::slot_removeVideoItem(VideoItem *item)
{
    m_videoList->removeItem(item);
}

//设置放大图ID
void RoomDialog::slot_setBigImageID(int id,QString name)
{
    ui->wdg_video->setInfo(id,name);

}
//获取放大图ID
int RoomDialog::slot_getBigImageID()
{
    return ui->wdg_video->m_id;
}

Ui::RoomDialog *RoomDialog::getUi() const
{
    return ui;
}
