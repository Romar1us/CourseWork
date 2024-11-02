#ifndef PROJECTJOURNAL_H
#define PROJECTJOURNAL_H

#include <QVector>
#include "project.h"

class ProjectJournal
{
public:
    ProjectJournal();
    QVector<Project> FilterByName(QString name);
    QVector<Project> FilterByManager(QString manager);

private:
    QVector<Project> projects;
};

#endif // PROJECTJOURNAL_H
