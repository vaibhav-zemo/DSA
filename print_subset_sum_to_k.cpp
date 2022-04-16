#include <iostream>
using namespace std;

void func(int *arr, int n, int *ans, int k, int j)
{
    if (n == 0)
    {
        if (k == 0)
        {
            for (int a = 0; a < j; a++)
            {
                cout << ans[a] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            return;
        }
    }

    func(arr + 1, n - 1, ans, k, j);
    ans[j] = arr[0];
    func(arr + 1, n - 1, ans, k - arr[0], j + 1);
    return;
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

    int *ans = new int [20];

    func(arr, n, ans, k, 0);

    return 0;
}