#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "ISort.h"
#include "Swap.h"

template <class T>
class BubbleSort : public ISort<T>
{
public:
    Sequence<T> *Sort(Sequence<T> *seq) override
    {
        bubbleSort(seq);
        return seq;
    }

private:
    void bubbleSort(Sequence<T> *seq)
    {
        int n = seq->GetLength();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (seq->Get(j) > seq->Get(j + 1))
                {
                    swap(seq, j, j + 1);
                }
            }
        }
    }
};

#endif
