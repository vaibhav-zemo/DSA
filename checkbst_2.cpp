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

class betterbst
{
public:
    int minimum;
    int maximum;
    bool isBST;
};

betterbst isBST2(bst<int> *root)
{
    if (root == NULL)
    {
        betterbst output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }

    betterbst leftnode = isBST2(root->left);
    betterbst rightnode = isBST2(root->right);
    int maximum = max(root->data, max(leftnode.maximum, rightnode.maximum));
    int minimum = min(root->data, min(leftnode.minimum, rightnode.minimum));
    bool isBSTfinal = (root->data > leftnode.maximum) && (root->data <= rightnode.minimum) && rightnode.isBST && leftnode.isBST;
    betterbst output;
    output.maximum = maximum;
    output.minimum = minimum;
    output.isBST = isBSTfinal;
    return output;
}

int main()
{
    bst<int> *root = input();
    cout << isBST2(root).isBST<< endl;

    return 0;
}