#include <iostream>
#include <string>
using namespace std;

int return_keypad(string *arr, int n, string *output)
{
    if (n == 0)
    {
        output[0] = "";
        return 1;
    }

    int rem = n % 10;
    int length = return_keypad(arr, n/10, output);
    int l = length;

    string *temp = new string[l];
    for (int i = 0; i < l; i++)
    {
        temp[i] = output[i];
    }
    
    int k = 0;
    for (int j=0;j<length;j++)
    {
        for (int i = 0; i < arr[rem-1].size(); i++)
        {
            output[k] = temp[j] + arr[rem-1][i];
            k++;
        }
    }

    return arr[rem].size() * length;
}

void print(string *ans, int n, string output = "")
{
    if (n <= 0)
    {
        cout << output << endl;
        return;
    }

    int rem = n % 10;
    int length = ans[rem - 1].size();
    for (int i = 0; i < length; i++)
    {
        print(ans, n / 10, ans[rem - 1][i] + output);
    }
}

int main()
{
    string arr[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n;
    cin >> n;

    string *output = new string[1000];
    int size = return_keypad(arr, n, output);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}