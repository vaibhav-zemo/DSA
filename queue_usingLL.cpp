#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T data)
    {
        Node<T> *n = new Node<T>(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        size++;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "NO Elements are present in the queue\n";
            return 0;
        }
        return head->data;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No Elements to dequeue\n";
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
};

int main()
{
    queue<int> q;
    q.enqueue(10);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    q.enqueue(16);
    q.enqueue(17);

    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.getsize()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}