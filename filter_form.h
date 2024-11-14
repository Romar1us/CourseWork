#ifndef FILTER_FORM_H
#define FILTER_FORM_H

#include <QWidget>
#include <map>
#include <variant>
#include <QString>
#include <QDate>
#include <QCloseEvent>
#include "filter_list.h"
#include "filter.h"
#include "comparator.h"

namespace Ui {
class FilterForm;
}

class FilterForm : public QWidget
{
    Q_OBJECT

public:
    explicit FilterForm(QWidget *parent = nullptr);
    ~FilterForm();
    void ClearFields();


public slots:
    void on_project_journal_filter_initiated(FilterList filter_list);

private slots:
    void on_filter_pb_clicked();

    void on_clear_filters_pb_clicked();

signals:
    void filters_set(FilterList filter_list);

protected:
    void closeEvent(QCloseEvent* event) override;


private:
    FilterList filter_list;
    Ui::FilterForm *ui;
};

#endif // FILTER_FORM_H
