/*
* Sum of n natural numbers.
*/
#include <iostream>

int fiboAt(int n)
{
    if (n < 2)
    {
        return 1;
    }

    return fiboAt(n-1) + fiboAt(n-2);
}

int main()
{
    int n;

    std::cout << "Show fibonacci sequence up to nth element" << std::endl;
    std::cout << "Enter number : " ;
    std::cin >> n;

    for (int i = 0 ; i < n ; i++)
    {
        int fiboNum = fiboAt(i);
        std::cout << fiboNum << "-";
    }

    std::cout << "\10 ";
    std::cout << std::endl;
    
    std::cin.get();
    std::cin.get();

    return 0;
}