#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class stack
{
    Node *head;
    int len;

public:
    stack()
    {
        head = NULL;
        len = 0;
    }

    int size()
    {
        return len;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        len++;
        return;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "NO Elements to pop\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        len--;
        delete temp;
        return;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "NO Elements are present in stack\n";
            return -1;
        }

        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(12);
    s.push(14);
    s.push(15);
    s.push(16);

    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}