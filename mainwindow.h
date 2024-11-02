#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include "project_info_form.h"
#include "project_journal.h"
#include "project.h"

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

public slots:
    void on_project_info_filled(Project* project);
private slots:
    void on_add_project_pb_clicked();

    void on_delete_project_pb_clicked();

private:
    Ui::MainWindow *ui;
    ProjectJournal project_journal;
    ProjectInfoForm project_info_form;

};
#endif // MAINWINDOW_H
