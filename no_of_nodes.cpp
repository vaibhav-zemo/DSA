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
        cout << "Enter no of childs of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childs;
            cout << "Enter " << i + 1 << "st child of " << front->data << endl;
            cin >> childs;
            Tree<int> *newchild = new Tree<int>(childs);
            q.push(newchild);
            front->child.push_back(newchild);
        }
    }
    return root;
}

void numnode(Tree<int> *root, int &num)
{
    num = num + root->child.size();
    for (int i = 0; i < root->child.size(); i++)
    {
        numnode(root->child[i], num);
    }
}

int numnode_2ndmethod(Tree<int> *root)
{
    int num = 1;
    for (int i = 0; i < root->child.size(); i++)
    {
        num+=numnode_2ndmethod(root->child[i]);
    }
    return num;
}

void output(Tree<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->child.size(); i++)
    {
        cout << root->child[i]->data << ", ";
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
    // output(root);
    static int num = 1;
    numnode(root, num);
    cout << num<<endl;
    cout << numnode_2ndmethod(root);

    return 0;
}