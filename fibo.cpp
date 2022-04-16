#include <iostream>
using namespace std;

int fibo_dp(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int fibo_helper(int *arr, int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int a = fibo_helper(arr, n - 1);
    int b = fibo_helper(arr, n - 2);

    arr[n] = a + b;
    return arr[n];
}

int fibo(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }

    return fibo_helper(arr, n);
}

int main()
{
    int n;
    cout << "Enter the number\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cout << "Fibonacci of " << i << " is :- " << fibo_dp(i) << endl;
    }

    return 0;
}