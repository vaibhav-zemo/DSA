#include <iostream>
#include <queue>
using namespace std;

void k_smallest_ele(int arr[], int n, int k)
{
    priority_queue<int> min;
    for (int i = 0; i < k; i++)
    {
        min.push(arr[i]);
    }

    int top;
    for (int i = k; i < n; i++)
    {
        top = min.top();
        if (top > arr[i])
        {
            min.pop();
            min.push(arr[i]);
        }
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = min.top();
        min.pop();
    }
}

int main()
{
    int arr[] = {8, 5, 12, 10, 0, 1, 6, 9};
    k_smallest_ele(arr, 8, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}