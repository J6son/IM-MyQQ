#ifndef VIDEOITEM_H
#define VIDEOITEM_H

#include <QWidget>
#include<QImage>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QTimer>
#include<QTime>

namespace Ui {
class VideoItem;
}

class VideoItem : public QWidget
{
    Q_OBJECT

public:
    explicit VideoItem(QWidget *parent = 0);
    ~VideoItem();
signals:
    void SIG_itemClicked(int id);
public slots:
    void setInfo(int id,QString name);
    void slot_setOneImage(QImage );

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void slot_CheckTime();
private:
    Ui::VideoItem *ui;
public:
    int m_id;
    QString m_name;

    QImage m_image;

    QTimer* m_timer;
    QTime m_lastTime;
    QImage m_defaultImg;
};

#endif // VIDEOITEM_H
