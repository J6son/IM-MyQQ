#ifndef MYQQDIALOG_H
#define MYQQDIALOG_H

#include <QDialog>
#include"qmytcpclient.h"
#include"Packdef.h"
#include"logindialog.h"
#include"IMToolBox.h"
#include<QMenu>
#include<QMap>
#include"useritem.h"
#include<QCloseEvent>
#include"chatdialog.h"
#include"roomdialog.h"
#include"video_read.h"
#include"audio_read.h"
#include"audio_write.h"
#include"customwidget.h"

namespace Ui {
class MyQQDialog;
}

class MyQQDialog : public /*QDialog*/CustomMoveDialog
{
    Q_OBJECT

public:
    explicit MyQQDialog(QWidget *parent = 0);
    ~MyQQDialog();

signals:
    void SIG_addFriend(QString name);

private slots:
    void slot_Delete();

    void on_pushButton_clicked();

    void slot_ReadyData(char* buf,int nlen);

    void slot_LoginCommit(QString name,QString password);

    void slot_RegisterCommit(QString name,QString password);

    void slot_RegisterRs(char*buf,int nlen);

    void slot_LoginRs(char *buf,int nlen);

    void slot_ForceOffline(char *buf,int nlen);

    void slot_dealMenu(QAction* action);

    void on_pb_menu_clicked();

    void slot_addFriendRq(QString name);

    void slot_dealAddFriendRq(char*buf,int nlen);

    void slot_dealAddFriendRs(char*buf,int nlen);

    void slot_FriendInfo(char*buf,int nlen);

    void slot_ChatRq(char*buf,int nlen);

    void slot_UserItemClicked();

    void InitServerIP();
    void on_pb_close_clicked();

    void closeEvent(QCloseEvent *event);//重写关闭事件

    void slot_SendChatRq(int id,QString content);

    void slot_ChatRs(char *buf, int nlen);

    void slot_createRoom();

    void slot_joinRoom(QString roomid);

    void slot_leaveRoom(int id);

    void slot_CreateRoomRs(char *buf, int nlen);

    void slot_JoinRoomRs(char *buf, int nlen);

    void slot_videoItemClicked(int id);

    void slot_RoomMember(char *buf, int nlen);

    void slot_LeaveRoomRs(char *buf, int nlen);

    void slot_sendVideoFrame(QImage& img);

    void slot_refreshImage(int id, QImage &img);

    void slot_VideoFrame(char *buf, int nlen);

    void slot_sendAudioFrame(QByteArray byte);

    void slot_AudioFrame(char *buf, int nlen);

private:
    Ui::MyQQDialog *ui;
    QMyTcpClient * m_tcpClient;
    QString m_serverIP; //配置IP 不用每次都在编译中配置
    LoginDialog *m_loginDlg;
    int m_id;
    IMToolList *m_widgetList;
    QMenu *m_mainMenu;
    QString m_UserName;
    RoomDialog* m_roomdlg;
    int m_roomid;//只能加入一个房间

    QMap<int,UserItem*>m_mapIDToUserItem;
    QMap<int,ChatDialog*>m_mapIDToChatdlg;
    QMap<int,VideoItem*>m_mapIDToVideoItem;

    Video_Read* m_pVideoRead;
    Audio_Read* m_pAudioRead; //声音采集
    QMap<int,Audio_Write*>m_mapIDToAudioWrite;
};

#endif // MYQQDIALOG_H
