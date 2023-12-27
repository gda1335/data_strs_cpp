/*
* Insertion sort implementation for C/C++.
* It is mostly used for linked lists.
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

    for (int i = 0 ; i < size ; i++)
    {
        rval = (double)rand()/RAND_MAX * 100.0;
        arr[i] = rval;
    }

    return arr;
}

// Insertion sort which big-o is O(n^2)
void sort(double* arr, int size)
{
    for (int i = 1 ; i < size ; i++)
    {
        double temp = arr[i];

        int j = i - 1;
        while  (j >= 0)
        {
            if ( temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }

            j--;
        }

        arr[j + 1] = temp;
    }
}

int main()
{
    // To calculate delta time
    std::chrono::_V2::system_clock::time_point tStart, tEnd;

    double* arr = generateRandomArray(ARR_SIZE);

    std::cout << ARR_SIZE << " numbers is being sorted..." << std::endl;

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
