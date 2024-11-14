#include "filter_form.h"
#include "ui_filter_form.h"

FilterForm::FilterForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FilterForm)
{
    ui->setupUi(this);
    ui->name_filter_type_comboBox->addItem("Дорівнює", QVariant(static_cast<int>(ComparisonType::EQUALS)));
    ui->name_filter_type_comboBox->addItem("Не дорівнює", QVariant(static_cast<int>(ComparisonType::NOTEQUALS)));
    ui->manager_filter_type_comboBox->addItem("Дорівнює", QVariant(static_cast<int>(ComparisonType::EQUALS)));
    ui->manager_filter_type_comboBox->addItem("Не дорівнює", QVariant(static_cast<int>(ComparisonType::NOTEQUALS)));
    ui->time_filter_type_comboBox->addItem("Дорівнює", QVariant(static_cast<int>(ComparisonType::EQUALS)));
    ui->time_filter_type_comboBox->addItem("Не дорівнює", QVariant(static_cast<int>(ComparisonType::NOTEQUALS)));
    ui->time_filter_type_comboBox->addItem("Більше ніж", QVariant(static_cast<int>(ComparisonType::GREATER)));
    ui->time_filter_type_comboBox->addItem("Менше ніж", QVariant(static_cast<int>(ComparisonType::LESS)));
    ui->status_filter_type_comboBox->addItem("Дорівнює", QVariant(static_cast<int>(ComparisonType::EQUALS)));
    ui->status_filter_type_comboBox->addItem("Не дорівнює", QVariant(static_cast<int>(ComparisonType::NOTEQUALS)));
}

FilterForm::~FilterForm()
{
    delete ui;
}

void FilterForm::ClearFields()
{
    ui->project_name_checkBox->setChecked(false);
    ui->manager_checkBox->setChecked(false);
    ui->time_checkBox->setChecked(false);
    ui->date_checkBox->setChecked(false);
    ui->status_checkBox->setChecked(false);
    ui->name_value_le->clear();
    ui->manager_value_le->clear();
    ui->time_value_le->clear();
    ui->start_date->clear();
    ui->status_value_le->clear();
}

void FilterForm::closeEvent(QCloseEvent* event)
{
    ClearFields();
    event->accept();
}

void FilterForm::on_project_journal_filter_initiated(FilterList filter_list)
{
    if(filter_list.is_name_filter_set)
    {
        ui->project_name_checkBox->setChecked(true);
        ui->name_value_le->setText(filter_list.name_filter.GetValue());
    }
    if(filter_list.is_manager_filter_set)
    {
        ui->manager_checkBox->setChecked(filter_list.is_manager_filter_set);
        ui->manager_value_le->setText(filter_list.manager_filter.GetValue());
    }
    if(filter_list.is_time_filter_set)
    {
        ui->time_checkBox->setChecked(filter_list.is_time_filter_set);
        ui->name_value_le->setText(QString::number(filter_list.time_filter.GetValue()));
    }
    if(filter_list.is_date_filter_set)
    {
        ui->date_checkBox->setChecked(filter_list.is_date_filter_set);
        ui->start_date->setDate(filter_list.start_date_filter.GetValue());
        ui->end_date->setDate(filter_list.end_date_filter.GetValue());
    }
    else
    {
        ui->start_date->setDate(QDate::currentDate());
    }
    if(filter_list.is_status_filter_set)
    {
        ui->status_checkBox->setChecked(filter_list.is_status_filter_set);
        ui->status_value_le->setText(filter_list.status_filter.GetValue());
    }

    ui->clear_filters_pb->setEnabled(filter_list.IsSet());


    this->show();
}

void FilterForm::on_filter_pb_clicked()
{
    filter_list.is_name_filter_set = ui->project_name_checkBox->isChecked();
    filter_list.is_manager_filter_set = ui->manager_checkBox->isChecked();
    filter_list.is_time_filter_set = ui->time_checkBox->isChecked();
    filter_list.is_status_filter_set = ui->status_checkBox->isChecked();
    filter_list.is_date_filter_set = ui->date_checkBox->isChecked();
    if(filter_list.is_name_filter_set)
    {
        ComparisonType type = static_cast<ComparisonType>(ui->name_filter_type_comboBox->currentData().toInt());
        Filter<QString> filter(ui->name_value_le->text(), type);

        filter_list.name_filter = filter;
    }
    if(filter_list.is_manager_filter_set)
    {
        ComparisonType type = static_cast<ComparisonType>(ui->manager_filter_type_comboBox->currentData().toInt());
        Filter<QString> filter(ui->manager_value_le->text(), type);
        filter_list.manager_filter = filter;
    }
    if(filter_list.is_time_filter_set)
    {
        ComparisonType type = static_cast<ComparisonType>(ui->time_filter_type_comboBox->currentData().toInt());
        Filter<int> filter(ui->time_value_le->text().toInt(), type);
        filter_list.time_filter = filter;
    }
    if(filter_list.is_status_filter_set)
    {
        ComparisonType type = static_cast<ComparisonType>(ui->status_filter_type_comboBox->currentData().toInt());
        Filter<QString> filter(ui->status_value_le->text(), type);
        filter_list.status_filter = filter;
    }
    if(filter_list.is_date_filter_set)
    {
        Filter<QDate> start_date_filter (ui->start_date->date(), ComparisonType::GREATER);
        filter_list.start_date_filter = start_date_filter;
        Filter<QDate> end_date_filter (ui->end_date->date(), ComparisonType::LESS);
        filter_list.end_date_filter = end_date_filter;
    }

    emit filters_set(filter_list);
    this->close();
}


void FilterForm::on_clear_filters_pb_clicked()
{
    filter_list.ClearFilters();
    ClearFields();
    emit filters_set(filter_list);

}

