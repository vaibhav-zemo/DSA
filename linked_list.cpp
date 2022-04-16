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
    int i;
    cin >> i;
    while (i != -1)
    {
        Node *n = new Node(i);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

        cin >> i;
    }
    return head;
}

Node *input_better()
{
    Node *head = NULL;
    Node *tail = NULL;
    int i;
    cout << "Enter the values\n";
    cin >> i;
    while (i != -1)
    {
        Node *n = new Node(i);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
            // or
            // tail = newNode
        }

        cin >> i;
    }
    return head;
}

Node *insert(Node *head, int pos, int data)
{
    Node *temp = head;
    Node *n = new Node(data);
    if (pos == 0)
    {
        n->next = head;
        head = n; // here our head is changed so we have to return new head
        return head;
    }

    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        n->next = temp->next;
        temp->next = n;
    }
    return head;
}

Node *insert_recursively(Node *head, int data, int pos)
{
    Node *n = new Node(data);
    if (pos == 0)
    {
        n->next = head;
        return n;
    }

    if (pos == 1)
    {
        head->next = n;
        return head;
    }

    if (pos == 2 && head->next->next!=NULL)
    {
        n->next = head->next;
        head->next = n;
        return head;
    }

    insert_recursively(head->next, data, pos - 1);
    return head;
}

Node *delete_recursively(Node *head, int pos)
{
    if (pos==0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    if (pos == 2)
    {
        Node*temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;
    }

    if (pos==2 && head->next->next==NULL)
    {
        Node*temp = head->next;
        head->next=NULL;
        delete temp;
        return head;
    }
    

    delete_recursively(head->next, pos - 1);
    return head;
}

Node *delete_at_i(Node *head, int i)
{
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 1;
    Node *temp2 = head;
    while (temp2 != NULL && count < i - 1)
    {
        temp2 = temp2->next;
        count++;
    }

    if (temp2->next->next == NULL)
    {
        Node *dele = temp2->next;
        delete dele;
        temp2->next = NULL;
    }
    else
    {
        Node *dele = temp2->next;
        delete dele;
        temp2->next = temp2->next->next;
    }
    return head;
}

int len(Node *head)
{
    Node *temp = head;
    int counter = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

int mid_ele(Node *head)
{
    int l = len(head);
    int mid = (l - 1) / 2;
    Node *temp = head;
    int counter = 1;
    while (counter <= mid)
    {
        temp = temp->next;
        counter++;
    }
    return temp->data;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *head = input_better();
    print(head);
    // Node *newhead = insert_recursively(head, 45, 5);
    // print(newhead);
    Node*newhead2 = delete_recursively(head,4);
    print(newhead2);

    return 0;
}