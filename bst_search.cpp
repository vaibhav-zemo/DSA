#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class bst
{
public:
    T data;
    bst<int> *left;
    bst<int> *right;

    bst(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~bst()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete left;
        }
    }
};

bst<int> *input()
{
    int r;
    cout << "Enter the root of the tree\n";
    cin >> r;

    if (r == -1)
    {
        return NULL;
    }

    bst<int> *root = new bst<int>(r);
    queue<bst<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        bst<int> *front = q.front();
        q.pop();

        int leftnode;
        cout << "Enter the left node of " << front->data << endl;
        cin >> leftnode;
        if (leftnode != -1)
        {
            bst<int> *leftn = new bst<int>(leftnode);
            front->left = leftn;
            q.push(leftn);
        }

        int rightnode;
        cout << "Enter the right node of " << front->data << endl;
        cin >> rightnode;
        if (rightnode != -1)
        {
            bst<int> *rightn = new bst<int>(rightnode);
            front->right = rightn;
            q.push(rightn);
        }
    }
    return root;
}

bool search(bst<int> *root, int value)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }

    if (root->data > value)
    {
        search(root->left, value);
    }

    if (root->data < value)
    {
        search(root->right, value);
    }
}

bool search_bt(bst<int> *root, int min, int max, vector<int> &v)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data >= min && root->data <= max)
    {
        // cout << root->data << " ";
        v.push_back(root->data);
    }

    if (root->data > min || root->data > max)
    {
        search_bt(root->left, min, max, v);
    }

    if (root->data < max || root->data < min)
    {
        search_bt(root->right, min, max, v);
    }
}

int main()
{
    bst<int> *root = input();
    // int data;
    // cout << "Enter the data\n";
    // cin >> data;
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    // if (search(root, data))
    // {
    //     cout << 1;
    // }
    // else
    // {
    //     cout << 0;
    // }
    // vector<int> v;
    // search_bt(root, 6, 10, v);
    // sort(v.begin(), v.end());
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    return 0;
}