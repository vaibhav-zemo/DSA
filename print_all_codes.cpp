#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, char> keyMap;

void print_code(string input, string output = "")
{
    char ch = 'a';
    for (int i = 1; i < 27; i++)
    {
        keyMap[to_string(i)] = ('a' + i - 1);
    }

    if (input == "")
    {
        cout << output << endl;
        return;
    }

    print_code(input.substr(1), output + keyMap[string(1, input[0])]);
    if (input.size() > 1 && stoi(input.substr(0, 2)) < 27)
    {
        print_code(input.substr(1), output + keyMap[input.substr(0, 2)]);
    }

    return;
}

int main()
{

    string input;
    cin >> input;
    print_code(input);

    return 0;
}