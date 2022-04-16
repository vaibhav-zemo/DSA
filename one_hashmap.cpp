#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> map;
    pair<string, int> p("abc", 1);
    map.insert(p);
    map["efg"] = 2;

    cout << map["abc"] << endl;
    cout << map.at("abc") << endl;
    // cout<<map.at("wer")<<endl; here at will throw error becuase wer is not present in map
    cout << "size:" << map.size() << endl;
    cout << map["wer"] << endl; // [] will give 0 output if the input is not present but it will also add wer in map
    cout << "size:" << map.size() << endl;

    if (map.count("wer") > 0) // .count gives only two value 0 when key is not present and 1 when key is present
    {
        cout << "wer is present" << endl;
    }

    map.erase("wer");
    if (map.count("wer") > 0)
    {
        cout << "wer is present" << endl;
    }

    return 0;
}