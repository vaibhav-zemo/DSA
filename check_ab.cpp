#include <iostream>
using namespace std;

bool check(string st, bool flag)
{
    if (st.size() == 0)
    {
        return true;
    }

    if (flag == false && st[0] != 'a')
    {
        return false;
    }

    if (st[0] == 'a' && st[1] != '\0' && st[1] != 'a' && st.substr(1, 2) != "bb")
    {
        return false;
    }

    if (st.substr(0, 1) == "bb" && st[2] != '\0' && st[2] != 'a')
    {
        return false;
    }
    else if (st.substr(0, 1) == "bb")
    {
        flag = true;
        return check(st.substr(2), flag);
    }

    flag = true;
    return check(st.substr(1), flag);
}

int main()
{

    string st;
    cin >> st;
    cout << check(st, false);

    return 0;
}