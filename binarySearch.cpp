#include <iostream>
int binarySearch(int *array, int searchedNum, int low, int high)
{
    int i = (high + low) / 2;
    if (array[i] == searchedNum)
        return i;
    if ((high - low) < 1)
        return -1;
    if (searchedNum < array[i])
        return binarySearch(array, searchedNum, low, i);
    else
        return binarySearch(array, searchedNum, i + 1, high);
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 6, 8, 9, 22};
    std::cout << binarySearch(array, 6, 0, 8);
}