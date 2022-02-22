/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_title;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_title;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QWidget *wdg_content;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_left_top;
    QTextBrowser *tb_chat;
    QWidget *wdg_tools;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_tool1;
    QPushButton *pb_tool2;
    QPushButton *pb_tool3;
    QPushButton *pb_tool4;
    QPushButton *pb_tool5;
    QSpacerItem *horizontalSpacer;
    QWidget *wdg_left_bottom;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *te_chat;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_send;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tw_page;
    QWidget *tab_1;
    QWidget *tab_2;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(800, 600);
        ChatDialog->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        ChatDialog->setFont(font);
        ChatDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(ChatDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_title = new QWidget(ChatDialog);
        wdg_title->setObjectName(QStringLiteral("wdg_title"));
        wdg_title->setMinimumSize(QSize(800, 40));
        wdg_title->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_4 = new QHBoxLayout(wdg_title);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lb_title = new QLabel(wdg_title);
        lb_title->setObjectName(QStringLiteral("lb_title"));
        lb_title->setMinimumSize(QSize(161, 30));
        lb_title->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(lb_title);

        horizontalSpacer_3 = new QSpacerItem(496, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pb_min = new QPushButton(wdg_title);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pb_min);

        pb_max = new QPushButton(wdg_title);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        pb_max->setFont(font1);

        horizontalLayout_4->addWidget(pb_max);

        pb_close = new QPushButton(wdg_title);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pb_close);


        verticalLayout->addWidget(wdg_title);

        wdg_content = new QWidget(ChatDialog);
        wdg_content->setObjectName(QStringLiteral("wdg_content"));
        horizontalLayout = new QHBoxLayout(wdg_content);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_left = new QWidget(wdg_content);
        wdg_left->setObjectName(QStringLiteral("wdg_left"));
        verticalLayout_3 = new QVBoxLayout(wdg_left);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        wdg_left_top = new QWidget(wdg_left);
        wdg_left_top->setObjectName(QStringLiteral("wdg_left_top"));
        tb_chat = new QTextBrowser(wdg_left_top);
        tb_chat->setObjectName(QStringLiteral("tb_chat"));
        tb_chat->setGeometry(QRect(0, 10, 561, 291));

        verticalLayout_3->addWidget(wdg_left_top);

        wdg_tools = new QWidget(wdg_left);
        wdg_tools->setObjectName(QStringLiteral("wdg_tools"));
        wdg_tools->setMinimumSize(QSize(561, 30));
        wdg_tools->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(wdg_tools);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        pb_tool1 = new QPushButton(wdg_tools);
        pb_tool1->setObjectName(QStringLiteral("pb_tool1"));
        pb_tool1->setMinimumSize(QSize(30, 30));
        pb_tool1->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bq/0.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tool1->setIcon(icon);
        pb_tool1->setIconSize(QSize(30, 30));
        pb_tool1->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool1);

        pb_tool2 = new QPushButton(wdg_tools);
        pb_tool2->setObjectName(QStringLiteral("pb_tool2"));
        pb_tool2->setMinimumSize(QSize(30, 30));
        pb_tool2->setMaximumSize(QSize(30, 30));
        pb_tool2->setIcon(icon);
        pb_tool2->setIconSize(QSize(30, 30));
        pb_tool2->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool2);

        pb_tool3 = new QPushButton(wdg_tools);
        pb_tool3->setObjectName(QStringLiteral("pb_tool3"));
        pb_tool3->setMinimumSize(QSize(30, 30));
        pb_tool3->setMaximumSize(QSize(30, 30));
        pb_tool3->setIcon(icon);
        pb_tool3->setIconSize(QSize(30, 30));
        pb_tool3->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool3);

        pb_tool4 = new QPushButton(wdg_tools);
        pb_tool4->setObjectName(QStringLiteral("pb_tool4"));
        pb_tool4->setMinimumSize(QSize(30, 30));
        pb_tool4->setMaximumSize(QSize(30, 30));
        pb_tool4->setIcon(icon);
        pb_tool4->setIconSize(QSize(30, 30));
        pb_tool4->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool4);

        pb_tool5 = new QPushButton(wdg_tools);
        pb_tool5->setObjectName(QStringLiteral("pb_tool5"));
        pb_tool5->setMinimumSize(QSize(30, 30));
        pb_tool5->setMaximumSize(QSize(30, 30));
        pb_tool5->setIcon(icon);
        pb_tool5->setIconSize(QSize(30, 30));
        pb_tool5->setFlat(true);

        horizontalLayout_2->addWidget(pb_tool5);

        horizontalSpacer = new QSpacerItem(377, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(wdg_tools);

        wdg_left_bottom = new QWidget(wdg_left);
        wdg_left_bottom->setObjectName(QStringLiteral("wdg_left_bottom"));
        wdg_left_bottom->setMinimumSize(QSize(561, 220));
        wdg_left_bottom->setMaximumSize(QSize(16777215, 220));
        verticalLayout_4 = new QVBoxLayout(wdg_left_bottom);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        te_chat = new QTextEdit(wdg_left_bottom);
        te_chat->setObjectName(QStringLiteral("te_chat"));

        verticalLayout_4->addWidget(te_chat);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pb_send = new QPushButton(wdg_left_bottom);
        pb_send->setObjectName(QStringLiteral("pb_send"));
        pb_send->setMinimumSize(QSize(75, 30));
        pb_send->setMaximumSize(QSize(75, 30));

        horizontalLayout_3->addWidget(pb_send);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(wdg_left_bottom);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new QWidget(wdg_content);
        wdg_right->setObjectName(QStringLiteral("wdg_right"));
        wdg_right->setMinimumSize(QSize(230, 561));
        wdg_right->setMaximumSize(QSize(230, 16777215));
        wdg_right->setFont(font);
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tw_page = new QTabWidget(wdg_right);
        tw_page->setObjectName(QStringLiteral("tw_page"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tw_page->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tw_page->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tw_page);


        horizontalLayout->addWidget(wdg_right);


        verticalLayout->addWidget(wdg_content);


        retranslateUi(ChatDialog);

        tw_page->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Dialog", 0));
        lb_title->setText(QApplication::translate("ChatDialog", "\344\270\216[ name ]\347\232\204\350\201\212\345\244\251", 0));
        pb_min->setText(QApplication::translate("ChatDialog", "-", 0));
        pb_max->setText(QApplication::translate("ChatDialog", "\345\217\243", 0));
        pb_close->setText(QApplication::translate("ChatDialog", "X", 0));
        pb_tool1->setText(QString());
        pb_tool2->setText(QString());
        pb_tool3->setText(QString());
        pb_tool4->setText(QString());
        pb_tool5->setText(QString());
        pb_send->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201", 0));
        tw_page->setTabText(tw_page->indexOf(tab_1), QApplication::translate("ChatDialog", "\345\261\236\346\200\2471", 0));
        tw_page->setTabText(tw_page->indexOf(tab_2), QApplication::translate("ChatDialog", "\345\261\236\346\200\2472", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
