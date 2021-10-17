#include <iostream>

int partition(int input[], int from, int to)
{
    int pivot = input[to];
    int wall = from;
    for (int i = from; i < to; i++)
    {
        if (input[i] <= pivot)
        {
            int temp = input[wall];
            input[wall] = input[i];
            input[i] = temp;
            wall++;
        }
    }
    input[to] = input [wall];
    input[wall] = pivot;

    return wall;
}


void quickSort(int input[], int from, int to)
{
    if (from < to)
    {
        int indexOfPivot = partition(input, from, to);
        quickSort(input, from, indexOfPivot - 1);
        quickSort(input, indexOfPivot + 1, to);
    }
}


void quickSortExecutor(int input[], int n)
{
    quickSort(input, 0, n - 1);
}

int main ()
{
    int arr[] = {6,1,12,3,10,5,6,16};
    quickSortExecutor(arr, 8);
    for (int i = 0; i < (sizeof(arr)/sizeof(*arr)); i++)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}