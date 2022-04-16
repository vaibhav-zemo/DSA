#include <iostream>
#include <climits>
using namespace std;

int mcp3(int **mat, int m, int n, int s, int e)
{
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    arr[m - 1][n - 1] = mat[m - 1][n - 1];
    // to fill last row
    for (int i = n - 2; i >= 0; i--)
    {
        arr[m - 1][i] = mat[m - 1][i] + arr[m - 1][i + 1];
    }

    // to fill last column
    for (int i = m - 2; i >= 0; i--)
    {
        arr[i][n - 1] = mat[i][n - 1] + arr[i + 1][n - 1];
    }

    // remaining row and columns
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            arr[i][j] = min(arr[i][j + 1], min(arr[i + 1][j], arr[i + 1][j + 1])) + mat[i][j];
        }
    }

    return arr[0][0];
}

int mcp2(int **mat, int m, int n, int **arr, int s, int e)
{
    if (s == m - 1 && e == n - 1)
    {
        return mat[s][e];
    }

    if (s >= m || e >= n)
    {
        return INT_MAX;
    }

    if (arr[s][e] != -1)
    {
        return arr[s][e];
    }

    int x = mcp2(mat, m, n, arr, s, e + 1);
    int y = mcp2(mat, m, n, arr, s + 1, e + 1);
    int z = mcp2(mat, m, n, arr, s + 1, e);
    arr[s][e] = mat[s][e] + min(x, min(y, z));

    return arr[s][e];
}

int mcp_helper(int **mat, int m, int n)
{
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = -1;
        }
    }

    return mcp2(mat, m, n, arr, 0, 0);
}

int mcp(int **mat, int m, int n, int s, int e)
{
    if (s == m - 1 && e == n - 1)
    {
        return mat[s][e];
    }

    if (s >= m || e >= n)
    {
        return INT_MAX;
    }

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (e != n - 1)
    {
        x = mcp(mat, m, n, s, e + 1);
    }
    if (s != m - 1)
    {
        y = mcp(mat, m, n, s + 1, e);
    }
    if (s != m - 1 && e != n - 1)
    {
        z = mcp(mat, m, n, s + 1, e + 1);
    }

    return mat[s][e] + min(x, min(y, z));
}

int main()
{
    int m, n;
    cout << "Enter the number of row and column:- \n";
    cin >> m >> n;

    int **mat = new int *[m];
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the data for row " << i + 1 << ":- " << endl;
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            int data;
            cin >> data;
            mat[i][j] = data;
        }
    }

    cout << mcp(mat, m, n, 0, 0) << endl;
    cout << mcp_helper(mat, m, n)<<endl;
    cout << mcp3(mat, m, n, 0, 0) << endl;

    return 0;
}