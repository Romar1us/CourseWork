#include "project_journal.h"

ProjectJournal::ProjectJournal() {}

ProjectJournal::ProjectJournal(QVector<Project> _projects) :
    projects(_projects) {}

ProjectJournal::~ProjectJournal()
{
}

void ProjectJournal::AddProject(const Project& project)
{
    projects.push_back(project);
    qDebug() << projects.size();
}

bool ProjectJournal::DeleteProjectById(const size_t& id)
{
    if(id > Project::count)
    {
        throw;
    }
    for(auto it = projects.begin(); it != projects.end(); ++it)
    {
        if(it->GetId() == id)
        {
            projects.erase(it);
            return true;
        }
    }
    return false;
}

bool ProjectJournal::GetProjectById(const size_t& id, Project& project) const
{
    if(id > projects[0].count)
    {
        return false;
    }
    for(auto& elem : projects)
    {
        if(elem.GetId() == id)
        {
            project = elem;
            return true;
        }
    }
    return false;
}

bool ProjectJournal::UpdateProjectById(const size_t& id, const Project& project)
{
    for(auto& elem : projects)
    {
        if(elem.GetId() == id)
        {
            elem = project;
            return true;
        }
    }
    return false;
}

QStringList ProjectJournal::GetManagers()
{
    QStringList managers;
    for(const auto& elem : projects)
    {
        QString manager = elem.GetManager();
        if(!managers.contains(manager))
        {
            managers.push_back(manager);
        }
    }
    return managers;
}

int ProjectJournal::GetProjectCountByStatus(const QString& status)
{
    int count = 0;
    for(const auto& elem : projects)
    {
        if(elem.GetStatus() == status)
        {
            ++count;
        }
    }
    return count;
}


ProjectJournal ProjectJournal::FilterByName(const ProjectJournal& project_journal, const Filter<QString>& filter)
{
    QVector<Project> result;
    Comparator<QString> comparator;
    for (const auto& project : project_journal.projects)
    {
        if(comparator.compare_map[filter.GetComparisonType()](project.GetName(), filter.GetValue()))
        {
            result.push_back(project);
        }
    }
    return ProjectJournal(result);
}

ProjectJournal ProjectJournal::FilterByManager(const ProjectJournal& project_journal, const Filter<QString>& filter)
{
    QVector<Project> result;
    Comparator<QString> comparator;
    for (const auto& project : project_journal.projects)
    {
        if(comparator.compare_map[filter.GetComparisonType()](project.GetManager(), filter.GetValue()))
        {
            result.append(project);
        }
    }
    return ProjectJournal(result);
}

ProjectJournal ProjectJournal::FilterByTime(const ProjectJournal& project_journal, const Filter<int>& filter)
{
    QVector<Project> result;
    Comparator<int> comparator;
    for(const auto& project : project_journal.projects)
    {
        if(comparator.compare_map[filter.GetComparisonType()](project.GetTime(), filter.GetValue()))
        {
            result.push_back(project);
        }
    }
    return ProjectJournal(result);
}

ProjectJournal ProjectJournal::FilterByStatus(const ProjectJournal& project_journal, const Filter<QString>& filter)
{
    QVector<Project> result;
    Comparator<QString> comparator;
    for(const auto& project : project_journal.projects)
    {
        if(comparator.compare_map[filter.GetComparisonType()](project.GetStatus(), filter.GetValue()))
        {
            result.push_back(project);
        }
    }
    return ProjectJournal(result);
}

ProjectJournal ProjectJournal::FilterByDate(const ProjectJournal& project_journal,
                                            const Filter<QDate>& start_date_filter, const Filter<QDate>& end_date_filter)
{
    QVector<Project> result;
    Comparator<QDate> comparator;
    for(const auto& project : project_journal.projects)
    {
        if(comparator.compare_map[start_date_filter.GetComparisonType()](project.GetDate(), start_date_filter.GetValue())
            && comparator.compare_map[end_date_filter.GetComparisonType()](project.GetDate(), end_date_filter.GetValue()))
        {
            result.push_back(project);
        }
    }
    return ProjectJournal(result);
}

ProjectJournal ProjectJournal::FilterHandler(const ProjectJournal& project_journal, const FilterList& filter_list)
{
    qDebug() << "filter handler launched";
    ProjectJournal result = project_journal;
    if(filter_list.is_name_filter_set)
    {
        result = ProjectJournal::FilterByName(result, filter_list.name_filter);
    }
    if(filter_list.is_manager_filter_set)
    {
        result = ProjectJournal::FilterByManager(result, filter_list.manager_filter);
    }
    if(filter_list.is_time_filter_set)
    {
        result = ProjectJournal::FilterByTime(result, filter_list.time_filter);
    }
    if(filter_list.is_status_filter_set)
    {
        result = ProjectJournal::FilterByStatus(result, filter_list.status_filter);
    }
    if(filter_list.is_date_filter_set)
    {
       result = ProjectJournal::FilterByDate(project_journal, filter_list.start_date_filter, filter_list.end_date_filter);
    }
    return result;
}

ProjectJournal ProjectJournal::SortByDate(const ProjectJournal& project_journal, const bool& is_ascending)
{
    ProjectJournal result = project_journal;
    std::sort(result.projects.begin(), result.projects.end(),
        [is_ascending](const Project& first, const Project& second)
        {
        if(first.GetDate() < second.GetDate())
        {
            return is_ascending;
        }
        return !is_ascending;
    });

    return result;
}

ProjectJournal ProjectJournal::SortByTime(const ProjectJournal& project_journal, const bool& is_ascending)
{
    ProjectJournal result = project_journal;
    std::sort(result.projects.begin(), result.projects.end(),
              [is_ascending](const Project& first, const Project& second)
              {
                  if(first.GetTime() < second.GetTime())
                  {
                      return is_ascending;
                  }
                  return !is_ascending;
              });

    return result;
}

ProjectJournal ProjectJournal::SortingHandler(const ProjectJournal& project_journal, const QString& type, bool ascending)
{
    ProjectJournal result;
    if(type == "time")
    {
        result = ProjectJournal::SortByTime(project_journal, ascending);
    }
    if(type == "date")
    {
        result = ProjectJournal::SortByDate(project_journal, ascending);
    }
    return result;
}

int ProjectJournal::GetSize() const
{
    return projects.size();
}

QString ProjectJournal::GetProjectAmountView() const
{
    int in_progress_number = ProjectJournal::FilterByStatus(*this, Filter(QString("В процесі"), ComparisonType::EQUALS)).GetSize();
    int done_number = ProjectJournal::FilterByStatus(*this, Filter(QString("Завершено"), ComparisonType::EQUALS)).GetSize();
    return QString("Всього %1 проектів. В процесі розробки: %2. Завершено: %3")
        .arg(QString::number(GetSize()))
        .arg(QString::number(in_progress_number))
        .arg(QString::number(done_number));
}


std::istream& operator>>(std::istream& is, ProjectJournal& project_journal)
{
    std::string line;
    qDebug() << "hello";
    while(getline(is, line))
    {
        qDebug() << "hello";
        qDebug() << line;
        std::stringstream ss(line);
        Project project;
        try
        {
            ss >> project;
        }
        catch(BasicException& ex)
        {
            throw ex;
        }

        project_journal.AddProject(project);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const ProjectJournal& project_journal)
{
    for(const auto& elem : project_journal.projects)
    {
        os << elem;
    }
    return os;
}
