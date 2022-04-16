#include <iostream>
using namespace std;

template <typename T>
class queue
{
    T *p;
    int initialIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    queue(int n)
    {
        p = new T[n];
        nextIndex = 0;
        initialIndex = -1;
        size = 0;
        capacity = n;
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
        if (size == capacity)
        {
            cout << "queue overflow\n";
            return;
        }

        p[nextIndex] = data;
        nextIndex = (nextIndex + 1) % 5;
        if (initialIndex == -1)
        {
            initialIndex = 0;
        }

        size++;
        return;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "No Element present in queue\n";
            return 0;
        }

        return p[initialIndex];
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No Element to dequeue\n";
            return;
        }

        initialIndex = (initialIndex + 1) % 5;
        size--;
        if (size == 0)
        {
            initialIndex = -1;
            nextIndex = 0;
        }

        return;
    }
};

int main()
{
    queue<int> q(5);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(15);
    q.enqueue(65);
    q.enqueue(160);

    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    cout << q.getsize() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.getsize() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.isEmpty() << endl;

    return 0;
}