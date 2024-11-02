#ifndef PROJECT_INFO_FORM_H
#define PROJECT_INFO_FORM_H

#include <QWidget>

namespace Ui {
class ProjectInfoForm;
}

class ProjectInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectInfoForm(QWidget *parent = nullptr);
    ~ProjectInfoForm();

private:
    Ui::ProjectInfoForm *ui;
};

#endif // PROJECT_INFO_FORM_H
