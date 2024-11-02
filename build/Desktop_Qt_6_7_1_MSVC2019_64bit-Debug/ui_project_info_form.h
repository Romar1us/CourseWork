/********************************************************************************
** Form generated from reading UI file 'project_info_form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_INFO_FORM_H
#define UI_PROJECT_INFO_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectInfoForm
{
public:
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *time_amount_le;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *project_name_le;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *project_status_le;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *project_manager_le;
    QPushButton *add_project_pb;

    void setupUi(QWidget *ProjectInfoForm)
    {
        if (ProjectInfoForm->objectName().isEmpty())
            ProjectInfoForm->setObjectName("ProjectInfoForm");
        ProjectInfoForm->resize(400, 300);
        horizontalLayoutWidget_3 = new QWidget(ProjectInfoForm);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(20, 100, 151, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        time_amount_le = new QLineEdit(horizontalLayoutWidget_3);
        time_amount_le->setObjectName("time_amount_le");

        horizontalLayout_3->addWidget(time_amount_le);

        horizontalLayoutWidget = new QWidget(ProjectInfoForm);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 251, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        project_name_le = new QLineEdit(horizontalLayoutWidget);
        project_name_le->setObjectName("project_name_le");

        horizontalLayout->addWidget(project_name_le);

        horizontalLayoutWidget_4 = new QWidget(ProjectInfoForm);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(20, 140, 221, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        project_status_le = new QLineEdit(horizontalLayoutWidget_4);
        project_status_le->setObjectName("project_status_le");

        horizontalLayout_4->addWidget(project_status_le);

        horizontalLayoutWidget_2 = new QWidget(ProjectInfoForm);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 60, 251, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        project_manager_le = new QLineEdit(horizontalLayoutWidget_2);
        project_manager_le->setObjectName("project_manager_le");

        horizontalLayout_2->addWidget(project_manager_le);

        add_project_pb = new QPushButton(ProjectInfoForm);
        add_project_pb->setObjectName("add_project_pb");
        add_project_pb->setGeometry(QRect(140, 240, 83, 29));

        retranslateUi(ProjectInfoForm);

        QMetaObject::connectSlotsByName(ProjectInfoForm);
    } // setupUi

    void retranslateUi(QWidget *ProjectInfoForm)
    {
        ProjectInfoForm->setWindowTitle(QCoreApplication::translate("ProjectInfoForm", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("ProjectInfoForm", "\320\247\320\260\321\201", nullptr));
        label->setText(QCoreApplication::translate("ProjectInfoForm", "\320\235\320\260\320\267\320\262\320\260 \320\277\321\200\320\276\320\265\320\272\321\202\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("ProjectInfoForm", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("ProjectInfoForm", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200", nullptr));
        add_project_pb->setText(QCoreApplication::translate("ProjectInfoForm", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectInfoForm: public Ui_ProjectInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_INFO_FORM_H
