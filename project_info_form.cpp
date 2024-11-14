#include "project_info_form.h"
#include "ui_project_info_form.h"

ProjectInfoForm::ProjectInfoForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectInfoForm)
{
    ui->setupUi(this);
    qDebug() << "hello";
}

ProjectInfoForm::~ProjectInfoForm()
{
    delete ui;
}

void ProjectInfoForm::closeEvent(QCloseEvent* event)
{
    ClearFields();
    event->accept();
}

void ProjectInfoForm::ClearFields()
{
    ui->project_name_le->clear();
    ui->project_manager_le->clear();
    ui->time_amount_le->clear();
    ui->project_status_le->clear();
};

bool ProjectInfoForm::IsFieldsEmpty()
{
    if(ui->project_name_le->text().isEmpty() ||
    ui->project_manager_le->text().isEmpty() ||
    ui->time_amount_le->text().isEmpty() ||
    ui->project_status_le->text().isEmpty())
    {
        return true;
    }
    return false;
}

void ProjectInfoForm::on_project_creation_initiated()
{
    ui->action_pb->setText("Створити");
    ui->date_de->setDate(QDate::currentDate());
    mode = InfoMode::CREATION;
    this->show();
}

void ProjectInfoForm::on_project_edition_initiated(Project project)
{
    ui->project_name_le->setText(project.GetName());
    ui->project_manager_le->setText(project.GetManager());
    ui->time_amount_le->setText(QString::number(project.GetTime()));
    ui->project_status_le->setText(project.GetStatus());
    ui->action_pb->setText("Редагувати");
    mode = InfoMode::EDITION;
    project_id = project.GetId();
    this->show();
}

void ProjectInfoForm::on_action_pb_clicked()
{
    if(IsFieldsEmpty())
    {
        QMessageBox::critical(this, "Помилка", "Потрібно ввести всі необхідні дані");
        return;
    }
    bool ok;
    QString name = ui->project_name_le->text();
    QString manager = ui->project_manager_le->text();
    QString status = ui->project_status_le->text();
    QDate date = ui->date_de->date();

    int time = ui->time_amount_le->text().toInt(&ok);
    if(ok == false)
    {
        QMessageBox::critical(this, "Помилка", "Введено неправильне значення");
        return;
    }


    Project project(name, manager, time, status, date);
    if(mode == InfoMode::CREATION)
    {
        emit project_created(project);
    }
    if(mode == InfoMode::EDITION)
    {
        emit project_edited(project, project_id);
    }
    this->close();

}


