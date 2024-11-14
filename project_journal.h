#ifndef PROJECTJOURNAL_H
#define PROJECTJOURNAL_H

#include <QVector>
#include <iostream>
#include <functional>
#include <sstream>
#include <algorithm>
#include <QSet>

#include "filter.h"
#include "filter_list.h"
#include "project.h"
#include "comparator.h"

class ProjectJournal
{
public:
    ProjectJournal();
    ProjectJournal(QVector<Project> _projects);
    ~ProjectJournal();

    void AddProject(const Project& project);
    bool DeleteProjectById(const size_t& id);
    bool GetProjectById(const size_t& id, Project& project) const;
    bool UpdateProjectById(const size_t& id, const Project& project);
    int GetSize() const;
    QStringList GetManagers();
    int GetProjectCountByStatus(const QString& status);
    static ProjectJournal FilterByName(const ProjectJournal& project_journal, const Filter<QString>& filter);
    static ProjectJournal FilterByManager(const ProjectJournal& project_journal, const Filter<QString>& filter);
    static ProjectJournal FilterByTime(const ProjectJournal& project_journal, const Filter<int>& filter);
    static ProjectJournal FilterByStatus(const ProjectJournal& project_journal, const Filter<QString>& filter);
    static ProjectJournal FilterByDate(const ProjectJournal& project_journal,
                                       const Filter<QDate>& start_date_filter, const Filter<QDate>& end_date_filter);
    static ProjectJournal FilterHandler(const ProjectJournal& project_journal, const FilterList& filter_list);
    static ProjectJournal SortByDate(const ProjectJournal& project_journal, const bool& is_ascending = true);
    static ProjectJournal SortByTime(const ProjectJournal& project_journal, const bool& is_ascending = true);
    static ProjectJournal SortingHandler(const ProjectJournal& project_journal, const QString& type, bool ascending);
    QString GetProjectAmountView() const;

    friend std::istream& operator>>(std::istream& is, ProjectJournal& project_journal);
    friend std::ostream& operator<<(std::ostream& os, const ProjectJournal& project_journal);

    QVector<Project> projects;
private:
};

#endif // PROJECTJOURNAL_H
