#include <iostream>
using namespace std;

int func(int *arr, int n, int **ans, int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            ans[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int x = func(arr + 1, n - 1, ans, k);
    int y = func(arr + 1, n - 1, ans + x, k - arr[0]);

    int z = x + y;
    for (int i = x; i < z; i++)
    {
        for (int j = ans[i][0]; j > 0; j--)
        {
            ans[i][j + 1] = ans[i][j];
        }
        ans[i][1] = arr[0];
        ans[i][0]++;
    }
    return z;
}

/*

""
20
12
20 12

*/

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int **ans = new int *[1000];
    for (int i = 0; i < 1000; i++)
    {
        ans[i] = new int[20];
    }

    int size = func(arr, n, ans, k);
    for (int i = 0; i < size; i++)
    {
        int l = ans[i][0];
        for (int j = 1; j <= l; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}