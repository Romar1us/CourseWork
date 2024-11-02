#include "project_info_form.h"
#include "ui_project_info_form.h"

ProjectInfoForm::ProjectInfoForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectInfoForm)
{
    ui->setupUi(this);
}

ProjectInfoForm::~ProjectInfoForm()
{
    delete ui;
}

void ProjectInfoForm::on_add_project_pb_clicked()
{
    if(ui->project_name_le->text().isEmpty() ||
        ui->project_manager_le->text().isEmpty() ||
        ui->time_amount_le->text().isEmpty() ||
        ui->project_status_le->text().isEmpty())
    {
        QMessageBox::information(this, "Помилка", "Потрібно ввести всі необхідні дані");
        return;
    }

    QString name = ui->project_name_le->text();
    QString manager = ui->project_manager_le->text();
    int time = ui->time_amount_le->text().toInt();
    QString status = ui->project_status_le->text();

    Project* project = new Project(name, manager, time, status);
    emit project_created(project);
}

