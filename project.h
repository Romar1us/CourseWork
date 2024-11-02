#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <QString>

enum class ProjectStatus
{
    DONE,
    IN_PROGRESS
};

class Project
{
public:
    Project();
    Project(QString _name, QString _manager, int _time, QString _status);
    Project(const Project& other);


    QString GetName() const;
    QString GetDate() const;
    QString GetManager() const;
    int GetTime() const; //mb change
    QString GetStatus() const;

    void SetName(QString _name);
    void SetDate(QString _date);
    void SetManager(QString _manager);
    void SetTime(int _time);
    void SetStatus(QString _status);

private:
    QString date;
    QString name;
    QString manager;
    int time;
    QString status;
};

#endif // PROJECT_H
