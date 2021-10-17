#include <iostream>

void selectionSort(int input[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // i points at the first number behind the "wall"
        int indexOfSmallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (input[j] < input[indexOfSmallest])
            {
                indexOfSmallest = j;
            }
        }
        // swap
        int temp = input[i];
        input[i] = input[indexOfSmallest];
        input[indexOfSmallest] = temp;
    }
}





int main()
{
    int arr[] = {6,1,12,3,10,5,6};
    selectionSort(arr, 7);
    for (int i = 0; i < (sizeof(arr)/sizeof(*arr)) -1 ; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}