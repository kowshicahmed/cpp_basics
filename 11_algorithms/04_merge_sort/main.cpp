#include <iostream>

void merge(int input[], int from, int middle, int to)
{
    int length_left = middle - from + 1;
    int length_right = to - middle;

    int *left = new int[length_left + 1];
    int *right = new int[length_right + 1];

    for (int i = 0; i < length_left; i++)
    {
        left[i] = input[from + i];
    }

    for (int i = 0; i < length_right; i++)
    {
        right[i] = input[middle + i + 1];
    }
    left[length_left] = INT_MAX;
    right[length_right] = INT_MAX;

    int left_pointer = 0;
    int right_pointer = 0;
    for (int i = from; i <= to; i++)
    {
        if (left[left_pointer] > right[right_pointer])
        {
            input[i] = right[right_pointer];
            right_pointer++;
        }
        else
        {
            input[i] = left[left_pointer];
            left_pointer++;
        }
    }
}


void merge_sort(int input[], int from, int to) 
{
    if (from < to)
    {
        int middle = (from + to) / 2;
        merge_sort(input, from, middle);    // splitting from start to middle
        merge_sort(input, middle + 1, to);  // splitting from middle+1 to end
        merge(input, from, middle, to);
    }
}

void merge_sort_executor(int input[], int n)
{
    merge_sort(input, 0, n-1);
}

int main(int argc, char **argv)
{
    int arr[] = {6,1,12,3,10,5,6,16};
    merge_sort_executor(arr, 8);
    for (int i = 0; i < (sizeof(arr)/sizeof(*arr)); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}