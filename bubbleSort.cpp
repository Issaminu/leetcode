#include <iostream>
int *bubbleSort(int *array, int length)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                isSorted = false;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        if (isSorted)
            break;
    }
    return array;
}

int main()
{
    int array[] = {66, 54, 78, 43, 2, 1, 27, 73, 63};
    std::cout << "Priting the array";
    int *test = bubbleSort(array, 9);
    for (int i = 0; i < 9; i++)
    {
        std::cout << test[i] << " ";
    }
}
