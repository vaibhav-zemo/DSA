#include <iostream>
using namespace std;

int check_array_rotation(int n, int *arr)
{
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ans = (i + 1);
        }
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout<<check_array_rotation(n,arr)<<endl;
    }

    return 0;
}