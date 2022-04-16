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
            root->left = leftc;
        }

        int right_child;
        cout << "Enter the right child of " << front->data << endl;
        cin >> right_child;
        if (right_child != -1)
        {
            binaryT<int> *rightc = new binaryT<int>(right_child);
            q.push(rightc);
            root->right = rightc;
        }
    }
    return root;
}

void output(binaryT<int> *root)
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

pair<int, int> height_diameter(binaryT<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> left_h_d = height_diameter(root->left);
    pair<int, int> right_h_d = height_diameter(root->right);
    int lh = left_h_d.first;
    int ld = left_h_d.second;
    int rh = right_h_d.first;
    int rd = right_h_d.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main()
{

    binaryT<int> *root = input();
    pair<int, int> p = height_diameter(root);
    cout << "height" << p.first << endl;
    cout << "diameter" << p.second << endl;
    delete root;

    return 0;
}