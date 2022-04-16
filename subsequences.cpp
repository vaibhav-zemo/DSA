#include <iostream>
#include <string>
using namespace std;

// void print(string st, string ans = "")
// {
//     if (st.length() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     substring(st.substr(1), ans);
//     substring(st.substr(1), ans + st[0]);
// }

int subs(string st, string ans[])
{
    if (st.empty())
    {
        ans[0] = "";
        return 1;
    }

    int smallOutput = subs(st.substr(1), ans);
    for (int i = 0; i < smallOutput; i++)
    {
        ans[i + smallOutput] =  st[0] + ans[i];
    }

    return smallOutput*2;
}

int main()
{

    string st;
    cin >> st;
    string *ans = new string[1000];
    int count = subs(st, ans);
    for (int i = 0; i < count; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}