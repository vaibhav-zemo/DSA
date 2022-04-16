#include <iostream>
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

class BST
{
public:
    bst<int> *root;

    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool search_helper(int data, bst<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }

        if (root->data == data)
        {
            return true;
        }
        else if (root->data > data)
        {
            return search_helper(data, root->left);
        }
        else if (root->data < data)
        {
            return search_helper(data, root->right);
        }
    }

public:
    bool search(int data)
    {
        return search_helper(data, root);
    }

private:
    bst<int> *insertp(bst<int> *root, int data)
    {
        if (root == NULL)
        {
            bst<int> *node = new bst<int>(data);
            return node;
        }

        if (root->data > data)
        {
            root->left = insertp(root->left, data);
        }
        else
        {
            root->right = insertp(root->right, data);
        }
        return root;
    }

public:
    void insert(int data)
    {
        this->root = insertp(this->root, data);
    }

private:
    bst<int> *deleteData(bst<int> *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (data < root->data)
        {
            root->left = deleteData(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = deleteData(root->right, data);
        }
        else
        {
            if (root->right == NULL && root->left == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->right == NULL)
            {
                bst<int> *node = root->left;
                root->left = NULL;
                delete root;
                return node;
            }
            else if (root->left == NULL)
            {
                bst<int> *node = root->right;
                root->right = NULL;
                delete root;
                return node;
            }
            else
            {
                bst<int> *minterm = root->right;
                while (minterm->left != NULL)
                {
                    minterm = minterm->left;
                }
                root->data = minterm->data;
                root->right = deleteData(root->right, minterm->data);
                return root;
            }
        }
    }

public:
    void deletenode(int data)
    {
        this->root = deleteData(this->root, data);
    }

private:
    void printTree(bst<int> *root)
    {

        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L" << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << "R" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    void print()
    {
        printTree(root);
    }
};

int main()
{

    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.deletenode(100);
    b.deletenode(10);
    b.print();

    return 0;
}