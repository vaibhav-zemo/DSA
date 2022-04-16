#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(14);
    pq.push(15);
    pq.push(122);
    pq.push(2);

    cout << "Size: " << pq.size() << endl;
    cout << "Is Empty: " << pq.empty() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}