/********************************************************************************
** Form generated from reading UI file 'myqqdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQQDIALOG_H
#define UI_MYQQDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imtoolbox.h"

QT_BEGIN_NAMESPACE

class Ui_MyQQDialog
{
public:
    QWidget *wdg__title;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_close;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_icon;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cbx_state;
    QLabel *lb_name;
    QLineEdit *le_feeling;
    QWidget *wdg_search;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pb_search;
    QLineEdit *le_search;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_page;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pb_friend;
    QPushButton *pb_group;
    QPushButton *pb_space;
    QStackedWidget *sw_page;
    QWidget *page_1;
    QVBoxLayout *verticalLayout;
    IMToolBox *wdg_box;
    QWidget *page_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_menu;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_test;
    QPushButton *pb_test2;
    QPushButton *ppb_test3;

    void setupUi(QDialog *MyQQDialog)
    {
        if (MyQQDialog->objectName().isEmpty())
            MyQQDialog->setObjectName(QStringLiteral("MyQQDialog"));
        MyQQDialog->resize(300, 638);
        MyQQDialog->setMinimumSize(QSize(300, 630));
        MyQQDialog->setSizeGripEnabled(true);
        wdg__title = new QWidget(MyQQDialog);
        wdg__title->setObjectName(QStringLiteral("wdg__title"));
        wdg__title->setGeometry(QRect(0, 3, 301, 40));
        wdg__title->setMinimumSize(QSize(301, 40));
        wdg__title->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(wdg__title);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        lb_title = new QLabel(wdg__title);
        lb_title->setObjectName(QStringLiteral("lb_title"));
        lb_title->setMinimumSize(QSize(72, 30));
        QFont font;
        font.setPointSize(15);
        lb_title->setFont(font);

        horizontalLayout->addWidget(lb_title);

        horizontalSpacer = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg__title);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        pb_min->setFont(font1);

        horizontalLayout->addWidget(pb_min);

        pb_close = new QPushButton(wdg__title);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(true);
        font2.setWeight(75);
        pb_close->setFont(font2);

        horizontalLayout->addWidget(pb_close);

        wdg_top = new QWidget(MyQQDialog);
        wdg_top->setObjectName(QStringLiteral("wdg_top"));
        wdg_top->setGeometry(QRect(0, 43, 301, 61));
        wdg_top->setMinimumSize(QSize(301, 61));
        wdg_top->setMaximumSize(QSize(16777215, 61));
        horizontalLayout_3 = new QHBoxLayout(wdg_top);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(4, 0, 0, 0);
        pb_icon = new QPushButton(wdg_top);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setMinimumSize(QSize(60, 60));
        pb_icon->setMaximumSize(QSize(60, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tx/13.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(50, 50));
        pb_icon->setFlat(true);

        horizontalLayout_3->addWidget(pb_icon);

        wdg_right = new QWidget(wdg_top);
        wdg_right->setObjectName(QStringLiteral("wdg_right"));
        wdg_right->setMinimumSize(QSize(0, 61));
        wdg_right->setMaximumSize(QSize(16777215, 61));
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 0, 5, 4);
        widget_6 = new QWidget(wdg_right);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 31));
        widget_6->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cbx_state = new QComboBox(widget_6);
        cbx_state->setObjectName(QStringLiteral("cbx_state"));
        cbx_state->setMinimumSize(QSize(10, 25));
        cbx_state->setMaximumSize(QSize(60, 16777215));
        QFont font3;
        font3.setPointSize(10);
        cbx_state->setFont(font3);

        horizontalLayout_2->addWidget(cbx_state);

        lb_name = new QLabel(widget_6);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setMinimumSize(QSize(0, 20));
        lb_name->setFont(font3);

        horizontalLayout_2->addWidget(lb_name);


        verticalLayout_2->addWidget(widget_6);

        le_feeling = new QLineEdit(wdg_right);
        le_feeling->setObjectName(QStringLiteral("le_feeling"));
        le_feeling->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(le_feeling);


        horizontalLayout_3->addWidget(wdg_right);

        wdg_search = new QWidget(MyQQDialog);
        wdg_search->setObjectName(QStringLiteral("wdg_search"));
        wdg_search->setGeometry(QRect(0, 104, 301, 51));
        wdg_search->setMinimumSize(QSize(301, 51));
        wdg_search->setMaximumSize(QSize(16777215, 51));
        horizontalLayout_4 = new QHBoxLayout(wdg_search);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pb_search = new QPushButton(wdg_search);
        pb_search->setObjectName(QStringLiteral("pb_search"));
        pb_search->setMinimumSize(QSize(30, 30));
        pb_search->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/searchbox_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_search->setIcon(icon1);
        pb_search->setIconSize(QSize(40, 40));

        horizontalLayout_4->addWidget(pb_search);

        le_search = new QLineEdit(wdg_search);
        le_search->setObjectName(QStringLiteral("le_search"));
        le_search->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(le_search);

        widget_3 = new QWidget(MyQQDialog);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 155, 301, 401));
        widget_3->setMinimumSize(QSize(301, 401));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        wdg_page = new QWidget(widget_3);
        wdg_page->setObjectName(QStringLiteral("wdg_page"));
        wdg_page->setMinimumSize(QSize(291, 31));
        wdg_page->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_7 = new QHBoxLayout(wdg_page);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        pb_friend = new QPushButton(wdg_page);
        pb_friend->setObjectName(QStringLiteral("pb_friend"));
        pb_friend->setMaximumSize(QSize(16777215, 30));
        pb_friend->setFont(font3);
        pb_friend->setCheckable(true);
        pb_friend->setChecked(true);
        pb_friend->setFlat(true);

        horizontalLayout_7->addWidget(pb_friend);

        pb_group = new QPushButton(wdg_page);
        pb_group->setObjectName(QStringLiteral("pb_group"));
        pb_group->setMaximumSize(QSize(16777215, 30));
        pb_group->setFont(font3);
        pb_group->setCheckable(true);
        pb_group->setChecked(false);
        pb_group->setFlat(true);

        horizontalLayout_7->addWidget(pb_group);

        pb_space = new QPushButton(wdg_page);
        pb_space->setObjectName(QStringLiteral("pb_space"));
        pb_space->setMaximumSize(QSize(16777215, 30));
        pb_space->setFont(font3);
        pb_space->setCheckable(true);
        pb_space->setChecked(false);
        pb_space->setFlat(true);

        horizontalLayout_7->addWidget(pb_space);


        verticalLayout_3->addWidget(wdg_page);

        sw_page = new QStackedWidget(widget_3);
        sw_page->setObjectName(QStringLiteral("sw_page"));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        verticalLayout = new QVBoxLayout(page_1);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_box = new IMToolBox(page_1);
        wdg_box->setObjectName(QStringLiteral("wdg_box"));

        verticalLayout->addWidget(wdg_box);

        sw_page->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        sw_page->addWidget(page_2);

        verticalLayout_3->addWidget(sw_page);

        sw_page->raise();
        wdg_page->raise();
        widget_4 = new QWidget(MyQQDialog);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 574, 301, 61));
        widget_4->setMinimumSize(QSize(301, 61));
        widget_4->setMaximumSize(QSize(16777215, 61));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pb_menu = new QPushButton(widget_4);
        pb_menu->setObjectName(QStringLiteral("pb_menu"));
        pb_menu->setMinimumSize(QSize(30, 30));
        pb_menu->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_menu->setIcon(icon2);
        pb_menu->setIconSize(QSize(30, 30));
        pb_menu->setFlat(true);

        horizontalLayout_6->addWidget(pb_menu);

        horizontalSpacer_2 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pb_test = new QPushButton(widget_4);
        pb_test->setObjectName(QStringLiteral("pb_test"));
        pb_test->setMinimumSize(QSize(30, 30));
        pb_test->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_test->setIcon(icon3);
        pb_test->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(pb_test);

        pb_test2 = new QPushButton(widget_4);
        pb_test2->setObjectName(QStringLiteral("pb_test2"));
        pb_test2->setMinimumSize(QSize(30, 30));
        pb_test2->setMaximumSize(QSize(30, 30));
        pb_test2->setIcon(icon3);
        pb_test2->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(pb_test2);

        ppb_test3 = new QPushButton(widget_4);
        ppb_test3->setObjectName(QStringLiteral("ppb_test3"));
        ppb_test3->setMaximumSize(QSize(30, 30));
        ppb_test3->setIcon(icon3);
        ppb_test3->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(ppb_test3);


        retranslateUi(MyQQDialog);

        sw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyQQDialog);
    } // setupUi

    void retranslateUi(QDialog *MyQQDialog)
    {
        MyQQDialog->setWindowTitle(QApplication::translate("MyQQDialog", "MyQQDialog", 0));
        lb_title->setText(QApplication::translate("MyQQDialog", "MyQQ", 0));
        pb_min->setText(QApplication::translate("MyQQDialog", "-", 0));
        pb_close->setText(QApplication::translate("MyQQDialog", "x", 0));
        pb_icon->setText(QString());
        cbx_state->clear();
        cbx_state->insertItems(0, QStringList()
         << QApplication::translate("MyQQDialog", "\345\234\250\347\272\277", 0)
         << QApplication::translate("MyQQDialog", "\347\246\273\347\272\277", 0)
         << QApplication::translate("MyQQDialog", "\345\277\231\347\242\214", 0)
        );
        lb_name->setText(QApplication::translate("MyQQDialog", "TextLabel", 0));
        pb_search->setText(QString());
        pb_friend->setText(QApplication::translate("MyQQDialog", "\345\245\275\345\217\213", 0));
        pb_group->setText(QApplication::translate("MyQQDialog", "\347\276\244\347\273\204", 0));
        pb_space->setText(QApplication::translate("MyQQDialog", "\347\251\272\351\227\264", 0));
        pb_menu->setText(QString());
        pb_test->setText(QString());
        pb_test2->setText(QString());
        ppb_test3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyQQDialog: public Ui_MyQQDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQQDIALOG_H
