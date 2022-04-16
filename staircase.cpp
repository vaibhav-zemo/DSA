#include <iostream>
using namespace std;

int staircase(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

/*

1-1-1-1
1-1-2
1-2-1
1-3
2-1-1
2-2
3-1

*/

int main()
{
    int n;
    cin >> n;

    cout << staircase(n);
    return 0;
}