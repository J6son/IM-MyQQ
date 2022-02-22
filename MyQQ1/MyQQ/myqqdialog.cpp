#include "myqqdialog.h"
#include "ui_myqqdialog.h"
#include<QCryptographicHash>
#include<QMessageBox>
#include<QVBoxLayout>
#include"useritem.h"
#include"notify.h"
#include<QScrollArea>
#include"ui_roomdialog.h"

#define MD5_KEY 1234
//加严  name 我12是34谁 防止彩虹表
//加static只能在当前文件可用
static QByteArray GetMD5(QString val)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    QString key = QString("%1_%2").arg(val).arg(MD5_KEY);

    hash.addData(key.toLocal8Bit());
    QByteArray bt = hash.result();

    return bt.toHex();   //MD5 32位16进制数 AD1234F....
}


MyQQDialog::MyQQDialog(QWidget *parent) :
    /*QDialog*/CustomMoveDialog(parent),m_id(0),m_roomid(0),
    ui(new Ui::MyQQDialog)
{
    ui->setupUi(this);

    //先设置默认IP
    std::string strIP = DEF_SERVER_IP;
    m_serverIP = QString::fromStdString(strIP);
    //再去配置文件中替换
    InitServerIP();

    m_tcpClient = new QMyTcpClient;
    connect(m_tcpClient,SIGNAL(SIG_ReadyData(char*,int)),this,SLOT(slot_ReadyData(char*,int)));

    //c_str() const char*
    m_tcpClient->setIpAndPort((char*)m_serverIP.toStdString().c_str());

    m_loginDlg = new LoginDialog;
    connect(m_loginDlg,SIGNAL(SIG_LoginCommit(QString,QString)),
            this,SLOT(slot_LoginCommit(QString,QString)));
    connect(m_loginDlg,SIGNAL(SIG_RegisterCommit(QString,QString)),
            this,SLOT(slot_RegisterCommit(QString,QString)));

    m_loginDlg->show();
    //this->hide();//父窗口myqqdialog隐藏 在main中已设置不显示

    //好友栏
    UserItem *item1 = new UserItem;
    UserItem *item2 = new UserItem;
    UserItem *item3 = new UserItem;

    m_widgetList = new IMToolList("我的好友");

    ui->wdg_box->addItem(m_widgetList);

    m_widgetList->addItem(item1);
    m_widgetList->addItem(item2);
    m_widgetList->addItem(item3);

    //this传参 指定父控件 父控件回收时会回收子控件
    m_mainMenu = new QMenu(this);
    m_mainMenu->addAction("添加好友");
    m_mainMenu->addSeparator();
    //m_mainMenu->addAction("");
    m_mainMenu->addAction("创建房间");
    m_mainMenu->addAction("加入房间");

    connect(m_mainMenu,SIGNAL(triggered(QAction*)),this,SLOT(slot_dealMenu(QAction*)));

    connect( this , SIGNAL(SIG_addFriend(QString)) ,
             this , SLOT(slot_addFriendRq(QString)) );

    m_roomdlg = new RoomDialog;
    connect(m_roomdlg,SIGNAL(SIG_quitRoom(int)),this,SLOT(slot_leaveRoom(int)));

    m_pVideoRead = new Video_Read;
    connect(m_roomdlg,SIGNAL(SIG_openVideoDev()),
            m_pVideoRead,SLOT(slot_openVideo()));
    connect(m_roomdlg,SIGNAL(SIG_closeVideoDev()),
            m_pVideoRead,SLOT(slot_closeVideo()));

    connect(m_pVideoRead,SIGNAL(SIG_sendVideoFrame(QImage&)),
            this,SLOT(slot_sendVideoFrame(QImage&)));

    connect(m_roomdlg,SIGNAL(SIG_setMoji(int)),
            m_pVideoRead,SLOT(slot_setMoji(int)));

    m_pAudioRead = new Audio_Read;
    connect(m_pAudioRead,SIGNAL(sig_net_tx_frame(QByteArray)),
            this,SLOT(slot_sendAudioFrame(QByteArray)));

    connect(m_roomdlg,SIGNAL(SIG_openAudioDev()),
            m_pAudioRead,SLOT(ResumeAudio()));
    connect(m_roomdlg,SIGNAL(SIG_closeAudioDev()),
            m_pAudioRead,SLOT(PauseAudio()));
}

