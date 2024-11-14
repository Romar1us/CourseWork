#include "graph_widget.h"
#include "ui_graph_widget.h"


GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GraphWidget)
{
    ui->setupUi(this);
}

GraphWidget::~GraphWidget()
{
    delete ui;
}


void GraphWidget::on_graph_drawing_initiated(ProjectJournal& project_journal)
{
    QBarSet* new_project_set = new QBarSet("Новий");
    new_project_set->setColor(QColor(89, 138, 222));
    QBarSet* in_progres_project_set = new QBarSet("В процесі");
    in_progres_project_set->setColor(QColor(255, 132, 0));
    QBarSet* done_project_set = new QBarSet("Завершено");
    done_project_set->setColor(QColor(0, 255, 0));

    connect(new_project_set, &QBarSet::hovered, this, [=](bool status, int index) {
        if (status) {
            QToolTip::showText(QCursor::pos(), QString("Новий: %1").arg(new_project_set->at(index)));
        }
    });

    connect(in_progres_project_set, &QBarSet::hovered, this, [=](bool status, int index) {
        if (status) {
            QToolTip::showText(QCursor::pos(), QString("В процесі: %1").arg(in_progres_project_set->at(index)));
        }
    });

    connect(done_project_set, &QBarSet::hovered, this, [=](bool status, int index) {
        if (status) {
            QToolTip::showText(QCursor::pos(), QString("Завершено: %1").arg(done_project_set->at(index)));
        }
    });
    for(const auto& elem : project_journal.GetManagers())
    {
        ProjectJournal temp_journal = ProjectJournal::FilterByManager(project_journal,
                                                                      Filter<QString>(elem, ComparisonType::EQUALS));
        *new_project_set << temp_journal.GetProjectCountByStatus("Новий");
        *in_progres_project_set << temp_journal.GetProjectCountByStatus("В процесі");
        *done_project_set << temp_journal.GetProjectCountByStatus("Завершено");

    }
    auto series = new QStackedBarSeries;
    series->append(new_project_set);
    series->append(in_progres_project_set);
    series->append(done_project_set);
    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Simple Stacked Bar Chart");
    chart->setBackgroundBrush(QColor(0, 0, 0));
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = project_journal.GetManagers();
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    axisY->setTickInterval(project_journal.GetSize() / 10);           // Інтервал між мітками - ціле число
    axisY->setLabelFormat("%.0f");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(this);
    chartView->setGeometry(10, 10, 780, 580); // x, y, width, height

    this->resize(800, 600);
    this->show();


}
