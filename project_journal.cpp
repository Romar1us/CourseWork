#include "project_journal.h"

ProjectJournal::ProjectJournal() {}

QVector<Project> ProjectJournal::FilterByName(QString name)
{
    QVector<Project> result;
    for (const auto& project : projects)
    {
        if(project.GetName() == name)
        {
            result.append(project);
        }
    }
    return result;
}

QVector<Project> ProjectJournal::FilterByManager(QString manager)
{
    QVector<Project> result;
    for (const auto& project : projects)
    {
        if(project.GetManager() == manager)
        {
            result.append(project);
        }
    }
    return result;
}

