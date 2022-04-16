#include <iostream>
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
        delete left;
        delete right;
    }
};

bst<int> *create(int *p, int s, int e)
{
    bst<int> *root = NULL;
    if (s == e)
    {
        root = new bst<int>(p[s]);
        return root;
    }
    int mid = (s + e) / 2;
    root = new bst<int>(p[mid]);

    root->left = create(p, s, mid - 1);
    root->right = create(p, mid + 1, e);
    return root;
}

void output(bst<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<bst<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        bst<int> *front = q.front();
        cout << front->data << ": ";
        q.pop();

        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ", ";
            q.push(front->left);
        }

        if (front->right != NULL)
        {
            cout << "R" << front->right->data << ", ";
            q.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {1, 3, 2, 4, 5, 6, 7};
    bst<int> *root = create(arr, 0, 6);
    output(root);

    return 0;
}