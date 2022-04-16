#include <iostream>
using namespace std;

void inplace_heap_sort(int arr[], int size)
{
    //insert //up-heapify
    cout << "Ans:- ";

    for (int i = 1; i < size; i++)
    {
        int childIndex = i;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    //remove // down-heapify

    for (int i = 1; i < size; i++)
    {
        int dynamic_size = size - i;

        int temp = arr[0];
        arr[0] = arr[dynamic_size];
        arr[dynamic_size] = temp;

        int parentIndex = 0;
        int leftchildIndex = 2 * parentIndex + 1;
        int rightchildIndex = 2 * parentIndex + 2;
        while (leftchildIndex < dynamic_size)
        {
            int minIndex = parentIndex;
            if (arr[minIndex] > arr[leftchildIndex])
            {
                minIndex = leftchildIndex;
            }
            if (rightchildIndex < dynamic_size && arr[minIndex] > arr[rightchildIndex])
            {
                minIndex = rightchildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            parentIndex = minIndex;
            leftchildIndex = 2 * parentIndex + 1;
            rightchildIndex = 2 * parentIndex + 2;
        }
    }
}

int main()
{
    int input[] = {5, 1, 2, 0, 8};
    inplace_heap_sort(input, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}