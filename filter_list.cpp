#include "filter_list.h"

FilterList::FilterList() {}

void FilterList::ClearFilters()
{
    is_name_filter_set = false;
    is_manager_filter_set = false;
    is_date_filter_set = false;
    is_time_filter_set = false;
    is_status_filter_set = false;
}

bool FilterList::IsSet()
{
    return is_name_filter_set || is_manager_filter_set || is_date_filter_set ||
           is_time_filter_set || is_status_filter_set;
}
