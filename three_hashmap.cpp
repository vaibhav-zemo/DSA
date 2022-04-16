#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_map<string, int> map;
    map["abc1"] = 1;
    map["abc2"] = 2;
    map["abc3"] = 3;
    map["abc4"] = 4;
    map["abc5"] = 5;
    map["abc6"] = 6;
    map["abc7"] = 7;

    unordered_map<string, int>::iterator it = map.begin();
    while (it != map.end())
    {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }

    unordered_map<string,int>::iterator it2 = map.find("abc1");
    map.erase(it2,it2 + 4);  // here + 4 means it2 upto fouth iteration



    return 0;
}