MyQQDialog::~MyQQDialog()
{
    delete ui;    
}

//回收资源
void MyQQDialog::slot_Delete()
{

    if(m_pVideoRead)
    {
        m_pVideoRead->slot_closeVideo();
        delete m_pVideoRead;
        m_pVideoRead = NULL;
    }
    if(m_tcpClient)
    {
        delete m_tcpClient;
        m_tcpClient=NULL;
    }
    //登录窗口不是子窗口 是自己创建的 要手动回收
    if(m_loginDlg)
    {
        delete m_loginDlg;
        m_loginDlg=NULL;
    }

    //子控件会自动回收(看析构函数) 不需要手动回收 回收两次会出错
//    if(m_widgetList)
//    {
//        delete m_widgetList;
//        m_widgetList=NULL;
//    }

//    for(auto ite=m_mapIDToUserItem.begin();ite!=m_mapIDToUserItem.end();ite++)
//    {
//        delete *ite;
//        *ite=NULL;
//    }
//    m_mapIDToUserItem.clear();

    //删除用户聊天窗口映射
    for(auto ite=m_mapIDToChatdlg.begin();ite!=m_mapIDToChatdlg.end();ite++)
    {
        delete *ite;
        *ite=NULL;
    }
    m_mapIDToChatdlg.clear();

    if(m_pAudioRead)
    {
        m_pAudioRead->PauseAudio();
        delete m_pAudioRead;
        m_pAudioRead = NULL;
    }
}

