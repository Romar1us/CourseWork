#include "sort_form.h"
#include "ui_sort_form.h"

SortForm::SortForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SortForm)
{
    ui->setupUi(this);
    ui->sort_order_cb->addItem("Ascending", true);
    ui->sort_order_cb->addItem("Descending", false);
    ui->time_rb->setChecked(true);
}

SortForm::~SortForm()
{
    delete ui;
}

void SortForm::on_project_sorting_initiated()
{
    this->show();
}

void SortForm::on_sort_pb_clicked()
{
    QString type = ui->time_rb->isChecked() ? "time" : "date";
    emit sorting_options_set(type, ui->sort_order_cb->currentData().toBool());
    this->close();
}

