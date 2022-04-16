#include <iostream>
using namespace std;

void merge(int *arr, int s, int e, int mid)
{
    int n1 = mid - s+1;
    int n2 = e - mid;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[s + i];
    }

    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid +1+ i];
    }

    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
    {
        if (arr1[i] >= arr2[j])
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergesort(int *arr, int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid+1, e);

        merge(arr, s, e, mid);
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

    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}