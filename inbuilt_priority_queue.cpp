#include <iostream>
#include <queue>
using namespace std;

int main()
{

    priority_queue<int> q;
    q.push(45);
    q.push(4);
    q.push(145);
    q.push(65);
    q.push(235);
    q.push(454);

    cout << "Size:- " << q.size() << endl;
    cout << "Top:- " << q.top() << endl;

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}