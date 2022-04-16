#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> q;
    q.push(10);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.empty()<<endl;


    return 0;
}