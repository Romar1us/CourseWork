#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>

#include <QString>
#include <QDate>

#include <QDebug>

#include "exceptions.h"

enum class ProjectStatus
{
    DONE,
    IN_PROGRESS
};


class Project
{
public:
    Project();
    Project(const QString& _name, const QString& _manager, const int& _time, const QString& _status, const QDate& _date);
    Project(const Project& other);


    QString GetName() const;
    QDate GetDate() const;
    QString GetManager() const;
    int GetTime() const; //mb change
    QString GetStatus() const;
    int GetId() const;

    void SetName(const QString& _name);
    void SetDate(const QDate& _date);
    void SetManager(const QString& _manager);
    void SetTime(const int& _time);
    void SetStatus(const QString& _status);


    QString ToString() const;

    static int count;

    Project& operator=(const Project& other);
    bool operator==(const Project& other) const;
    friend std::istream& operator>>(std::istream& is, Project& project);
    friend std::ostream& operator<<(std::ostream& os, const Project& project);


private:
    QDate date;
    QString name;
    QString manager;
    int time;
    QString status;
    int id;
};

#endif // PROJECT_H
