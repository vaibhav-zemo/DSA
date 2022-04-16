#include <bits/stdc++.h>
using namespace std;

int return_permutation(string st, string *ans)
{
    if (st.size() == 1)
    {
        ans[0] = st[0];
        return 1;
    }

    char ch = st[0];
    int size = return_permutation(st.substr(1), ans);
    int k = 0;
    int l = ans[0].size();
    string *op = new string[20];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= ans[i].size(); j++)
        {
            string temp = ans[i].substr(0, j) + ch + ans[i].substr(j);
            op[k] = temp;
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        ans[i] = op[i];
    }
    

    return size * (l + 1);
}

int main()
{

    string st;
    cin >> st;

    string *ans = new string[20];
    int size = return_permutation(st, ans);
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}