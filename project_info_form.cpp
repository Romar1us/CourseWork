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
