#include <iostream>
using namespace std;

class TriesNode
{
public:
    char data;
    TriesNode **children;
    bool terminal;

    TriesNode(char data)
    {
        this->data = data;
        children = new TriesNode *[26];
        terminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Tries
{
    TriesNode *root;

public:
    Tries()
    {
        root = new TriesNode('\0');
    }

    void insertHelper(TriesNode *root, string st)
    {
        if (st.size() == 0)
        {
            root->terminal = true;
            return;
        }

        TriesNode *child;
        int index = st[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TriesNode(st[0]);
            root->children[index] = child;
        }

        insertHelper(child, st.substr(1));
    }

    void insert(string st)
    {
        insertHelper(root, st);
    }

    bool search(TriesNode *root, string st)
    {
        //base case
        if (st.size() == 0)
        {
            return root->terminal;
        }

        //Small calculation
        int index = st[0] - 'a';
        TriesNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        //Recursive call
        return search(child, st.substr(1));
    }

    bool search(string st)
    {
        return search(root, st);
    }

    void remove(TriesNode *root, string word)
    {
        //base case
        if (word.size() == 0)
        {
            root->terminal = false;
            return;
        }

        //small calculation
        TriesNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        //recursive call
        remove(child, word.substr(1));

        //if node is useless
        if (child->terminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void remove(string word)
    {
        remove(root, word);
    }
};

int main()
{
    Tries T;
    T.insert("and");
    T.insert("are");
    T.insert("dot");

    cout << T.search("and") << endl;

    T.remove("and");
    cout << T.search("and") << endl;

    return 0;
}