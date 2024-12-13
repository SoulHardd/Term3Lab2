#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "ISort.h"

template <class T>
class InsertionSort : public ISort<T>
{
public:
    Sequence<T> *Sort(Sequence<T> *seq) override
    {
        insertionSort(seq);
        return seq;
    }

private:
    void insertionSort(Sequence<T> *seq)
    {
        int n = seq->GetLength();
        for (int i = 1; i < n; i++)
        {
            T key = seq->Get(i);
            int j = i - 1;

            while (j >= 0 && seq->Get(j) > key)
            {
                seq->InsertAt(seq->Get(j), j + 1);
                j--;
            }
            seq->InsertAt(key, j + 1);
        }
    }
};

#endif
