#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> fun(int *v, int size)
{
    vector<int> ans;
    unordered_map<int, bool> map;
    for (int i = 0; i < size; i++)
    {
        if (map.count(v[i]) > 0)
        {
            continue;
        }

        map[v[i]] = true;
        ans.push_back(v[i]);
    }
    return ans;
}

int main()
{

    int v[] = {2, 3, 2, 4, 2, 3, 1, 6, 5, 2, 3, 3, 6, 5, 5};
    vector<int> output = fun(v, 15);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}