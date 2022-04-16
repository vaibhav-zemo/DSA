#include <bits/stdc++.h>
using namespace std;

void print(int *input, int i, int n, int *output, int j)
{
    if (i == n)
    {
        int idx = 0;
        while (idx < j)
        {
            cout << output[idx] << " ";
            ++idx;
        }
        cout << endl;
        return;
    }

    print(input, i + 1, n, output, j);
    output[j] = input[i];
    print(input, i + 1, n, output, j + 1);
}

/*

20
12
20 12

*/

int main()
{

    int n;
    cin >> n;

    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int *output = new int[100];
    output[0] = 0;
    print1(input, 0, n, output);

    return 0;
}