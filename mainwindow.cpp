#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&project_info_form, &ProjectInfoForm::project_created, this, &MainWindow::on_project_info_filled);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_project_pb_clicked()
{
    project_info_form.show();
}

void MainWindow::on_project_info_filled(Project* project)
{
    qDebug() << "hello";
}



void MainWindow::on_delete_project_pb_clicked()
{

}

