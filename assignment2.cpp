#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void intersection(int **p, int t)
{
    unordered_map<int, bool> map;
}

int main()
{

    int t;
    cout << "Enter the no. of testcases\n";
    cin >> t;

    int temp;
    vector<vector<int>> v;
    for (int i = 0; i < t * 2; i++)
    {
        int a;
        cout << "Enter no. of integar\n";
        cin >> a;
        cout << "Enter the values of array:- " << i << endl;
        for (int j = 0; j < a; j++)
        {
            cout<<"j"<<endl;
            cin>>v[i][j];
        }
        
    }

    return 0;
}