#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this, &MainWindow::project_creation_initiated,
                     &project_info_form, &ProjectInfoForm::on_project_creation_initiated);
    QObject::connect(&project_info_form, &ProjectInfoForm::project_created,
                     this, &MainWindow::on_project_created);
    QObject::connect(this, &MainWindow::project_edition_initiated,
                     &project_info_form, &ProjectInfoForm::on_project_edition_initiated);
    QObject::connect(&project_info_form, &ProjectInfoForm::project_edited,
                     this, &MainWindow::on_project_edited);
    QObject::connect(this, &MainWindow::project_journal_filter_initiated,
                     &filter_form, &FilterForm::on_project_journal_filter_initiated);
    QObject::connect(&filter_form, &FilterForm::filters_set,
                     this, &MainWindow::on_filters_set);
    QObject::connect(ui->read_from_file_action, &QAction::triggered,
                     this, &MainWindow::on_read_from_file);
    QObject::connect(ui->write_to_file_action, &QAction::triggered,
                     this, &MainWindow::on_write_to_file);
    QObject::connect(this, &MainWindow::project_sorting_initiated,
                     &sort_form, &SortForm::on_project_sorting_initiated);
    QObject::connect(&sort_form, &SortForm::sorting_options_set,
                     this, &MainWindow::on_sorting_options_set);
    QObject::connect(this, &MainWindow::graph_drawing_initiated,
                     &graph_widget, &GraphWidget::on_graph_drawing_initiated);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateList()
{
    ui->projects_list_widget->clear();
    project_journal_view = ProjectJournal::FilterHandler(base_project_journal, filter_list);
    for (const auto& elem : project_journal_view.projects)
    {
        QListWidgetItem* item = new QListWidgetItem(elem.ToString());
        item->setData(Qt::UserRole, elem.GetId());
        ui->projects_list_widget->addItem(item);
    }
}

void MainWindow::UpdateProjectAmountView()
{
    ui->project_amount_view_le->setText(project_journal_view.GetProjectAmountView());
}

void MainWindow::on_project_created(Project project)
{
    base_project_journal.AddProject(project);
    UpdateList();
    UpdateProjectAmountView();
}

void MainWindow::on_project_edited(Project project, int project_id)
{
    base_project_journal.UpdateProjectById(project_id, project);
    UpdateList();
    qDebug() << project.GetId();
}

void MainWindow::on_filters_set(FilterList _filter_list)
{
    filter_list = _filter_list;
    project_journal_view = ProjectJournal::FilterHandler(base_project_journal, _filter_list);
    UpdateList();
    UpdateProjectAmountView();
}

void MainWindow::on_add_project_pb_clicked()
{
    emit project_creation_initiated();
}

void MainWindow::on_delete_project_pb_clicked()
{
    QListWidgetItem* item = ui->projects_list_widget->currentItem();
    if(!item)
    {
        QMessageBox::information(this, "Помилка", "Спершу виберіть проект");
        return;
    }
    int id = item->data(Qt::UserRole).toInt();
    base_project_journal.DeleteProjectById(id);
    UpdateProjectAmountView();
    delete item;
}

void MainWindow::on_alter_project_pb_clicked()
{
    QListWidgetItem* item = ui->projects_list_widget->currentItem();
    if(!item)
    {
        QMessageBox::information(this, "Помилка", "Спершу виберіть проект");
        return;
    }
    int id = item->data(Qt::UserRole).toInt();
    Project project;
    project_journal_view.GetProjectById(id, project);
    qDebug() << id;
    emit project_edition_initiated(project);
}

void MainWindow::on_filter_projects_pb_clicked()
{
    emit project_journal_filter_initiated(filter_list);
}

void MainWindow::on_clear_filters_pb_clicked()
{
    filter_list.ClearFilters();
    project_journal_view = base_project_journal;
    UpdateList();
    UpdateProjectAmountView();
}

void MainWindow::on_read_from_file()
{
    QString path = QFileDialog::getOpenFileName(this, "Open file", "C:/Users/Roman/Documents", "Text Files (*.txt);;All Files (*)");
    std::fstream file(path.toStdString(), std::ios::in | std::ios::app);
    if(file.is_open())
    {
        qDebug() << "file opened";
    }
    try
    {
        file >> base_project_journal;
    }
    catch(BasicException& ex)
    {
        QMessageBox::information(this, "error", ex.what());
    }

    file.close();
    UpdateList();
    UpdateProjectAmountView();
}

void MainWindow::on_write_to_file()
{
    QString path = QFileDialog::getSaveFileName(this, ("Save file"), "C:/Users/Roman/Documents", ("Text Files (*.txt);;All Files (*)"));
    std::fstream file(path.toStdString(), std::ios::out | std::ios::app);
    file << project_journal_view;
    file.close();

}


void MainWindow::on_sort_projects_pb_clicked()
{
    emit project_sorting_initiated();
}

void MainWindow::on_sorting_options_set(const QString& type, bool ascending)
{
    project_journal_view = ProjectJournal::SortingHandler(project_journal_view, type, ascending);
    UpdateList();
}


void MainWindow::on_graph_pb_clicked()
{
    emit graph_drawing_initiated(project_journal_view);
}

