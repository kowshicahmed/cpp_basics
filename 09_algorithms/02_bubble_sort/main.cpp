#include <iostream>

void bubbleSort(int input[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // i reprents how many elements
        // have bubbled to the correct place
        for(int j = 0; j + 1 < n - i; j++)
        {
            if (input[j] > input[j + 1])
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int arr[] = {6,1,12,3,10,5,6};
    bubbleSort(arr, 7);
    for (int i = 0; i < (sizeof(arr)/sizeof(*arr)); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}