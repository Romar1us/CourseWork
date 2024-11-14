#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QObject>
#include <QFileDialog>
#include <fstream>

#include "filter_list.h"
#include "project_info_form.h"
#include "filter_form.h"
#include "project_journal.h"
#include "project.h"
#include "sort_form.h"
#include "graph_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void UpdateList();
    void UpdateProjectAmountView();

public slots:
    void on_project_created(Project project);
    void on_project_edited(Project project, int project_id);
    void on_filters_set(FilterList filter_list);
    void on_sorting_options_set(const QString& type, bool ascending);

private slots:
    void on_add_project_pb_clicked();
    void on_delete_project_pb_clicked();
    void on_alter_project_pb_clicked();
    void on_filter_projects_pb_clicked();
    void on_clear_filters_pb_clicked();
    void on_read_from_file();
    void on_write_to_file();
    void on_sort_projects_pb_clicked();

    void on_graph_pb_clicked();

signals:
    void project_creation_initiated();
    void project_edition_initiated(Project project);
    void project_journal_filter_initiated(FilterList filter_list);
    void project_sorting_initiated();
    void graph_drawing_initiated(ProjectJournal& project_journal);

private:
    Ui::MainWindow *ui;
    ProjectJournal base_project_journal;
    ProjectJournal project_journal_view;
    ProjectInfoForm project_info_form;
    FilterForm filter_form;
    FilterList filter_list;
    GraphWidget graph_widget;
    SortForm sort_form;


};
#endif // MAINWINDOW_H
