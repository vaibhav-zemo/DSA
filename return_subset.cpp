#include <iostream>
using namespace std;

int func(int *arr, int n, int **ans)
{
    if (n == 0)
    {
        ans[0][0] = 0;
        return 1;
    }

    int smallOutput = func(arr + 1, n - 1, ans);
    for (int i = 0; i < smallOutput; i++)
    {
        int col = ans[i][0] + 1;
        ans[i + smallOutput][0] = col;
        for (int j = (ans[i][0]+1); j > 1; j--)
        {
            ans[i+smallOutput][j] = ans[i][j-1];
        }
        ans[i + smallOutput][1] = arr[0];
        
    }

    return smallOutput * 2;
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

    int **ans = new int*[1000];
    for (int i = 0; i < 1000; i++)
    {
        ans[i] = new int[20];
    }

    int size = func(arr, n, ans);
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