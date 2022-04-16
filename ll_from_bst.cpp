#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

class Pair
{
public:
    Node *head;
    Node *tail;
};

void output(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << "->";
        head = head->next;
    }
    cout << "NULL";
}

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

Node *ll_to_bst(bst<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *head = new Node(root->data);
    head->next = ll_to_bst(root->right);
    Node *left_n = ll_to_bst(root->left);
    Node *temp = left_n;
    Node *temps = left_n;
    if (left_n != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    if (temp == NULL)
    {
        return head;
    }
    else
    {
        return temps;
    }
}

Pair ll_to_bst2(bst<int> *root)
{
    if (root == NULL)
    {
        Pair node;
        node.head = NULL;
        node.tail = NULL;
        return node;
    }

    Pair node;
    node.head = new Node(root->data);
    Pair rightnode = ll_to_bst2(root->right);
    node.head->next = rightnode.head;
    Pair leftnode = ll_to_bst2(root->left);
    if (leftnode.tail != NULL)
    {
        leftnode.tail->next = node.head;
    }

    Pair output_node;
    if (leftnode.head != NULL)
    {
        output_node.head = leftnode.head;
        output_node.tail = rightnode.tail;
        return output_node;
    }
    else
    {
        return node;
    }
}

int main()
{
    bst<int> *root = input();
    // Node *head = ll_to_bst(root);
    // output(head);
    Pair ans = ll_to_bst2(root);
    output(ans.head);

    return 0;
}