void MyQQDialog::on_pushButton_clicked()
{
    STRU_LOGIN_RQ rq;
    strcpy(rq.m_szUser,"111");
    strcpy(rq.m_szPassword,"111");
    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

void MyQQDialog::slot_ReadyData(char* buf,int nlen)
{
    int type = *(int *)buf;
    switch(type)
    {
    case DEF_PACK_LOGIN_RS:
        qDebug()<<"DEF_PACK_LOGIN_RS";
        slot_LoginRs(buf, nlen);
        break;
    case DEF_PACK_REGISTER_RS:
        qDebug()<<"DEF_PACK_REGISTER_RS";
        slot_RegisterRs(buf, nlen);
        break;
    case DEF_PACK_FORCE_OFFLINE:
        slot_ForceOffline(buf,nlen);
        break;
    case DEF_PACK_ADD_FRIEND_RQ:
        slot_dealAddFriendRq(buf,nlen);
        break;
    case DEF_PACK_ADD_FRIEND_RS:
        slot_dealAddFriendRs(buf,nlen);
        break;
    case DEF_PACK_FRIEND_INFO:
        slot_FriendInfo(buf,nlen);
        break;
    case DEF_PACK_CHAT_RQ:
        slot_ChatRq(buf,nlen);
        break;
    case DEF_PACK_CHAT_RS:
        slot_ChatRs(buf,nlen);
        break;
    case DEF_PACK_CREATEROOM_RS:
        slot_CreateRoomRs(buf,nlen);
        break;
    case DEF_PACK_JOINROOM_RS:
        slot_JoinRoomRs(buf,nlen);
        break;
    case DEF_PACK_ROOM_MEMBER:
        slot_RoomMember(buf,nlen);
        break;
    case DEF_PACK_LEAVEROOM_RS:
        slot_LeaveRoomRs(buf,nlen);
        break;
    case DEF_PACK_VIDEO_FRAME:
        slot_VideoFrame(buf,nlen);
        break;
    case DEF_PACK_AUDIO_FRAME:
        slot_AudioFrame(buf,nlen);
        break;
    default:break;
    }

    delete []buf;
}

//提交登录
void MyQQDialog::slot_LoginCommit(QString name, QString password)
{
    STRU_LOGIN_RQ rq;
    //Unicode中文兼容
    std::string strName = name.toStdString();
    const char* bufName = strName.c_str();
    strcpy_s(rq.m_szUser,MAX_SIZE,bufName);

    QByteArray btPassword = GetMD5(password);
    memcpy(rq.m_szPassword,btPassword.data(),btPassword.size());

    m_UserName = name;
    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

//提交注册
void MyQQDialog::slot_RegisterCommit(QString name, QString password)
{
    STRU_REGISTER_RQ rq;
    //Unicode中文兼容
    std::string strName = name.toStdString();
    const char* bufName = strName.c_str();
    strcpy_s(rq.m_szUser,MAX_SIZE,bufName);

    QByteArray btPassword = GetMD5(password);
    memcpy(rq.m_szPassword,btPassword.data(),btPassword.size());

    qDebug()<<rq.m_szPassword;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

//注册回复
void MyQQDialog::slot_RegisterRs(char *buf, int nlen)
{
    STRU_REGISTER_RS *rs = (STRU_REGISTER_RS*) buf;
    switch (rs->m_lResult)
    {
    case userid_is_exist:
        QMessageBox::about(m_loginDlg,"提示","注册失败，用户已存在");
        break;
    case register_success:
        QMessageBox::about(m_loginDlg,"提示","注册成功");
        break;
    default:
        break;
    }
}

//登录回复
void MyQQDialog::slot_LoginRs(char *buf, int nlen)
{
    STRU_LOGIN_RS *rs = (STRU_LOGIN_RS*) buf;
    switch (rs->m_lResult)
    {
    case userid_no_exist:
        QMessageBox::about(m_loginDlg,"提示","登录失败，用户不存在");
        break;
    case password_error:
        QMessageBox::about(m_loginDlg,"提示","登陆失败，密码错误");
        break;
    case login_success:
        //QMessageBox::about(m_loginDlg,"提示","登陆失败，密码错误");
        //id赋值
        m_id = rs->m_UserID;
        //ui跳转
        m_loginDlg->hide();
        this->show();
        break;
    default:
        break;
    }
}

//强制下线
void MyQQDialog::slot_ForceOffline(char *buf, int nlen)
{
    STRU_FORCE_OFFLINE *rs = (STRU_FORCE_OFFLINE*)buf;
    if(rs->m_userID == m_id)
    {
        QMessageBox::about(this,"提示","异地登录,强制下线");

        //退出程序
        this->close();//进入关闭事件函数 closeEvent
        //exit(0);
    }
}

#include<QInputDialog>
//处理菜单
void MyQQDialog::slot_dealMenu(QAction *action)
{
    if(action->text()=="添加好友")
    {
        qDebug()<<"添加好友";
        //弹出一个输入框
        QString strName = QInputDialog::getText(this,"添加好友","输入好友姓名");
        QRegExp reg("[a-zA-Z0-9]{1,10}");
        bool res = reg.exactMatch(strName);
        if(res)
        {
            //发送添加好友信号
            Q_EMIT SIG_addFriend(strName);
        }
        else
        {
            QMessageBox::about(this,"提示","用户名非法\n输入10位以内数字或字母");
        }
    }
    else if(action->text()=="创建房间")
    {
        qDebug()<<"创建房间";
        if(m_roomid != 0)
        {
            QMessageBox::about(this,"提示","已经在房间里,不能创建");
            return;
        }
        slot_createRoom();
    }
    else if(action->text()=="加入房间")
    {
        qDebug()<<"加入房间";
        if(m_roomid != 0)
        {
            QMessageBox::about(this,"提示","已经在房间里,不能加入");
            return;
        }
        //弹出一个输入框
        QString strRoom = QInputDialog::getText(this,"添加房间","输入房间号");
        QRegExp reg("[0-9]{1,10}");
        bool res = reg.exactMatch(strRoom);
        if(res)
        {
            //加入房间
            slot_joinRoom(strRoom);
        }
        else
        {
            QMessageBox::about(this,"提示","房间号非法\n输入8位以内数字");
        }
    }
}

//点击菜单
void MyQQDialog::on_pb_menu_clicked()
{
    if(m_mainMenu)
    {
        QPoint p = QCursor::pos();
        QSize size = m_mainMenu->sizeHint(); //最终大小
        int y = p.y()-size.height();
        m_mainMenu->exec(QPoint(p.x(),y));
    }
}

//发送加好友请求
void MyQQDialog::slot_addFriendRq(QString name)
{
    if(m_UserName == name)
    {
        QMessageBox::about(this,"提示","不能添加自己");
        return;
    }
    //已经是好友不能添加
    for(auto ite=m_mapIDToUserItem.begin();ite!=m_mapIDToUserItem.end();ite++)
    {
        UserItem *item = *ite;
        if( item ->m_name == name )
        {
            QMessageBox::about(this , "提示","已经是好友,不能添加");
            return;
        }
    }

    STRU_ADD_FRIEND_RQ rq;
    std::string strAddName = name.toStdString();
    strcpy_s(rq.m_szAddFriendName,MAX_SIZE,strAddName.c_str());

    rq.m_userID = m_id;
    std::string strUserName = rq.m_szUserName;
    strcpy_s(rq.m_szUserName,MAX_SIZE,strUserName.c_str());

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

//处理添加好友请求
void MyQQDialog::slot_dealAddFriendRq(char *buf, int nlen)
{
    STRU_ADD_FRIEND_RQ* rq = (STRU_ADD_FRIEND_RQ*)buf;
    STRU_ADD_FRIEND_RS rs;
    strcpy_s(rs.szAddFriendName,MAX_SIZE,rq->m_szAddFriendName);
    rs.m_friendID = m_id;
    rs.m_userID=rq->m_userID;

    if(QMessageBox::question(this,"好友请求",QString("%1 请求添加你为好友").arg(rq->m_szUserName))
            == QMessageBox::Yes)
    {
        //同意请求
        rs.m_result=add_success;
    }
    else
    {
        rs.m_result=user_refused;
    }
    m_tcpClient->SendData((char*)&rs,sizeof(rs));
}

//处理添加好友回复
void MyQQDialog::slot_dealAddFriendRs(char *buf, int nlen)
{
    STRU_ADD_FRIEND_RS *rs = ( STRU_ADD_FRIEND_RS *)buf;
    switch (rs->m_result) {
    case no_this_user:
        QMessageBox::about(this,"提示","没有此用户");
        break;
    case user_refused:
        QMessageBox::about(this,"提示","用户拒绝");
        break;
    case user_is_offline:
        QMessageBox::about(this,"提示","用户离线");
        break;
    case add_success:
        QMessageBox::about(this,"提示",QString("成功添加[%1]为好友").arg(rs->szAddFriendName));
        break;
    default:
        break;
    }

}

//好友列表
void MyQQDialog::slot_FriendInfo(char *buf, int nlen)
{
    STRU_FRIEND_INFO *friendrq = (STRU_FRIEND_INFO *)buf;

    //好友是自己
    if(friendrq->m_userID == m_id)
    {
        //设置默认头像
        ui->pb_icon->setIcon(QIcon(QString(":/tx/%1.png").arg(friendrq->m_iconID)));
        ui->lb_name->setText(friendrq->m_szName);
        return ;
    }
    //内存里没有这个用户 即不在线
    if(m_mapIDToUserItem.find(friendrq->m_userID) == m_mapIDToUserItem.end())
    {
        //新建一项
        UserItem *item = new UserItem;
        item->setInfo(friendrq->m_userID,friendrq->m_state,friendrq->m_szName,
                      QString(":/tx/%1.png").arg(friendrq->m_iconID));
        //好友列表抽屉
        m_widgetList->addItem(item);
        connect(item,SIGNAL(SIG_ItemClicked()),this,SLOT(slot_UserItemClicked()));

        m_mapIDToUserItem[friendrq->m_userID] = item;

        //为这个新建好友创建聊天窗口
        ChatDialog *chat = new ChatDialog;
        chat->setInfo(friendrq->m_userID,friendrq->m_szName);
        connect(chat,SIGNAL(SIG_SendChatMsg(int,QString)),
                            this,SLOT(slot_SendChatRq(int,QString)));

        m_mapIDToChatdlg[friendrq->m_userID] = chat;
    }
    else
    {
        UserItem *item = m_mapIDToUserItem[friendrq->m_userID];
        //弹出上线提示框
        if( item->m_state == 0 )
        {
            Notify *nf = new Notify;
            nf->setMsg( item->m_name , item->m_id , QString("[ %1 ]上线了").arg(item->m_name));
            nf->showAsQQ();
        }

        item->setInfo(friendrq->m_userID,friendrq->m_state,friendrq->m_szName,
                      QString(":/tx/%1.png").arg(friendrq->m_iconID));
    }

}

//处理聊天请求
void MyQQDialog::slot_ChatRq(char *buf, int nlen)
{
    //1.我->服务器->对方 2.对方->服务器->我
    STRU_CHAT_RQ* rq = (STRU_CHAT_RQ*) buf;
    //对于聊天窗口来说 对方用户是 rq->m_userID 自己是rq->m_friendID
    if(m_mapIDToChatdlg.find(rq->m_userID)!=m_mapIDToChatdlg.end())
    {
        ChatDialog* chat = m_mapIDToChatdlg[rq->m_userID];
        std::string strContent = rq->m_ChatContent;

        chat->slot_recvChatMsg(QString::fromStdString(strContent));

        //弹出聊天请求通知
        Notify *nf = new Notify;
        nf->setMsg( chat->m_name , chat->m_id , QString("[ %1 ]\n发来一则消息").arg(chat->m_name));
        nf->showAsQQ();
    }
}

//处理聊天回复
void MyQQDialog::slot_ChatRs(char *buf, int nlen)
{
    STRU_CHAT_RS* rs = (STRU_CHAT_RS*) buf;
    //对方不在线  1.我->服务器 2.我<-服务器
    //对方用户是 rq->m_friendID
    if(rs->m_result == user_is_offline)
    {
        if(m_mapIDToChatdlg.find(rs->m_friendID)!=m_mapIDToChatdlg.end())
        {
            ChatDialog* chat = m_mapIDToChatdlg[rs->m_friendID];
            chat->slot_showOffline();
        }
    }

}

//创建房间
void MyQQDialog::slot_createRoom()
{
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID = m_id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

//加入房间
void MyQQDialog::slot_joinRoom(QString roomid)
{
    int id = roomid.toInt();

    STRU_JOINROOM_RQ rq;
    rq.m_UserID = m_id;
    rq.m_RoomID = id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));
}

//离开房间
void MyQQDialog::slot_leaveRoom(int id)
{
    m_roomid = 0;

    STRU_LEAVEROOM_RQ rq;
    rq.m_nUserId = m_id;
    rq.m_RoomId = id;

    m_tcpClient->SendData((char*)&rq,sizeof(rq));

    //回收所有人的视频 从控件中移除显示
    for(auto ite=m_mapIDToVideoItem.begin();ite!=m_mapIDToVideoItem.end();++ite)
    {
        VideoItem* item = *ite;
        m_roomdlg->slot_removeVideoItem(item);
        delete item;
        item = NULL;
    }
    m_mapIDToVideoItem.clear();

    //关闭音频
    if(m_pAudioRead)
        m_pAudioRead->PauseAudio();//关闭音频采集

    //回收所有人的音频项
    for(auto ite=m_mapIDToAudioWrite.begin();ite!=m_mapIDToAudioWrite.end();++ite)
    {
        Audio_Write* item = *ite;
        delete item;
        item = NULL;
    }
    m_mapIDToAudioWrite.clear();
    m_roomid = 0;
}

//处理创建房间回复
void MyQQDialog::slot_CreateRoomRs(char *buf, int nlen)
{
    STRU_CREATEROOM_RS* rs = (STRU_CREATEROOM_RS*)buf;
    m_roomid = rs->m_RoomId;

    m_roomdlg->slot_setInfo(rs->m_RoomId);
    m_roomdlg->show();

    //添加自己video显示
    if(m_mapIDToVideoItem.find(m_id)==m_mapIDToVideoItem.end())
    {
        //自己的视频项还没创建
        VideoItem* item = new VideoItem;
        item->setInfo(m_id,m_UserName);
        connect(item,SIGNAL(SIG_itemClicked(int)),
                this,SLOT(slot_videoItemClicked(int)));
        m_roomdlg->slot_addVideoItem(item);
        m_mapIDToVideoItem[m_id] = item;
    }
}

//处理加入房间回复
void MyQQDialog::slot_JoinRoomRs(char *buf, int nlen)
{
    STRU_JOINROOM_RS* rs = (STRU_JOINROOM_RS*)buf;
    //房间存在
    if(rs->m_lResult)
    {
        m_roomid = rs->m_RoomID;

        m_roomdlg->slot_setInfo(rs->m_RoomID);
        m_roomdlg->show();

        //添加自己video显示
        if(m_mapIDToVideoItem.find(m_id)==m_mapIDToVideoItem.end())
        {
            //自己的视频项还没创建
            VideoItem* item = new VideoItem;
            item->setInfo(m_id,m_UserName);
            connect(item,SIGNAL(SIG_itemClicked(int)),
                    this,SLOT(slot_videoItemClicked(int)));
            m_roomdlg->slot_addVideoItem(item);
            m_mapIDToVideoItem[m_id] = item;
        }
    }
    else
    {
        QMessageBox::about(this,"提示","加入房间失败");
    }
}

//点击右侧缩略图 获取ID 名字
void MyQQDialog::slot_videoItemClicked(int id)
{
    VideoItem* item = (VideoItem*)QObject::sender();
    m_roomdlg->slot_setBigImageID(id,item->m_name);
}

//房间内好友列表
void MyQQDialog::slot_RoomMember(char *buf, int nlen)
{
    STRU_ROOM_MEMBER_RQ *rq = (STRU_ROOM_MEMBER_RQ*)buf;

    //video显示
    if(m_mapIDToVideoItem.find(rq->m_UserID)==m_mapIDToVideoItem.end())
    {
        //自己的视频项还没创建
        VideoItem* item = new VideoItem;
        item->setInfo(rq->m_UserID,rq->m_szUser);
        connect(item,SIGNAL(SIG_itemClicked(int)),
                this,SLOT(slot_videoItemClicked(int)));
        m_roomdlg->slot_addVideoItem(item);
        m_mapIDToVideoItem[rq->m_UserID] = item;
    }

    //音频
    if(m_mapIDToAudioWrite.find(rq->m_UserID)==m_mapIDToAudioWrite.end())
    {
        Audio_Write* item = new Audio_Write;
        m_mapIDToAudioWrite[rq->m_UserID] = item;
    }
}

//房间内某人离开
void MyQQDialog::slot_LeaveRoomRs(char *buf, int nlen)
{
    STRU_LEAVEROOM_RS* rs = (STRU_LEAVEROOM_RS*)buf;

    //map中删掉这个人 回收视频
    auto ite = m_mapIDToVideoItem.find(rs->m_UserID);
    if(ite!=m_mapIDToVideoItem.end())
    {
        VideoItem* item = *ite;
        m_roomdlg->slot_removeVideoItem(item);
        m_mapIDToVideoItem.erase(ite);
        delete item;
        item=NULL;
    }

    auto iteAudio = m_mapIDToAudioWrite[rs->m_UserID];
    if(iteAudio != m_mapIDToAudioWrite.end())
    {
        Audio_Write* item = m_mapIDToAudioWrite[rs->m_UserID];
        m_mapIDToAudioWrite.erase(iteAudio);
        delete item;
        item = NULL;
    }

}

#include<QBuffer>
//发送视频帧
void MyQQDialog::slot_sendVideoFrame(QImage &img)
{
    //刷新Ui
    slot_refreshImage(m_id,img);

    //将image图片转换成缓冲区
    QByteArray ba;
    QBuffer qbuf(&ba); //类似文件指针
    img.save(&qbuf,"JPEG");//将图片数据写入ba

    //发送到服务器
    //因为图片RGB不同 大小会变 要发不定长的包 不能用结构体
    //视频数据帧
    // 成员描述
    // int type;
    // int userId;
    // int roomId;
    // QByteArray videoFrame;
    char* buf = new char[12+ba.size()]; //3个int+图片
    char* tmp = buf;
    int type = DEF_PACK_VIDEO_FRAME;
    int userId = m_id;
    int roomId = m_roomid;

    *(int*)tmp = type; //*(int*)按照四个字节写
    tmp += sizeof(int);
    *(int*)tmp = userId; //*(int*)按照四个字节写
    tmp += sizeof(int);
    *(int*)tmp = roomId; //*(int*)按照四个字节写
    tmp += sizeof(int);

    memcpy(tmp,ba.data(),ba.size());

    m_tcpClient->SendData(buf,(12+ba.size()));
    delete []buf;
}

//刷新界面图片显示
void MyQQDialog::slot_refreshImage(int id,QImage &img)
{
    //发言的是自己 更新大图
    if(m_roomdlg->getUi()->wdg_video->m_id == id)
        m_roomdlg->getUi()->wdg_video->slot_setOneImage(img);

    //发言的不是自己 更新小图
    if(m_mapIDToVideoItem.find(id)!=m_mapIDToVideoItem.end())
    {
        VideoItem* item = m_mapIDToVideoItem[id];
        item->slot_setOneImage(img);
    }
}

//从服务器获取视频帧 并解析
void MyQQDialog::slot_VideoFrame(char *buf, int nlen)
{
    //buf -> image
    //视频数据帧
    // 成员描述
    // int type;
    // int userId;
    // int roomId;
    // QByteArray videoFrame;
    char* tmp = buf;
    int type = *(int*)tmp;
    tmp += sizeof(int);
    int userId = *(int*)tmp;
    tmp += sizeof(int);
    int roomId = *(int*)tmp;
    tmp += sizeof(int);

    QByteArray ba(tmp,nlen-12);
    QImage img;
    img.loadFromData(ba);

    this->slot_refreshImage(userId,img);
}

//发音频帧
void MyQQDialog::slot_sendAudioFrame(QByteArray byte)
{
    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;

    int type = DEF_PACK_AUDIO_FRAME;
    int userId = m_id;
    int roomId = m_roomid;

    char* buf = new char[12+byte.size()];
    char* tmp = buf;

    *(int*)tmp = type;
    tmp += sizeof(int);
    *(int*)tmp = userId;
    tmp += sizeof(int);
    *(int*)tmp = roomId;
    tmp += sizeof(int);

    memcpy(tmp,byte.data(),byte.size());

    m_tcpClient->SendData(buf,12+byte.size());
    delete []buf;

}

//解析音频并播放
void MyQQDialog::slot_AudioFrame(char *buf, int nlen)
{
    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// QByteArray audioFrame;

    char* tmp = buf;
    int type = *(int*)tmp;
    tmp += sizeof(int);
    int userId = *(int*)tmp;
    tmp += sizeof(int);
    int rooomId = *(int*)tmp;
    tmp += sizeof(int);

    if(m_mapIDToAudioWrite.find(userId)!=m_mapIDToAudioWrite.end())
    {
        QByteArray byte(tmp,nlen-12);
        Audio_Write* item = m_mapIDToAudioWrite[userId];
        item->slot_net_rx(byte);
    }
}

//双击用户响应
void MyQQDialog::slot_UserItemClicked()
{
    qDebug()<<__func__;
    //QObject::sender()返回发送者的指针
    UserItem *item = (UserItem *)QObject::sender();
    //显示聊天窗口
    if(m_mapIDToChatdlg.find(item->m_id)!=m_mapIDToChatdlg.end())
    {
        ChatDialog* chat = m_mapIDToChatdlg[item->m_id];
        chat->hide();
        chat->show();
    }
}

#include<QSettings>
#include<QCoreApplication>
#include<QFileInfo>

// [net]
//ip = "xxxx"

//加载配置文件 QSettings 以后IP直接从配置文件里改
void MyQQDialog::InitServerIP()
{
    //获取exe路径 拼接成配置文件路径
    QString path = QCoreApplication::applicationDirPath()+"/config.ini";
    QFileInfo info(path);
    if(info.exists())
    {
        //存在 读取设置ip
        //打开配置文件 存在则读取 不存在则创建
        QSettings setting(path,QSettings::IniFormat,NULL);
        setting.beginGroup("net");
        QVariant var = setting.value("ip");
        QString ip = var.toString();
        if(!ip.isEmpty())
            m_serverIP = ip;
        setting.endGroup();

        qDebug()<<m_serverIP;
    }
    else
    {
       //不存在则创建 并写默认ip
        QSettings setting(path,QSettings::IniFormat,NULL);
        setting.beginGroup("net");
        setting.setValue("ip",m_serverIP);

        setting.endGroup();
    }
}

//用户退出
void MyQQDialog::on_pb_close_clicked()
{
    //询问是否退出
    if(QMessageBox::question(this,"提示","是否退出程序")==QMessageBox::Yes)
    {
        //发送离线请求
        STRU_OFFLINE_RQ rq;
        rq.m_userID = m_id;
        m_tcpClient->SendData((char*)&rq,sizeof(rq));
        this->close(); //进入关闭事件函数 closeEvent
    }
}

void MyQQDialog::closeEvent(QCloseEvent *event)
{
    //回收资源
    this->slot_Delete();
    event->accept();
}

//发送聊天请求
void MyQQDialog::slot_SendChatRq(int id, QString content)
{
    STRU_CHAT_RQ rq;
    rq.m_userID = m_id;
    rq.m_friendID = id;

     std::string strContent = content.toStdString();
     strcpy_s(rq.m_ChatContent,MAX_CONTENT_LEN,strContent.c_str());

     m_tcpClient->SendData((char*)&rq,sizeof(rq));

}
