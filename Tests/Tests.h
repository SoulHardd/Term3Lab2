#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "../Sequence/ArraySequence.h"
#include "../Sequence/ListSequence.h"
#include "../Sort/HeapSort.h"
#include "../Sort/MergeSort.h"
#include "../Sort/QuickSort.h"
#include "../Sort/ShellSort.h"
#include "../Sort/BubbleSort.h"
#include "../Sort/InsertionSort.h"

void runSortTest(ISort<int> *sorter, Sequence<int> *sequence, const std::string &sortName, int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    sorter->Sort(sequence);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Sort: " << sortName << ", Objects: " << size << ", Time: " << (duration.count()) * 1000 << " ms\n";
}

void loadTests(int SIZE)
{

    int a[SIZE];
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = std::rand() % SIZE;
    }

    Sequence<int> *arraySequence = new ArraySequence<int>(a, SIZE);

    ISort<int> *bubbleSort = new BubbleSort<int>();
    ISort<int> *insertionSort = new InsertionSort<int>();
    ISort<int> *heapSort = new HeapSort<int>();
    ISort<int> *mergeSort = new MergeSort<int>();
    ISort<int> *quickSort = new QuickSort<int>();
    ISort<int> *shellSort = new ShellSort<int>();

    // runSortTest(bubbleSort, new ArraySequence<int>(*arraySequence), "BubbleSort", SIZE);
    // runSortTest(insertionSort, new ArraySequence<int>(*arraySequence), "InsertionSort", SIZE);
    runSortTest(heapSort, new ArraySequence<int>(*arraySequence), "HeapSort", SIZE);
    runSortTest(mergeSort, new ArraySequence<int>(*arraySequence), "MergeSort", SIZE);
    runSortTest(quickSort, new ArraySequence<int>(*arraySequence), "QuickSort", SIZE);
    runSortTest(shellSort, new ArraySequence<int>(*arraySequence), "ShellSort", SIZE);
}

#endif