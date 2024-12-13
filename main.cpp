#include <iostream>
#include "Sequence/Sequence.h"
#include "Sequence/ArraySequence.h"
#include "Sort/HeapSort.h"
#include "Sort/ISort.h"
#include "Sort/QuickSort.h"
#include "Sort/ShellSort.h"
#include "Sort/MergeSort.h"
#include "Sequence/ListSequence.h"
#include "Tests/Tests.h"

#include <string>

void showMainMenu();
void sortObjectMenu();
void LoadTests();

int main()
{
    int choice;
    do
    {
        showMainMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            sortObjectMenu();
            break;
        case 2:
            LoadTests();
            break;
        case 0:
            std::cout << "Exiting the program" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}

void showMainMenu()
{
    std::cout << "\n=== Main Menu ===" << std::endl;
    std::cout << "1) Sort your object" << std::endl;
    std::cout << "2) Run load tests" << std::endl;
    std::cout << "0) Exit" << std::endl;
}

void sortObjectMenu()
{
    int objectChoice, sortChoice;
    std::cout << "\n=== Sort Object Menu ===" << std::endl;
    std::cout << "Choose object type:" << std::endl;
    std::cout << "1) Dynamic Array (ArraySequence)" << std::endl;
    std::cout << "2) Linked List (ListSequence)" << std::endl;
    std::cout << "0) Back to Main Menu" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> objectChoice;

    if (objectChoice == 0)
        return;

    int size;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    int *a = new int[size]; // Create dynamic array

    std::cout << "Enter the elements:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> a[i];
    }

    Sequence<int> *sequence = nullptr;

    switch (objectChoice)
    {
    case 1:
        sequence = new ArraySequence<int>(a, size);
        break;
    case 2:
        sequence = new ListSequence<int>(a, size);
        break;
    default:
        std::cout << "Invalid choice. Returning to Main Menu." << std::endl;
        delete[] a; // Clean up allocated memory
        return;
    }

    std::cout << "Choose sorting method:" << std::endl;
    std::cout << "1) Heap Sort" << std::endl;
    std::cout << "2) Merge Sort" << std::endl;
    std::cout << "3) Quick Sort" << std::endl;
    std::cout << "4) Shell Sort" << std::endl;
    std::cout << "0) Back to Sort Object Menu" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> sortChoice;

    ISort<int> *sorter = nullptr;

    switch (sortChoice)
    {
    case 1:
        sorter = new HeapSort<int>();
        break;
    case 2:
        sorter = new MergeSort<int>();
        break;
    case 3:
        sorter = new QuickSort<int>();
        break;
    case 4:
        sorter = new ShellSort<int>();
        break;
    case 0:
        delete[] a; // Clean up allocated memory
        return;
    default:
        std::cout << "Invalid choice. Returning to Sort Object Menu." << std::endl;
        delete[] a; // Clean up allocated memory
        return;
    }

    sorter->Sort(sequence);
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < sequence->GetLength(); ++i)
    {
        std::cout << sequence->Get(i) << " ";
    }
    std::cout << std::endl;

    // Clean up
    delete[] a;
    delete sequence;
    delete sorter;
}

void LoadTests()
{
    int num;
    std::cout << "Enter number of objects: ";
    std::cin >> num;
    std::cout << "\n=== Load Tests ===" << std::endl;
    loadTests(num);
}
