#include <iostream>
#include <math.h>
using namespace std;

int no_of_bt(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int mod = (int)(pow(10, 9)) + 7;
    int x = no_of_bt(n - 1);
    int y = no_of_bt(n - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    return (temp1 + temp2) % mod;
}

int main()
{
    int h;
    cout << "Enter the height of binary tree:- ";
    cin >> h;

    cout << no_of_bt(h);

    return 0;
}