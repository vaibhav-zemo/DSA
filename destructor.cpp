#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T> *> children;

    Treenode(T data)
    {
        this->data = data;
    }

    ~Treenode() // better to make a destructor instead of a delete fucntion
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

Treenode<int> *input()
{
    int r;
    cout << "Enter the root\n";
    cin >> r;
    Treenode<int> *root = new Treenode<int>(r);
    queue<Treenode<int> *> nodes;
    nodes.push(root);
    while (nodes.size() != 0)
    {
        Treenode<int> *frontn = nodes.front();
        nodes.pop();
        int n;
        cout << "Enter the number of childerns of " << frontn->data << " node" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int child;
            cout << "Enter " << i + 1 << "th child of " << frontn->data << endl;
            cin >> child;
            Treenode<int> *newchild = new Treenode<int>(child);
            frontn->children.push_back(newchild);
            nodes.push(newchild);
        }
    }
    return root;
}

void print(Treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void delete_tree(Treenode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        delete_tree(root->children[i]);
    }
    delete root;
}

int main()
{

    Treenode<int> *root = input();
    print(root);
    delete root; // our destructor will call here; or we can use delete_tree;

    return 0;
}