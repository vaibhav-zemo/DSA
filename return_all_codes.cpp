#include <iostream>
#include <string>
using namespace std;

int return_code(string input, string *output)
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    int x = return_code(input.substr(1), output);
    int y = 0;
    if (input.size() > 1)
    {
        if (((input[0]-'0') * 10 + (input[1]-'0') >= 10) && ((input[0]-'0') * 10 + (input[1]-'0') < 27))
        {
            y = return_code(input.substr(2), output+x);
        }
    }

    for (int i = 0; i < x; i++)
    {
        char temp = ('a' + (input[0]-'0') - 1);
        output[i] = temp + output[i];
    }

    for (int i = x; i < x+y; i++)
    {
        char temp = ('a' + stoi(input.substr(0, 2)) - 1);
        output[i] = temp + output[i];
    }

    return x + y;
}

int main()
{

    string input;
    cin >> input;

    string *output = new string[20];
    int size = return_code(input, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}