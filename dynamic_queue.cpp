#include <iostream>
using namespace std;

template <typename T>
class Dynamic_q
{
    T *p;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    Dynamic_q()
    {
        p = new T[5];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        if (size == capacity)
        {
            T *newp = new T[capacity * 2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newp[j] = p[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newp[j] = p[i];
                j++;
            }

            delete[] p;
            p = newp;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }

        p[nextIndex] = data;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
        return;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "No Elements are present in queue\n";
            return 0;
        }

        return p[firstIndex];
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No Elements are present to dequeue\n";
            return;
        }

        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
            return;
        }
        return;
    }
};

int main()
{
    Dynamic_q<int> d;
    d.enqueue(23);
    d.enqueue(25);
    d.enqueue(27);
    d.enqueue(24);
    d.enqueue(63);
    d.enqueue(73);
    d.enqueue(83);

    cout << d.front() << endl;
    d.dequeue();
    cout << d.front() << endl;
    cout << d.getsize() << endl;
    d.dequeue();
    d.dequeue();
    d.dequeue();
    d.dequeue();
    d.dequeue();
    d.dequeue();
    d.dequeue();
    cout << d.isEmpty();

    return 0;
}