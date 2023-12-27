/*
* Sum of n natural numbers.
*/
#include <iostream>

int sumOfN(int n)
{
    if (n < 1)
    {
        return 0;
    }

    return sumOfN(n - 1) + n;
}
int main()
{
    int n;

    std::cout << "Sum of N natural numbers" << std::endl;
    std::cout << "Enter number : " ;
    std::cin >> n;

    int sum = sumOfN(n);

    std::cout << "Sum of 0 up to " << n << " numbers : " << sum << std::endl;
    std::cin.get();
    std::cin.get();

    return 0;
}