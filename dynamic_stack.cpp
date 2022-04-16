#include <iostream>
using namespace std;

class Dynamic_stack
{
    int nextIndex;
    int *p;
    int sizet;

public:
    Dynamic_stack()
    {
        int *p = new int[5];
        int sizet = 5;
        nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    void push(int data)
    {
        if (nextIndex == sizet)
        {
            int *newp = new int[sizet * 2];
            for (int i = 0; i < sizet; i++)
            {
                newp[i] = p[i];
            }

            sizet *= 2;
            delete[] p;
            p = newp;
        }

        p[nextIndex] = data;
        nextIndex++;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    int top()
    {
        if (nextIndex == 0)
        {
            cout << "No elements are present in stack";
            return -1;
        }

        return p[nextIndex - 1];
    }

    void pop()
    {
        if (nextIndex == 0)
        {
            cout << "No elements are present in stack" << endl;
        }
        nextIndex--;
    }
};

int main()
{
    Dynamic_stack s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);

    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    s.pop();
    cout << s.size() << endl;
    cout << s.isEmpty();

    cout << endl;
    cout << endl;
    cout << endl;

    return 0;
}