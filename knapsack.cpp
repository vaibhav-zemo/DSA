#include <iostream>
using namespace std;

int knapsack3(int *w, int *v, int n, int wmax)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[wmax + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int f = 0; f <= wmax; f++)
        {
            if (i == 0 || f == 0)
            {
                arr[i][f] = 0;
            }
            else if (w[n - i] > f)
            {
                arr[i][f] = arr[i - 1][f];
            }
            else
            {

                int x = arr[i - 1][f - w[n - i]] + v[n - i];
                int y = arr[i - 1][f];
                arr[i][f] = max(x, y);
            }
        }
    }
    return arr[n][wmax];
}

int knapsack2(int *w, int *v, int n, int wmax, int **arr)
{

    if (n == 0 || wmax == 0)
    {
        return 0;
    }

    if (arr[n][wmax] != -1)
    {
        return arr[n][wmax];
    }

    if (w[0] > wmax)
    {
        return knapsack2(w + 1, v + 1, n - 1, wmax, arr);
    }

    int x = knapsack2(w + 1, v + 1, n - 1, wmax - w[0], arr) + v[0];
    int y = knapsack2(w + 1, v + 1, n - 1, wmax, arr);

    arr[n][wmax] = max(x, y);
    return arr[n][wmax];
}

int knapsack_helper(int *w, int *v, int n, int wmax)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[wmax + 1];
        for (int f = 0; f <= wmax; f++)
        {
            arr[i][f] = -1;
        }
    }
    return knapsack2(w, v, n, wmax, arr);
}

int knapsack(int *w, int *v, int n, int wmax)
{
    if (n == 0 || wmax == 0)
    {
        return 0;
    }

    if (w[0] > wmax)
    {
        return knapsack(w + 1, v + 1, n - 1, wmax);
    }

    int x = knapsack(w + 1, v + 1, n - 1, wmax - w[0]) + v[0];
    int y = knapsack(w + 1, v + 1, n - 1, wmax);

    return max(x, y);
}

int main()
{

    int n;
    cout << "No. of items:- \n";
    cin >> n;

    int *w = new int[n];
    int *v = new int[n];
    cout << "Enter the weights:- \n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        w[i] = a;
    }
    cout << "Enter the  value:- \n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = a;
    }

    int wmax;
    cout << "Enter max weight:- \n";
    cin >> wmax;

    cout << knapsack(w, v, n, wmax) << endl;
    cout << knapsack_helper(w, v, n, wmax) << endl;
    cout << knapsack3(w, v, n, wmax) << endl;

    return 0;
}