#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Isort.h"

template <class T>
class MergeSort : public ISort<T>
{
public:
    Sequence<T> *Sort(Sequence<T> *seq) override
    {
        if (seq->GetLength() <= 1)
            return seq;

        mergeSort(seq, 0, seq->GetLength() - 1);
        return seq;
    }

private:
    void mergeSort(Sequence<T> *seq, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(seq, left, mid);
            mergeSort(seq, mid + 1, right);

            merge(seq, left, mid, right);
        }
    }

    void merge(Sequence<T> *seq, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        T *leftArray = new T[n1];
        T *rightArray = new T[n2];

        for (int i = 0; i < n1; i++)
            leftArray[i] = seq->Get(left + i);
        for (int j = 0; j < n2; j++)
            rightArray[j] = seq->Get(mid + 1 + j);

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            if (leftArray[i] <= rightArray[j])
            {
                seq->InsertAt(leftArray[i], k);
                i++;
            }
            else
            {
                seq->InsertAt(rightArray[j], k);
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            seq->InsertAt(leftArray[i], k);
            i++;
            k++;
        }

        while (j < n2)
        {
            seq->InsertAt(rightArray[j], k);
            j++;
            k++;
        }

        delete[] leftArray;
        delete[] rightArray;
    }
};

#endif
