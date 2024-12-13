
#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class ListSequence : public Sequence<T>
{
private:
    LinkedList<T> *elements;

public:
    ListSequence()
    {
        this->elements = new LinkedList<T>();
    }

    ListSequence(int size)
    {
        this->elements = new LinkedList<T>(size);
    }

    ListSequence(T *elements, int size)
    {
        this->elements = new LinkedList<T>(elements, size);
    }

    ListSequence(const Sequence<T> &list)
    {
        const ListSequence<T> *sourceList = static_cast<const ListSequence<T> *>(&list);
        this->elements = new LinkedList<T>(*sourceList->elements);
    }

    T GetFirst()
    {
        return this->elements->GetFirst();
    }

    T GetLast()
    {
        return this->elements->GetLast();
    }

    T Get(int index)
    {
        return this->elements->Get(index);
    }

    Sequence<T> *GetSubSequence(int startIndex, int endIndex)
    {
        LinkedList<T> *SubList = this->elements->GetSubList(startIndex, endIndex);
        ListSequence<T> *SubSequence = new ListSequence<T>;
        SubSequence->elements = SubList;
        return SubSequence;
    }

    int GetLength()
    {
        return this->elements->GetLength();
    }

    Sequence<T> *Append(T element)
    {
        this->elements->Append(element);
        return this;
    }

    Sequence<T> *Prepend(T element)
    {
        this->elements->Prepend(element);
        return this;
    }

    Sequence<T> *InsertAt(T element, int index)
    {
        this->elements->InsertAt(element, index);
        return this;
    }

    Sequence<T> *Concat(Sequence<T> *list)
    {
        ListSequence<T> *concatList = new ListSequence<T>;
        ListSequence<T> *tmp = static_cast<ListSequence<T> *>(list);
        concatList->elements = this->elements->Concat(tmp->elements);
        return concatList;
    }
};

#endif