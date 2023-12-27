#include <iostream>

// Insertion sort which big-o is O(n^2)
int* sort(int* arr, int size)
{
    int* sorted = new int[size];
    for (int i = 0; i < size ; i++)
    {
        sorted[i] = arr[i];
    }

    for (int i = 1 ; i < size ; i++)
    {
        int temp = sorted[i];

        int j = i - 1;
        while  (j >= 0)
        {
            if ( temp < sorted[j])
            {
                sorted[j + 1] = sorted[j];
            }
            else
            {
                break;
            }

            j--;
        }

        sorted[j + 1] = temp;
    }

    return sorted;
}

// Binary search
bool binarySearch(int* arr, int size, int key)
{
    int* sorted = sort(arr, size);

    int l = 0;
    int r = size - 1;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (key < sorted[mid])
        {
            r = mid - 1;
        }
        else if (key > sorted[mid])
        {
            l = mid + 1;
        }
        else
        {
            return true;
        }
    } 

    return false;
}

int main()
{

    int n;
    int key;

    std::cout << "Search given key in array" << std::endl;
    std::cout << "Enter array size : " ;
    std::cin>>n;

    int* arr1 = new int[n];

    std::cout << "Enter elements of array : ";
    for (int i = 0 ; i < n ; i++)
	{
		std::cin>>arr1[i];
	}

    std::cout << "Enter key value : " ;
    std::cin>>key;

    if (binarySearch(arr1, n, key))
    {
        std::cout << "Key is found !" << std::endl;
    }
    else
    {
        std::cout << "Key is not found !" << std::endl;
    }

    std::cin.get();
    std::cin.get();

    return 0;
}