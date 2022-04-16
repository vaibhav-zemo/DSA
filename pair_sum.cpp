#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int pair_sum(int *arr, int n, int k)
{
    
    map<int, int> M;
    for (int i = 0; i < n; i++)
    {
        M[arr[i]]++;
    }

    if (M.size()==1)
    {
        int count = 0;
        int temp = n-1;
        while (n>1)
        {
            count += temp;
            temp--;
            n--;
        }
        return count;
        
    }

    int ans = 0;
    sort(arr, arr + n);
    

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (((arr[i] + arr[j]) == k))
        {
            if ((i+1)==j)
            {
                ans++;
                i++;
                j++;
                continue;
            }
            
            ans += M[arr[i]] * M[arr[j]];
            i += M[arr[i]];
            j -= M[arr[j]];
        }
        else if ((arr[i] + arr[j]) > k)
        {
            j--;
        }
        else if ((arr[i] + arr[j]) < k)
        {
            i++;
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

        int k;
        cin >> k;

        cout << pair_sum(arr, n, k) << endl;
    }

    return 0;
}