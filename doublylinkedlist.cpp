#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *input()
{
    Node *head = NULL;
    Node *temp = NULL;
    int i;
    cin >> i;
    while (i != -1)
    {
        Node *n = new Node(i);
        if (head == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {
            n->prev = temp;
            temp->next = n;
            temp = temp->next;
        }

        cin >> i;
    }
    return head;
}

Node *insert(Node *head, int pos, int data)
{
    Node *n = new Node(data);
    if (pos == 1)
    {
        n->next = head;
        head->prev = n;
        head = n;
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next->next == NULL)
    {
        temp = temp->next;
        n->next = NULL;
        n->prev = temp;
        temp->next = n;
    }
    else
    {
        n->next = temp->next;
        temp->next->prev = n;
        n->prev = temp;
        temp->next = n;
    }

    return head;
}

Node *delete_at_i(Node *head, int pos)
{
    if (pos == 1)
    {
        Node *todelete = head;
        head = head->next;
        head->prev = NULL;
        delete todelete;
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next->next == NULL)
    {
        Node *todelete = temp->next;
        temp->next = NULL;
        delete todelete;
        return head;
    }
    else
    {
        Node *todelete = temp->next;
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        delete todelete;
        return head;
    }
}

void output(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    cout << "Enter the values\n";
    Node *head = input();
    output(head);
    cout << "Enter the position\n";
    int *pos = new int;
    cin >> *pos;
    Node *newhead = delete_at_i(head, *pos);
    output(newhead);

    return 0;
}