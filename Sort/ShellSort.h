#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "Isort.h"

template <typename T>
class ShellSorter : public ISort<T>
{
public:
    void Sort(Sequence<T> *seq) override
    {
        int n = seq->GetLength();

        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                T temp = seq->Get(i);
                int j;

                for (j = i; j >= gap && seq->Get(j - gap) > temp; j -= gap)
                {
                    seq->InsertAt(seq->Get(j - gap), j);
                }
                seq->InsertAt(temp, j);
            }
        }
    }
};

#endif