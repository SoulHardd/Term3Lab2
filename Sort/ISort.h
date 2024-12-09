#ifndef ISORT_H
#define ISORT_H

#include "../Sequence/Sequence.h"

template <class T>
class ISorter
{
public:
    virtual Sequence<T> *Sort(Sequence<T> *seq) = 0;
    ~ISorter() {};
};

#endif