#ifndef ISORT_H
#define ISORT_H

#include "../Sequence/Sequence.h"

template <class T>
class ISort
{
public:
    virtual Sequence<T> *Sort(Sequence<T> *seq) = 0;
    ~ISort() {};
};

#endif