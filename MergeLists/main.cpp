/*
* Merge given 4 lists in sorted order
*/
#include <iostream>

// Insertion sort which big-o is O(n^2)
void sort(int* arr, int size)
{
    for (int i = 1 ; i < size ; i++)
    {
        int temp = arr[i];

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

int* merge2(int* arr1, int size1, int* arr2, int size2)
{
	int* merged = new int[size1 + size2];

	sort(arr1, size1);
	sort(arr2, size2);

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < size1 && j < size2)
	{
		if (arr1[i] <= arr2[j])
		{
			merged[k] = arr1[i];
			i++;
			k++;
		}
		else
		{
			merged[k] = arr2[j];
			j++;
			k++;
		}
	}

	while (i < size1)
	{
		merged[k] = arr1[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		merged[k] = arr2[j];
		j++;
		k++;
	}

	return merged;
}

void merge4(
	int** mergedList,
	int* mergedSize,
	int* arr1, int size1,
	int* arr2, int size2,
	int* arr3, int size3,
	int* arr4, int size4)
{
	*mergedSize = size1 + size2 + size3 + size4;
	*mergedList = merge2(arr1, size1, arr2, size2);
	*mergedList = merge2(*mergedList, size1 + size2, arr3, size3);
	*mergedList = merge2(*mergedList, size1 + size2 + size3, arr4, size4);
}

int main()
{
	int nElements[4];

    std::cout << "Merge given 4 lists" << std::endl;

	for (int i = 0 ; i < 4 ; i++)
	{
		std::cout << "Enter number of elements of List " << i+1 <<  " : " ;
    	std::cin >> nElements[i];
	}
    
	int *arr1, *arr2, *arr3, *arr4;
	arr1 = new int[nElements[0]];
	arr2 = new int[nElements[1]];
	arr3 = new int[nElements[2]];
	arr4 = new int[nElements[3]];

	std::cout << "Enter elements of List 1 : ";
    for (int i = 0 ; i < nElements[0] ; i++)
	{
		std::cin>>arr1[i];
	}

	std::cout << "Enter elements of List 2 : ";
    for (int i = 0 ; i < nElements[1] ; i++)
	{
		std::cin>>arr2[i];
	}

	std::cout << "Enter elements of List 3 : ";
    for (int i = 0 ; i < nElements[2] ; i++)
	{
		std::cin>>arr3[i];
	}

	std::cout << "Enter elements of List 4 : ";
    for (int i = 0 ; i < nElements[3] ; i++)
	{
		std::cin>>arr4[i];
	}

	int* mergedList;
	int mergedSize;
	merge4(
		&mergedList,
		&mergedSize,
		arr1, nElements[0],
		arr2, nElements[1],
		arr3, nElements[2],
		arr4, nElements[3]);

	std::cout << "Merged list : " << std::endl;
	for (int i = 0 ; i < mergedSize ; i++)
	{
		std::cout << mergedList[i] << " " ;
	}

	delete [] arr1;
	delete [] arr2;
	delete [] arr3;
	delete [] arr4;
    
    std::cin.get();
    std::cin.get();

    return 0;
}