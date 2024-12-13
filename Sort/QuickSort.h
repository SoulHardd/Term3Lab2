#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Isort.h"

template <class T>
class QuickSort : public ISort<T>
{
public:
    Sequence<T> *Sort(Sequence<T> *seq) override
    {
        quickSort(seq, 0, seq->GetLength() - 1);
        return seq;
    }

private:
    void quickSort(Sequence<T> *seq, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(seq, low, high);
            quickSort(seq, low, pi - 1);
            quickSort(seq, pi + 1, high);
        }
    }

    void swap(Sequence<T> *seq, int i, int j)
    {
        if (i != j)
        {
            T temp = seq->Get(i);
            seq->InsertAt(seq->Get(j), i);
            seq->InsertAt(temp, j);
        }
    }

    int partition(Sequence<T> *seq, int low, int high)
    {
        T pivot = seq->Get(high);
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (seq->Get(j) < pivot)
            {
                i++;
                swap(seq, i, j);
            }
        }
        swap(seq, i + 1, high);
        return i + 1;
    }
};

#endif
