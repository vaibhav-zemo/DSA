#include <iostream>
#include <string>
using namespace std;

int editDis3(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = i;
    }

    for (int i = 0; i <= n; i++)
    {
        arr[0][i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else
            {
                int a = arr[i][j - 1];
                int b = arr[i - 1][j];
                int c = arr[i - 1][j - 1];
                arr[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }
    return arr[m][n];
}

int editDis2(string s, string t, int **arr)
{
    int m = s.length();
    int n = t.length();

    if (m == 0 || n == 0)
    {
        return max(m, n);
    }

    if (arr[m][n] != -1)
    {
        return arr[m][n];
    }

    if (s[0] == t[0])
    {
        return editDis2(s.substr(1), t.substr(1), arr);
    }
    else
    {
        int a = editDis2(s.substr(1), t, arr) + 1;
        int b = editDis2(s.substr(1), t.substr(1), arr) + 1;
        int c = editDis2(s, t.substr(1), arr) + 1;
        arr[m][n] = min(a, min(b, c));
    }
    return arr[m][n];
}

int editDis_helper(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            arr[i][j] = -1;
        }
    }

    return editDis2(s, t, arr);
}

int editDis(string s, string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    if (s[0] == t[0])
    {
        return editDis(s.substr(1), t.substr(1));
    }
    else
    {
        int a = 1 + editDis(s.substr(1), t);
        int b = 1 + editDis(s, t.substr(1));
        int c = 1 + editDis(s.substr(1), t.substr(1));
        return min(a, min(b, c));
    }
}

int main()
{
    string s, t;
    cout << "Enter the two strings:- \n";
    cin >> s >> t;

    cout << editDis(s, t) << endl;
    cout << editDis_helper(s, t) << endl;
    cout << editDis3(s, t) << endl;

    return 0;
}