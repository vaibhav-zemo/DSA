#include <iostream>
#include <queue>
#include <vector>
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

vector<int> *root_to_node(bst<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *output_left = root_to_node(root->left, x);
    if (output_left != NULL)
    {
        output_left->push_back(root->data);
        return output_left;
    }

    vector<int> *output_right = root_to_node(root->right, x);
    if (output_right != NULL)
    {
        output_right->push_back(root->data);
        return output_right;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    bst<int> *root = input();
    vector<int> *ans = root_to_node(root, 5);
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << " ";
    }

    return 0;
}