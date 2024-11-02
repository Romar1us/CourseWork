#ifndef PROJECT_INFO_FORM_H
#define PROJECT_INFO_FORM_H

#include <QWidget>
#include <QMessageBox>

#include "project.h"

namespace Ui {
class ProjectInfoForm;
}

class ProjectInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectInfoForm(QWidget *parent = nullptr);
    ~ProjectInfoForm();

signals:
    void project_created(Project* project);

private slots:
    void on_add_project_pb_clicked();

private:
    Ui::ProjectInfoForm *ui;
};

#endif // PROJECT_INFO_FORM_H
