#ifndef GRAPH_WIDGET_H
#define GRAPH_WIDGET_H

#include <QWidget>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QToolTip>


#include "project_journal.h"

namespace Ui {
class GraphWidget;
}

class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    ~GraphWidget();

public slots:
    void on_graph_drawing_initiated(ProjectJournal& project_journal);

private:
    Ui::GraphWidget *ui;
};

#endif // GRAPH_WIDGET_H
