#include <bits/stdc++.h>
using namespace std;

void print_permutation(string st, string ans)
{
    if (st.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = st[0];
    for (int i = ans.size(); i >= 0; i--)
    {
        string temp = ans.substr(0, i) + ch + ans.substr(i);
        print_permutation(st.substr(1), temp);
    }
}

int main()
{

    string st;
    cin >> st;

    string ans = "";
    print_permutation(st, ans);

    return 0;
}