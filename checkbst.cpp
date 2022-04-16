#include <iostream>
#include <limits.h>
#include <queue>
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

int minmum(bst<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minmum(root->left), minmum(root->right)));
}

int maxmum(bst<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maxmum(root->left), maxmum(root->right)));
}

bool isBST(bst<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftmax = maxmum(root->left);
    int rightmin = minmum(root->right);

    bool output = (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
    return output;
}

int main()
{
    bst<int> *root = input();
    cout << isBST(root) << endl;

    return 0;
}