#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newdata = new int[capacity * 2];
            for (int i = 0; i < capacity * 2; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    DynamicArray(DynamicArray &d)
    {
        // this->data = d.data                // This is example of shallow copy which default copy constructor do

        int *ndata = new int[this->capacity];
        for (int i = 0; i < this->nextIndex; i++)
        {
            ndata[i] = this->data[i];
        }
        d.data = ndata;
        d.capacity = this->capacity;
        d.nextIndex = this->nextIndex;
    }

    void operator=(DynamicArray &d)
    {
        int *ndata = new int[this->capacity];
        for (int i = 0; i < this->nextIndex; i++)
        {
            ndata[i] = this->data[i];
        }
        d.data = ndata;
        d.capacity = this->capacity;
        d.nextIndex = this->nextIndex;
    }

    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
    }

    int get(int i)
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void add_at_index(int i, int element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }
};
int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(12);
    d1.add(14);
    d1.add(15);
    d1.add(16);
    d1.add(19);
    d1.add(18);
    d1.add(17);

    // d1.print();
    // cout<<endl;
    // cout<<d1.get(4);
    // cout<<endl;
    // d1.add_at_index(4,105);
    // cout<<d1.get(4);

    DynamicArray d2(d1);
    d2.print();

    return 0;
}