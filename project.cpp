#include "project.h"

int Project::count = 0;

Project::Project() {}

Project::Project(const QString& _name, const QString& _manager, const int& _time, const QString& _status, const QDate& _date) :
    date(_date), name(_name), manager(_manager), time(_time), status(_status), id(count)
{
    ++count;
}

Project::Project(const Project& other)
{
    name = other.name;
    manager = other.manager;
    time = other.time;
    status = other.status;
    date = other.date;
    id = other.id;
}

QString Project::GetName() const
{
    return name;
}

QDate Project::GetDate() const
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

int Project::GetId() const
{
    return id;
}

void Project::SetName(const QString& _name)
{
    name = _name;
}

void Project::SetDate(const QDate& _date)
{
    date = (_date);
}

void Project::SetManager(const QString& _manager)
{
    manager = _manager;
}
void Project::SetTime(const int& _time)
{
    time = _time;
}
void Project::SetStatus(const QString& _status)
{
    status = _status;
}

QString Project::ToString() const
{
    return QString("Запис [%1]\nНазва проекту: %2\nВідповідальна особа: %3\n"
                   "Запланований час: %4\nСтатус: %5\n")
        .arg(date.toString("dd.MM.yyyy")) .arg(name) .arg(manager) .arg(QString::number(time)) .arg(status);
}

Project& Project::operator=(const Project& other)
{
    name = other.name;
    manager = other.manager;
    time = other.time;
    date = other.date;
    status = other.status;
    id = other.id;
    return *this;
}

bool Project::operator==(const Project& other) const
{
    if(name == other.name && manager == other.manager
        && time == other.time && status == other.status && date == other.date)
    {
        return true;
    }
    return false;
}

std::istream& operator>>(std::istream& is, Project& project)
{
    std::string text;
    std::getline(is, text);
    QString my_text = QString::fromStdString(text);
    QStringList my_list = my_text.split(" | ");
    if(my_list.size() < 5)
    {
        throw InvalidSaveFileException();
    }
    project.SetDate(QDate::fromString(my_list[0], "dd.MM.yyyy"));
    project.SetName(my_list[1]);
    project.SetManager(my_list[2]);
    project.SetTime(my_list[3].toInt());
    project.SetStatus(my_list[4]);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Project& project)
{
    os << project.date.toString("dd.MM.yyyy").toStdString() << " | " << project.name.toStdString()
       << " | " << project.manager.toStdString() << " | " << project.time << " | "
       << project.status.toStdString() << "\n";

    return os;
}
