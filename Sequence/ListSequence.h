
#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class MutableListSequence : public Sequence<T>
{
private:
    LinkedList<T> *elements;

public:
    MutableListSequence()
    {
        this->elements = new LinkedList<T>();
    }

    MutableListSequence(T *elements, int size)
    {
        this->elements = new LinkedList<T>(elements, size);
    }

    MutableListSequence(const MutableListSequence<T> &list)
    {
        this->elements = new LinkedList<T>(*list.elements);
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
        MutableListSequence<T> *SubSequence = new MutableListSequence<T>;
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
        MutableListSequence<T> *concatList = new MutableListSequence<T>;
        MutableListSequence<T> *tmp = static_cast<MutableListSequence<T> *>(list);
        concatList->elements = this->elements->Concat(tmp->elements);
        return concatList;
    }
};

template <class T>
class ImmutableListSequence : public Sequence<T>
{
private:
    LinkedList<T> *elements;

public:
    ImmutableListSequence()
    {
        this->elements = new LinkedList<T>();
    }

    ImmutableListSequence(T *elements, int size)
    {
        this->elements = new LinkedList<T>(elements, size);
    }

    ImmutableListSequence(const ImmutableListSequence<T> &list)
    {
        this->elements = new LinkedList<T>(*list.elements);
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
        ImmutableListSequence<T> *SubSequence = new ImmutableListSequence<T>;
        SubSequence->elements = SubList;
        return SubSequence;
    }

    int GetLength()
    {
        return this->elements->GetLength();
    }

    ImmutableListSequence<T> *Copy()
    {
        return new ImmutableListSequence<T>(*this);
    }

    Sequence<T> *Append(T element)
    {
        ImmutableListSequence<T> *copy = Copy();
        copy->elements->Append(element);
        return copy;
    }

    Sequence<T> *Prepend(T element)
    {
        ImmutableListSequence<T> *copy = Copy();
        copy->elements->Prepend(element);
        return copy;
    }

    Sequence<T> *InsertAt(T element, int index)
    {
        ImmutableListSequence<T> *copy = Copy();
        copy->elements->InsertAt(element, index);
        return copy;
    }

    Sequence<T> *Concat(Sequence<T> *list)
    {
        ImmutableListSequence<T> *copy = Copy();
        ImmutableListSequence<T> *concatList = new ImmutableListSequence<T>;
        ImmutableListSequence<T> *tmp = static_cast<ImmutableListSequence<T> *>(list);
        concatList->elements = copy->elements->Concat(tmp->elements);
        return concatList;
    }
};

#endif