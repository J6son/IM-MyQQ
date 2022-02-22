#ifndef NOTIFY_H
#define NOTIFY_H

#include <QWidget>

#include<QPoint>

#include<QRect>
#include<QTimer>
#include<QEvent>


namespace Ui {
class Notify;
}

class Notify : public QWidget
{
    Q_OBJECT

public:
    explicit Notify(QWidget *parent = 0);
    ~Notify();
    void setInfo(const QString &name , quint32 id);

signals:
    void SIG_showChatDlg(quint32 id);

public slots:

    void on_pb_show_clicked();

    void on_CloseWnd_clicked();

    void showAsQQ();

    void setMsg(const QString &name, quint32 id , QString msg);

    void myMove();
    void myStay();
    void myClose();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *) ;

private:
    Ui::Notify *ui;

    QString m_name;
    quint32 m_id;

    QPoint normalPoint;
    QRect deskRect;
    bool isEnter;
    QTimer *timerShow;
    QTimer *timerStay;
    QTimer *timerClose;


};

#endif // NOTIFY_H
