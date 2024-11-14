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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectInfoForm
{
public:
    QPushButton *action_pb;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *project_name_le;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *project_manager_le;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *time_amount_le;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *project_status_le;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDateEdit *date_de;

    void setupUi(QWidget *ProjectInfoForm)
    {
        if (ProjectInfoForm->objectName().isEmpty())
            ProjectInfoForm->setObjectName("ProjectInfoForm");
        ProjectInfoForm->resize(400, 297);
        action_pb = new QPushButton(ProjectInfoForm);
        action_pb->setObjectName("action_pb");
        action_pb->setGeometry(QRect(140, 240, 83, 29));
        verticalLayoutWidget = new QWidget(ProjectInfoForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 292, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        project_name_le = new QLineEdit(verticalLayoutWidget);
        project_name_le->setObjectName("project_name_le");

        horizontalLayout->addWidget(project_name_le);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        project_manager_le = new QLineEdit(verticalLayoutWidget);
        project_manager_le->setObjectName("project_manager_le");

        horizontalLayout_2->addWidget(project_manager_le);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        time_amount_le = new QLineEdit(verticalLayoutWidget);
        time_amount_le->setObjectName("time_amount_le");

        horizontalLayout_3->addWidget(time_amount_le);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        project_status_le = new QLineEdit(verticalLayoutWidget);
        project_status_le->setObjectName("project_status_le");

        horizontalLayout_4->addWidget(project_status_le);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        date_de = new QDateEdit(verticalLayoutWidget);
        date_de->setObjectName("date_de");

        horizontalLayout_5->addWidget(date_de);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(ProjectInfoForm);

        QMetaObject::connectSlotsByName(ProjectInfoForm);
    } // setupUi

    void retranslateUi(QWidget *ProjectInfoForm)
    {
        ProjectInfoForm->setWindowTitle(QCoreApplication::translate("ProjectInfoForm", "Form", nullptr));
        action_pb->setText(QString());
        label->setText(QCoreApplication::translate("ProjectInfoForm", "\320\235\320\260\320\267\320\262\320\260 \320\277\321\200\320\276\320\265\320\272\321\202\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("ProjectInfoForm", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200      ", nullptr));
        label_3->setText(QCoreApplication::translate("ProjectInfoForm", "\320\247\320\260\321\201                   ", nullptr));
        label_4->setText(QCoreApplication::translate("ProjectInfoForm", "\320\241\321\202\320\260\321\202\321\203\321\201              ", nullptr));
        label_5->setText(QCoreApplication::translate("ProjectInfoForm", "\320\224\320\260\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectInfoForm: public Ui_ProjectInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_INFO_FORM_H
