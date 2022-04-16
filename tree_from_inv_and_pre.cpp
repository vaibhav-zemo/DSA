#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class tree
{
public:
    T data;
    tree<T> *left;
    tree<T> *right;
    tree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~tree()
    {
        delete left;
        delete right;
    }
};

tree<int> *build_tree_helper(int *inv, int *pre, int invS, int invE, int preS, int preE)
{
    if (invS > invE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    tree<int> *root = new tree<int>(rootData);
    int rootIndex = -1;
    for (int i = invS; i <= invE; i++)
    {
        if (rootData == inv[i])
        {
            rootIndex = i;
            break;
        }
    }

    int linvS = invS;
    int linvE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linvE - linvS + lpreS;
    int rinvS = rootIndex + 1;
    int rinvE = invE;
    int rpreS = lpreE + 1;
    int rpreE = preE;

    root->left = build_tree_helper(inv, pre, linvS, linvE, lpreS, lpreE);
    root->right = build_tree_helper(inv, pre, rinvS, rinvE, rpreS, rpreE);
    return root;
}

tree<int> *build_tree(int *inv, int *pre, int size)
{
    return build_tree_helper(inv, pre, 0, size - 1, 0, size - 1);
}

void output(tree<int> *root)
{
    queue<tree<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        tree<int> *front = q.front();
        q.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ", ";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "L" << front->right->data << ", ";
            q.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    int inv[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    tree<int> *root = build_tree(inv, pre, 9);
    output(root);

    return 0;
}