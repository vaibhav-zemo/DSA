#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Tree
{
public:
    T data;
    vector<Tree<T> *> child;

    Tree(T data)
    {
        this->data = data;
    }
};

Tree<int> *input()
{
    int r;
    cout << "Enter the root\n";
    cin >> r;
    Tree<int> *root = new Tree<int>(r);
    queue<Tree<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        Tree<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter number of childs of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int child;
            cout << "Enter the " << i + 1 << "st child of " << front->data << endl;
            cin >> child;
            Tree<int> *newchild = new Tree<int>(child);
            q.push(newchild);
            front->child.push_back(newchild);
        }
    }
    return root;
}

int getHeight(Tree<int> *root)
{
    int max = 0;
    for (int i = 0; i < root->child.size(); i++)
    {
        int height = getHeight(root->child[i]);
        if (height > max)
        {
            max = height;
        }
    }
    return max + 1;
}

void output(Tree<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->child.size(); i++)
    {
        cout << root->child[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->child.size(); i++)
    {
        output(root->child[i]);
    }
}

int main()
{
    Tree<int> *root = input();
    output(root);
    int i = getHeight(root);
    cout << i;

    return 0;
}