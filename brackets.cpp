#include <iostream>
#include <stack>
using namespace std;

bool check_brackets(string st)
{
    int i = 0;
    stack<char> s;
    while (st[i] != '\0')
    {
        if (st[i] == '(' || st[i] == '{' || st[i] == '[')
        {
            s.push(st[i]);
        }
        else if (st[i] == ')' && s.top() != '(')
        {
            return 0;
        }
        else if (st[i] == ']' && s.top() != '[')
        {
            return 0;
        }
        else if (st[i] == '}' && s.top() != '{')
        {
            return 0;
        }
        else
        {
            s.pop();
        }
        i++;
    }
    return 1;
}

int main()
{
    string st;
    cin >> st;

    cout << check_brackets(st);

    return 0;
}