#include <iostream>
#include <math.h>
using namespace std;

int min_count3(int n)
{
    int *arr = new int[n+1];

    arr[0] = 0;
    for (int i = 1; i < n +1; i++)
    {
        int root = sqrt(i);
        arr[i] = i - pow(root, 2) + 1;
    }
    return arr[n];
}

int min_count2(int n, int *arr)
{
    if (n <= 0)
    {
        return 0;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int root = sqrt(n);
    arr[n] = min_count2(n - pow(root, 2), arr) + 1;

    return arr[n];
}

int min_count_helper(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    return min_count2(n, arr);
}

int min_count(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int root = sqrt(n);
    n -= pow(root, 2);
    return min_count(n) + 1;
}

int main()
{
    int n;
    cout << "Enter the number:- \n";
    cin >> n;
    cout << min_count(n) << endl;
    cout << min_count_helper(n)<<endl;
    cout << min_count3(n) << endl;

    return 0;
}