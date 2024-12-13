#ifndef SWAP_H
#define SWAP_H

#include "../Sequence/Sequence.h"

template <class T>
void swap(Sequence<T> *seq, int i, int j)
{
    if (i != j)
    {
        T temp = seq->Get(i);
        seq->InsertAt(seq->Get(j), i);
        seq->InsertAt(temp, j);
    }
}

#endif