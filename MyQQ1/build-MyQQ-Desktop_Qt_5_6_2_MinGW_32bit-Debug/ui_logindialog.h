/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *lb_name;
    QLabel *lb_password;
    QLineEdit *le_name;
    QLineEdit *le_password;
    QPushButton *pb_clear;
    QPushButton *pb_commit;
    QWidget *tab_5;
    QLabel *lb_register_name;
    QLineEdit *le_register_password;
    QLineEdit *le_register_name;
    QLabel *lb_register_password;
    QLabel *lb_register_confirm;
    QLineEdit *le_register_confirm;
    QPushButton *pb_register_clear;
    QPushButton *pb_register_commit;
    QLabel *lb_icon;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(614, 380);
        tabWidget_2 = new QTabWidget(LoginDialog);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(200, 20, 381, 301));
        QFont font;
        font.setPointSize(12);
        tabWidget_2->setFont(font);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lb_name = new QLabel(tab_3);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setGeometry(QRect(20, 40, 72, 30));
        QFont font1;
        font1.setPointSize(9);
        lb_name->setFont(font1);
        lb_password = new QLabel(tab_3);
        lb_password->setObjectName(QStringLiteral("lb_password"));
        lb_password->setGeometry(QRect(30, 90, 72, 30));
        lb_password->setFont(font1);
        le_name = new QLineEdit(tab_3);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(120, 40, 191, 30));
        le_password = new QLineEdit(tab_3);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setGeometry(QRect(120, 90, 191, 30));
        le_password->setEchoMode(QLineEdit::Password);
        pb_clear = new QPushButton(tab_3);
        pb_clear->setObjectName(QStringLiteral("pb_clear"));
        pb_clear->setGeometry(QRect(160, 220, 93, 28));
        pb_commit = new QPushButton(tab_3);
        pb_commit->setObjectName(QStringLiteral("pb_commit"));
        pb_commit->setGeometry(QRect(270, 220, 93, 28));
        tabWidget_2->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        lb_register_name = new QLabel(tab_5);
        lb_register_name->setObjectName(QStringLiteral("lb_register_name"));
        lb_register_name->setGeometry(QRect(30, 50, 72, 30));
        lb_register_name->setFont(font1);
        le_register_password = new QLineEdit(tab_5);
        le_register_password->setObjectName(QStringLiteral("le_register_password"));
        le_register_password->setGeometry(QRect(130, 90, 191, 30));
        le_register_password->setEchoMode(QLineEdit::Password);
        le_register_name = new QLineEdit(tab_5);
        le_register_name->setObjectName(QStringLiteral("le_register_name"));
        le_register_name->setGeometry(QRect(130, 50, 191, 30));
        lb_register_password = new QLabel(tab_5);
        lb_register_password->setObjectName(QStringLiteral("lb_register_password"));
        lb_register_password->setGeometry(QRect(30, 90, 72, 30));
        lb_register_password->setFont(font1);
        lb_register_confirm = new QLabel(tab_5);
        lb_register_confirm->setObjectName(QStringLiteral("lb_register_confirm"));
        lb_register_confirm->setGeometry(QRect(30, 140, 72, 30));
        lb_register_confirm->setFont(font1);
        le_register_confirm = new QLineEdit(tab_5);
        le_register_confirm->setObjectName(QStringLiteral("le_register_confirm"));
        le_register_confirm->setGeometry(QRect(130, 140, 191, 30));
        le_register_confirm->setEchoMode(QLineEdit::Password);
        pb_register_clear = new QPushButton(tab_5);
        pb_register_clear->setObjectName(QStringLiteral("pb_register_clear"));
        pb_register_clear->setGeometry(QRect(150, 220, 93, 28));
        pb_register_commit = new QPushButton(tab_5);
        pb_register_commit->setObjectName(QStringLiteral("pb_register_commit"));
        pb_register_commit->setGeometry(QRect(260, 220, 93, 28));
        tabWidget_2->addTab(tab_5, QString());
        lb_icon = new QLabel(LoginDialog);
        lb_icon->setObjectName(QStringLiteral("lb_icon"));
        lb_icon->setGeometry(QRect(10, 70, 171, 231));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/tx/6.png")));
        lb_icon->setScaledContents(true);
        lb_icon->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(tabWidget_2, le_name);
        QWidget::setTabOrder(le_name, le_password);
        QWidget::setTabOrder(le_password, pb_commit);
        QWidget::setTabOrder(pb_commit, pb_clear);
        QWidget::setTabOrder(pb_clear, le_register_name);
        QWidget::setTabOrder(le_register_name, le_register_password);
        QWidget::setTabOrder(le_register_password, le_register_confirm);
        QWidget::setTabOrder(le_register_confirm, pb_register_commit);
        QWidget::setTabOrder(pb_register_commit, pb_register_clear);

        retranslateUi(LoginDialog);

        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        lb_name->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0));
        lb_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
#ifndef QT_NO_TOOLTIP
        le_name->setToolTip(QApplication::translate("LoginDialog", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\357\274\214\351\225\277\345\272\246 \344\270\215\350\266\205\350\277\20710 \344\275\215", 0));
#endif // QT_NO_TOOLTIP
        pb_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        pb_commit->setText(QApplication::translate("LoginDialog", "\346\217\220\344\272\244", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("LoginDialog", "  \347\231\273\345\275\225  ", 0));
        lb_register_name->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0));
        lb_register_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        lb_register_confirm->setText(QApplication::translate("LoginDialog", "\347\241\256\350\256\244", 0));
        pb_register_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        pb_register_commit->setText(QApplication::translate("LoginDialog", "\346\217\220\344\272\244", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("LoginDialog", "  \346\263\250\345\206\214  ", 0));
        lb_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
