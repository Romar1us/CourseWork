#ifndef PROJECT_INFO_FORM_H
#define PROJECT_INFO_FORM_H

#include <QWidget>
#include <QMessageBox>
#include <QCloseEvent>

#include "project.h"

enum class InfoMode
{
    CREATION,
    EDITION
};

namespace Ui {
class ProjectInfoForm;
}

class ProjectInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectInfoForm(QWidget *parent = nullptr);
    ~ProjectInfoForm();

    void ClearFields();
    bool IsFieldsEmpty();

signals:
    void project_created(Project project);
    void project_edited(Project project, int _project_id);

public slots:
    void on_project_creation_initiated();
    void on_project_edition_initiated(Project project);

private slots:
    void on_action_pb_clicked();

protected:
    void closeEvent(QCloseEvent* event) override;
private:
    InfoMode mode;
    int project_id = -1;
    Ui::ProjectInfoForm *ui;
};

#endif // PROJECT_INFO_FORM_H
