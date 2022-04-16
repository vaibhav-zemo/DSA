#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int Maxfreq(int *input, int n)
{
    unordered_map<int, int> map;
    int maxFreq = 0;
    for (int i = 0; i < n; i++)
    {
        if (map.count(input[i]) > 0)
        {
            map[input[i]]++;
            if (map[input[i]] > maxFreq)
            {
                maxFreq = map[input[i]];
            }
        }
        map[input[i]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (map[input[i]] == maxFreq)
        {
            return input[i];
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;

    cout << "Enter the values of the array\n";
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << Maxfreq(p, n);

    return 0;
}