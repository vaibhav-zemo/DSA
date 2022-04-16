#include <iostream>
#include <climits>
using namespace std;

int min_step3(int n)
{
    int *arr = new int[n + 1];

    arr[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int x = INT_MAX, y = INT_MAX;
        if (i % 2 == 0)
        {
            x = arr[i / 2];
        }
        if (i % 3 == 0)
        {
            y = arr[i / 3];
        }

        arr[i] = min(arr[i - 1], min(x, y)) + 1;
    }

    return arr[n];
}

int min_helper(int *arr, int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int x = min_helper(arr, n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = min_helper(arr, n / 2);
    }
    if (n % 3 == 0)
    {
        z = min_helper(arr, n / 3);
    }

    int output = min(x, min(y, z)) + 1;
    arr[n] = output;
    return output;
}

int min_step2(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }

    return min_helper(arr, n);
}

int min_step(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int x = min_step(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = min_step(n / 2);
    }
    if (n % 3 == 0)
    {
        z = min_step(n / 3);
    }

    return min(x, min(y, z)) + 1;
}

int main()
{
    cout << min_step(101) << endl;
    cout << min_step2(101) << endl;
    cout << min_step3(101);

    return 0;
}