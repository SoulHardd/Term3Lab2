#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <chrono>
#include <cstdlib>                     // Для rand()
#include <ctime>                       // Для time()
#include "../Sequence/ArraySequence.h" // Предполагается, что у вас есть этот заголовок
#include "../Sequence/ListSequence.h"  // Предполагается, что у вас есть этот заголовок
#include "../Sort/HeapSort.h"          // Предполагается, что у вас есть этот заголовок
#include "../Sort/MergeSort.h"         // Предполагается, что у вас есть этот заголовок
#include "../Sort/QuickSort.h"         // Предполагается, что у вас есть этот заголовок
#include "../Sort/ShellSort.h"         // Предполагается, что у вас есть этот заголовок

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

    // Генерация случайных данных
    int a[SIZE];
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = std::rand() % SIZE;
    }

    Sequence<int> *arraySequence = new ArraySequence<int>(a, SIZE);

    // Создание сортировщиков
    ISort<int> *heapSort = new HeapSort<int>();
    ISort<int> *mergeSort = new MergeSort<int>();
    ISort<int> *quickSort = new QuickSort<int>();
    ISort<int> *shellSort = new ShellSort<int>();

    // Тестирование сортировок для ArraySequence
    runSortTest(heapSort, new ArraySequence<int>(*arraySequence), "HeapSort", SIZE);
    runSortTest(mergeSort, new ArraySequence<int>(*arraySequence), "MergeSort", SIZE);
    runSortTest(quickSort, new ArraySequence<int>(*arraySequence), "QuickSort", SIZE);
    runSortTest(shellSort, new ArraySequence<int>(*arraySequence), "ShellSort", SIZE);
}

#endif