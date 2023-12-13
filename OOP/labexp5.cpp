#include <iostream>

template <typename T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

template <typename T>
void displayArray(const T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int intArraySize;

    std::cout << "Enter Array Size: " << std::endl;
    std::cin >> intArraySize;

    int intArray[intArraySize];
    float floatArray[intArraySize];

    std::cout << "Enter " << intArraySize << " integers for the array:" << std::endl;
    for (int i = 0; i < intArraySize; ++i)
    {
        std::cin >> intArray[i];
    }

    std::cout << "Enter " << intArraySize << " floating-point numbers for the array:" << std::endl;
    for (int i = 0; i < intArraySize; ++i)
    {
        std::cin >> floatArray[i];
    }

    std::cout << "\nOriginal Integer Array: ";
    displayArray(intArray, intArraySize);

    selectionSort(intArray, intArraySize);

    std::cout << "Sorted Integer Array: ";
    displayArray(intArray, intArraySize);

    std::cout << std::endl;

    std::cout << "Original Float Array: ";
    displayArray(floatArray, intArraySize);

    selectionSort(floatArray, intArraySize);

    std::cout << "Sorted Float Array: ";
    displayArray(floatArray, intArraySize);

    return 0;
}
