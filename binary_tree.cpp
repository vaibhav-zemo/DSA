#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class binaryT
{
public:
    T data;
    binaryT<int> *left;
    binaryT<int> *right;

    binaryT(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryT()
    {
        delete left;
        delete right;
    }
};

binaryT<int> *input()
{
    int r;
    cout << "Enter the root\n";
    cin >> r;
    if (r == -1)
    {
        return NULL;
    }
    binaryT<int> *root = new binaryT<int>(r);
    binaryT<int> *node_left = input();
    binaryT<int> *node_right = input();
    root->left = node_left;
    root->right = node_right;
    return root;
}

binaryT<int> *input_level_wise()
{
    int r;
    cout << "Enter the root\n";
    cin >> r;
    if (r==-1)
    {
        return NULL;
    }
    
    binaryT<int> *root = new binaryT<int>(r);
    queue<binaryT<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        binaryT<int> *front = q.front();
        q.pop();

        int left_child;
        cout << "Enter the left child of " << front->data << endl;
        cin >> left_child;
        if (left_child != -1)
        {
            binaryT<int> *leftc = new binaryT<int>(left_child);
            q.push(leftc);
            front->left = leftc;
        }

        int right_child;
        cout << "Enter the right child of " << front->data << endl;
        cin >> right_child;
        if (right_child != -1)
        {
            binaryT<int> *rightc = new binaryT<int>(right_child);
            q.push(rightc);
            front->right = rightc;
        }
    }
    return root;
}

void output(binaryT<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ", ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << ", ";
    }
    cout << endl;

    output(root->left);
    output(root->right);
}

void output_level_wise(binaryT<int> *root)
{

    queue<binaryT<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        binaryT<int> *front = q.front();
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

int count_node(binaryT<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count_node(root->left) + count_node(root->right);
}

void inorder(binaryT<int> *root)
{
    if (root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    // binaryT<int> *root = new binaryT<int>(1);
    // binaryT<int> *node1 = new binaryT<int>(2);
    // binaryT<int> *node2 = new binaryT<int>(3);
    // root->left = node1;
    // root->right = node2;
    binaryT<int> *root = input_level_wise();
    output_level_wise(root);
    // inorder(root);
    delete root;

    return 0;
}