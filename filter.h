#ifndef FILTER_H
#define FILTER_H

#include <comparator.h>

template<typename T>
class Filter
{
public:
    Filter();
    Filter(const T& _value, const ComparisonType& _comparison_type);

    T GetValue() const;
    ComparisonType GetComparisonType() const;

private:
    T value;
    ComparisonType comparison_type;
};

template<typename T>
inline Filter<T>::Filter() {}

template<typename T>
inline Filter<T>::Filter(const T& _value, const ComparisonType& _comparison_type)
    : value(_value), comparison_type(_comparison_type) {}

template<typename T>
inline T Filter<T>::GetValue() const
{
    return value;
}

template<typename T>
inline ComparisonType Filter<T>::GetComparisonType() const
{
    return comparison_type;
}

#endif // FILTER_H
