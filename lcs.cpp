#include <iostream>
#include <string>
using namespace std;

int lcs3(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[n + 1];
    }

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
            }

            else if (s[m - i] == t[n - j])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                int a = arr[i][j - 1];
                int b = arr[i - 1][j];
                int c = arr[i - 1][j - 1];
                arr[i][j] = max(a, max(b, c));
            }
        }
    }

    return arr[m][n];
}

int lcs2(int **arr, string s, string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    if (arr[s.length()][t.length()] != -1)
    {
        return arr[s.length()][t.length()];
    }

    if (s[0] == t[0])
    {
        return 1 + lcs2(arr, s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs2(arr, s, t.substr(1));
        int b = lcs2(arr, s.substr(1), t);

        return max(a, b);
    }
}

int lcs_helper(string s, string t)
{
    int **arr = new int *[s.length() + 1];
    for (int i = 0; i < s.length() + 1; i++)
    {
        arr[i] = new int[t.length() + 1];
        for (int j = 0; j < t.length() + 1; j++)
        {
            arr[i][j] = -1;
        }
    }

    return lcs2(arr, s, t);
}

int lcs(string s, string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int c = lcs(s, t.substr(1));
        return max(a, c);
    }
}

int main()
{
    string s, t;
    cout << "Enter the two strings:- \n";
    cin >> s >> t;

    cout << lcs(s, t) << endl;
    cout << lcs_helper(s, t) << endl;
    cout << lcs3(s, t) << endl;

    return 0;
}