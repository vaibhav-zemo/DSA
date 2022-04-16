#include <iostream>
using namespace std;

class stack
{
    int *p;
    int nextindex;
    int capacity;

public:
    stack(int n)
    {
        p = new int[n];
        nextindex = 0;
        capacity = n;
    }

    void push(int data)
    {
        if (capacity == nextindex)
        {
            cout << "Stack overflow\n";
            return;
        }

        p[nextindex] = data;
        nextindex++;
    }

    void pop()
    {
        if (nextindex == 0)
        {
            cout << "No elements to pop\n";
            return;
        }
        nextindex--;
    }

    int top()
    {
        if (nextindex == 0)
        {
            cout << "No elements present in the stack\n";
            return -1;
        }
        return p[nextindex - 1];
    }

    int size()
    {
        return nextindex;
    }

    bool isEmpty()
    {
        return nextindex == 0;
    }
};

int main()
{
    stack s(5);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    cout << s.size() << endl;

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl;
    s.pop();
    s.pop();

    return 0;
}