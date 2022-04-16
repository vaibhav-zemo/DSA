#include <iostream>
using namespace std;

int binary_search(int *arr, int s, int e, int x)
{
    int mid = (s + e) / 2;
    if (s > e)
    {
        return -1;
    }

    if (x == arr[mid])
    {
        return mid;
    }
    else if (x > arr[mid])
    {
        s = mid + 1;
    }
    else
    {
        e = mid - 1;
    }
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << binary_search(arr, 0, n - 1, x);

    return 0;
}