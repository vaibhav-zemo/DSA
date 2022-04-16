#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
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
            temp->next = n;
            temp = temp->next;
        }

        cin >> i;
    }
    temp->next = head;
    return head;
}

int len(Node *head)
{
    Node *temp = head;
    int count = 1;
    while (temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void output(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;

    } while (temp != head);
    cout << "NULL" << endl;
}

int main()
{
    cout << "Enter the values\n";
    Node *head = input();
    output(head);
    cout<<len(head);

    return 0;
}