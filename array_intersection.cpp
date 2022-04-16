#include <iostream>
#include <map>
using namespace std;

void intersection(int n, int m, int *arr1, int *arr2)
{
    map<int, int> Map;
    for (int i = 0; i < n; i++)
    {
        Map[arr1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (Map.count(arr2[i]))
        {
            cout << arr2[i] << " ";
        }
    }
    cout << endl;
    return;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n;

        int *arr1 = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        cin >> m;
        int *arr2 = new int[m];
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        intersection(n, m, arr1, arr2);
    }

    return 0;
}