#ifndef FILTER_LIST_H
#define FILTER_LIST_H

#include <QString>
#include <QDate>
#include "filter.h"

class FilterList
{
public:
    FilterList();

    Filter<QString> name_filter;
    bool is_name_filter_set = false;

    Filter<QString> manager_filter;
    bool is_manager_filter_set = false;

    Filter<int> time_filter;
    bool is_time_filter_set = false;

    Filter<QString> status_filter;
    bool is_status_filter_set = false;

    Filter<QDate> start_date_filter;
    Filter<QDate> end_date_filter;
    bool is_date_filter_set = false;

    void ClearFilters();
    bool IsSet();


};

#endif // FILTER_LIST_H
