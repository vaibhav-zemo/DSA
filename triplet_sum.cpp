#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int triplet_sum(int n, int *arr, int x)
{
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int left;
        if (arr[i] < 0)
        {
            left = x + arr[i];
        }
        else
        {
            left = x - arr[i];
        }
        int j = i + 1, k = n - 1;
        while (j < k)
        {

            if ((arr[j] + arr[k]) == left)
            {
                // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                ans++;
                j++;
                k--;
            }
            else if ((arr[j] + arr[k]) > left)
            {
                k--;
            }
            else if ((arr[j] + arr[k]) < left)
            {
                j++;
            }
        }
    }
    return ans;
}

/*
1,4,7
1,5,6
2,3,7
2,4,6
3,4,5

-6 -5 -3 0 2 5 8 10 11

*/

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

        int k;
        cin >> k;

        cout << triplet_sum(n, arr, k) << endl;
    }

    return 0;
}