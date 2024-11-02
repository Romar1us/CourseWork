#include "project.h"

Project::Project() {}

Project::Project(QString _name, QString _manager, int _time, QString _status) :
    name(_name), manager(_manager), time(_time), status(_status) {}

Project::Project(const Project& other)
{
    name = other.name;
    manager = other.manager;
    time = other.time;
    status = other.status;
}

QString Project::GetName() const
{
    return name;
}
QString Project::GetDate() const
{
    return date;
}

QString Project::GetManager() const
{
    return manager;
}

int Project::GetTime() const
{
    return time;
}

QString Project::GetStatus() const
{
    return status;
}

void Project::SetName(QString _name)
{
    name = _name;
}

void Project::SetDate(QString _date)
{
    date = (_date);
}

void Project::SetManager(QString _manager)
{
    manager = _manager;
}
void Project::SetTime(int _time)
{
    time = _time;
}
void Project::SetStatus(QString _status)
{
    status = _status;
}
