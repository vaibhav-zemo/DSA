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
};

Treenode<int> *input_in_a_better_way()
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
            cout << "Enter " << i+1 << "th child of " << frontn->data<<endl;
            cin >> child;
            Treenode<int> *newchild = new Treenode<int>(child);
            frontn->children.push_back(newchild);
            nodes.push(newchild);
        }
    }
    return root;
}

Treenode<int> *input()
{
    int r;
    cout << "Enter the root\n";
    cin >> r;
    Treenode<int> *root = new Treenode<int>(r);
    int n;
    cout << "NO of children\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Treenode<int> *child = input();
        root->children.push_back(child);
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

int main()
{
    // Treenode<int> *root = new Treenode<int>(1);
    // Treenode<int> *node1 = new Treenode<int>(2);
    // Treenode<int> *node2 = new Treenode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    Treenode<int> *root = input_in_a_better_way();
    print(root);

    return 0;
}