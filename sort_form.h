#ifndef SORT_FORM_H
#define SORT_FORM_H

#include <QWidget>

namespace Ui {
class SortForm;
}

class SortForm : public QWidget
{
    Q_OBJECT

public:
    explicit SortForm(QWidget *parent = nullptr);
    ~SortForm();

private slots:
    void on_sort_pb_clicked();

public slots:
    void on_project_sorting_initiated();

signals:
    void sorting_options_set(const QString& type, bool ascending);

private:
    Ui::SortForm *ui;
};

#endif // SORT_FORM_H
