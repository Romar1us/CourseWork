/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *read_from_file_action;
    QAction *write_to_file_action;
    QWidget *centralwidget;
    QListWidget *projects_list_widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add_project_pb;
    QPushButton *alter_project_pb;
    QPushButton *delete_project_pb;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *filter_projects_pb;
    QPushButton *clear_filters_pb;
    QLineEdit *project_amount_view_le;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *sort_projects_pb;
    QPushButton *cancel_sort_pb;
    QPushButton *graph_pb;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 600);
        read_from_file_action = new QAction(MainWindow);
        read_from_file_action->setObjectName("read_from_file_action");
        write_to_file_action = new QAction(MainWindow);
        write_to_file_action->setObjectName("write_to_file_action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        projects_list_widget = new QListWidget(centralwidget);
        projects_list_widget->setObjectName("projects_list_widget");
        projects_list_widget->setGeometry(QRect(10, 10, 981, 361));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 440, 160, 103));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_project_pb = new QPushButton(verticalLayoutWidget);
        add_project_pb->setObjectName("add_project_pb");

        verticalLayout->addWidget(add_project_pb);

        alter_project_pb = new QPushButton(verticalLayoutWidget);
        alter_project_pb->setObjectName("alter_project_pb");

        verticalLayout->addWidget(alter_project_pb);

        delete_project_pb = new QPushButton(verticalLayoutWidget);
        delete_project_pb->setObjectName("delete_project_pb");

        verticalLayout->addWidget(delete_project_pb);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(200, 440, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        filter_projects_pb = new QPushButton(verticalLayoutWidget_2);
        filter_projects_pb->setObjectName("filter_projects_pb");

        verticalLayout_2->addWidget(filter_projects_pb);

        clear_filters_pb = new QPushButton(verticalLayoutWidget_2);
        clear_filters_pb->setObjectName("clear_filters_pb");

        verticalLayout_2->addWidget(clear_filters_pb);

        project_amount_view_le = new QLineEdit(centralwidget);
        project_amount_view_le->setObjectName("project_amount_view_le");
        project_amount_view_le->setGeometry(QRect(10, 370, 981, 28));
        project_amount_view_le->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        project_amount_view_le->setFrame(false);
        project_amount_view_le->setReadOnly(true);
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(370, 440, 164, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        sort_projects_pb = new QPushButton(verticalLayoutWidget_3);
        sort_projects_pb->setObjectName("sort_projects_pb");

        verticalLayout_3->addWidget(sort_projects_pb);

        cancel_sort_pb = new QPushButton(verticalLayoutWidget_3);
        cancel_sort_pb->setObjectName("cancel_sort_pb");

        verticalLayout_3->addWidget(cancel_sort_pb);

        graph_pb = new QPushButton(centralwidget);
        graph_pb->setObjectName("graph_pb");
        graph_pb->setGeometry(QRect(550, 440, 158, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(read_from_file_action);
        menu->addSeparator();
        menu->addAction(write_to_file_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        read_from_file_action->setText(QCoreApplication::translate("MainWindow", "\320\227\321\207\320\270\321\202\320\260\321\202\320\270 \320\267 \321\204\320\260\320\271\320\273\321\203", nullptr));
        write_to_file_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\320\270 \321\203 \321\204\320\260\320\271\320\273", nullptr));
        add_project_pb->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        alter_project_pb->setText(QCoreApplication::translate("MainWindow", "\320\227\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
        delete_project_pb->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
        filter_projects_pb->setText(QCoreApplication::translate("MainWindow", "\320\244\321\226\320\273\321\214\321\202\321\200\321\203\320\262\320\260\321\202\320\270", nullptr));
        clear_filters_pb->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\270\320\275\321\203\321\202\320\270 \321\204\321\226\320\273\321\214\321\202\321\200\320\270", nullptr));
        sort_projects_pb->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270", nullptr));
        cancel_sort_pb->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\260\321\201\321\203\320\262\320\260\321\202\320\270 \321\201\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217", nullptr));
        graph_pb->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\321\226\320\272", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
