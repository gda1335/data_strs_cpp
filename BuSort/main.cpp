/*
* Bubble sort implementation for C/C++.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#define ARR_SIZE 100000

double* generateRandomArray(int size)
{
    double rval;

    srand(time(NULL));

    double* arr = new double[size];

    std::cout << ARR_SIZE << " numbers is being sorted..." << std::endl;

    for (int i = 0 ; i < size ; i++)
    {
        rval = (double)rand()/RAND_MAX * 100.0;
        arr[i] = rval;
    }

    return arr;
}

// Bubble sort which big-o is O(n^2) but needs more swap operations.
void sort(double* arr, int size)
{
    while (true)
    {
        bool isChanged = false;

        for (int i = 0 ; i < size - 1 ; i++ )
        {
            if (arr[i] > arr[i+1])
            {
                double temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isChanged = true;
            }
        }

        if (!isChanged)
        {
            break;
        }
    }
    
}

int main()
{
    // To calculate delta time
    std::chrono::_V2::system_clock::time_point tStart, tEnd;

    double* arr = generateRandomArray(ARR_SIZE);

    tStart = std::chrono::high_resolution_clock::now();
    sort(arr, ARR_SIZE);
    tEnd = std::chrono::high_resolution_clock::now();

    for (int i = 0 ; i < ARR_SIZE ; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    // Free dynamically allocated memory
    delete [] arr;

    std::cout << "Elapsed time is " << (tEnd-tStart).count()*1E-9 << " seconds\n";
    std::cin.get();

    return 0;
}
