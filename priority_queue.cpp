#include <iostream>
#include <vector>
using namespace std;

class priority
{
    vector<int> arr;

public:
    priority()
    {
    }

    int size()
    {
        return arr.size();
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }

    int getmin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return arr[0];
    }

    void insert(int data)
    {
        arr.push_back(data);
        int childIndex = arr.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int remove_data()
    {
        if (isEmpty())
        {
            return 0;
        }

        int ans = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();

        int parentIndex = 0;
        int leftIndex = 2 * parentIndex + 1;
        int rightIndex = 2 * parentIndex + 2;
        while (leftIndex < arr.size())
        {
            int minIndex = parentIndex;
            if (arr[minIndex] > arr[leftIndex])
            {
                minIndex = leftIndex;
            }
            if (rightIndex < arr.size() && arr[minIndex] > arr[rightIndex])
            {
                minIndex = rightIndex;
            }
            if (parentIndex == minIndex)
            {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftIndex = 2 * parentIndex + 1;
            rightIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};

int main()
{
    priority p;
    p.insert(10);
    p.insert(12);
    p.insert(13);
    p.insert(14);
    p.insert(15);

    cout << p.size() << endl;
    cout << p.getmin() << endl;
    while (!p.isEmpty())
    {
        cout << p.remove_data() << " ";
    }
    cout << endl;

    return 0;
}