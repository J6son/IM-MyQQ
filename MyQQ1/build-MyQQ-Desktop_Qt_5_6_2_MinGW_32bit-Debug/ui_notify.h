/********************************************************************************
** Form generated from reading UI file 'notify.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFY_H
#define UI_NOTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notify
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_tittle;
    QSpacerItem *horizontalSpacer;
    QPushButton *CloseWnd;
    QLabel *lb_content;
    QPushButton *pb_show;

    void setupUi(QWidget *Notify)
    {
        if (Notify->objectName().isEmpty())
            Notify->setObjectName(QStringLiteral("Notify"));
        Notify->resize(270, 110);
        Notify->setMinimumSize(QSize(270, 110));
        Notify->setMaximumSize(QSize(1000000, 1000000));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Notify->setFont(font);
        widget = new QWidget(Notify);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 270, 31));
        widget->setMinimumSize(QSize(270, 31));
        widget->setMaximumSize(QSize(270, 31));
        widget->setStyleSheet(QStringLiteral("background-color:#31A66B;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lb_tittle = new QLabel(widget);
        lb_tittle->setObjectName(QStringLiteral("lb_tittle"));
        lb_tittle->setMinimumSize(QSize(80, 30));
        lb_tittle->setMaximumSize(QSize(80, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        lb_tittle->setFont(font1);
        lb_tittle->setStyleSheet(QLatin1String(" \n"
"color: rgb(255, 255, 255);"));
        lb_tittle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lb_tittle);

        horizontalSpacer = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CloseWnd = new QPushButton(widget);
        CloseWnd->setObjectName(QStringLiteral("CloseWnd"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CloseWnd->sizePolicy().hasHeightForWidth());
        CloseWnd->setSizePolicy(sizePolicy);
        CloseWnd->setMinimumSize(QSize(30, 30));
        CloseWnd->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        CloseWnd->setFont(font2);
        CloseWnd->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        CloseWnd->setIconSize(QSize(30, 30));
        CloseWnd->setAutoDefault(true);
        CloseWnd->setFlat(true);

        horizontalLayout->addWidget(CloseWnd);

        lb_content = new QLabel(Notify);
        lb_content->setObjectName(QStringLiteral("lb_content"));
        lb_content->setGeometry(QRect(10, 30, 181, 71));
        QFont font3;
        font3.setPointSize(12);
        lb_content->setFont(font3);
        lb_content->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pb_show = new QPushButton(Notify);
        pb_show->setObjectName(QStringLiteral("pb_show"));
        pb_show->setGeometry(QRect(200, 50, 60, 30));
        pb_show->setFont(font3);
        pb_show->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"background-color: #31A668;\n"
"color: #FFFFFF;"));

        retranslateUi(Notify);

        QMetaObject::connectSlotsByName(Notify);
    } // setupUi

    void retranslateUi(QWidget *Notify)
    {
        Notify->setWindowTitle(QApplication::translate("Notify", "Form", 0));
        lb_tittle->setText(QApplication::translate("Notify", "\346\266\210\346\201\257\351\200\232\347\237\245", 0));
        CloseWnd->setText(QApplication::translate("Notify", "X", 0));
        lb_content->setText(QApplication::translate("Notify", "\347\224\250\346\210\267 AAA \n"
"\345\217\221\346\235\245\344\270\200\345\210\231\346\266\210\346\201\257", 0));
        pb_show->setText(QApplication::translate("Notify", "\346\237\245\347\234\213", 0));
    } // retranslateUi

};

namespace Ui {
    class Notify: public Ui_Notify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFY_H
