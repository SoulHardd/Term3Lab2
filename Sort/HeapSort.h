#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "Isort.h"

template <typename T>
class HeapSorter : public ISort<T>
{
public:
    void Sort(Sequence<T> *seq) override
    {
        int n = seq->GetLength();

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(seq, n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            swap(seq, 0, i);
            heapify(seq, i, 0);
        }
    }

private:
    void heapify(Sequence<T> *seq, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && seq->Get(left) > seq->Get(largest))
        {
            largest = left;
        }

        if (right < n && seq->Get(right) > seq->Get(largest))
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(seq, i, largest);

            heapify(seq, n, largest);
        }
    }

    void swap(Sequence<T> *seq, int i, int j)
    {
        T temp = seq->Get(i);
        seq->InsertAt(seq->Get(j), i);
        seq->InsertAt(temp, j);
    }
};

#endif