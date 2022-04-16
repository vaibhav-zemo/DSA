#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Pair
{
public:
    Node *head;
    Node *tail;
};

Node *input()
{
    int i;
    cin >> i;
    Node *head = NULL;
    Node *temp = NULL;
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
    return head;
}

int mid(Node *head, int n)
{
    Node *slow = head;
    Node *fast = head;
    if (n % 2 != 0)
    {
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
    else
    {
        while (fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
}

Node *merge_sorted_list(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *temp = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head == NULL)
        {
            if (head1->data > head2->data)
            {
                head = head2;
                temp = head2;
                head2 = head2->next;
            }
            else
            {
                head = head1;
                temp = head1;
                head1 = head1->next;
            }
        }
        else
        {
            if (head1->data > head2->data)
            {
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
            else
            {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
        }
    }

    while (head1 != NULL)
    {
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    return head;
}

int len(Node *head)
{
    int count = 1;
    while (head->next != NULL)
    {
        head = head->next;
        count++;
    }

    return count;
}

Node *merge_sorting(Node *head)
{
    int l = len(head);
    int mid = l / 2;
    if (mid == 0)
    {
        return head;
    }

    Node *temp = head;
    int count = 1;
    Node *head1 = head;
    Node *head2 = NULL;

    while (count != mid)
    {
        temp = temp->next;
        count++;
    }
    head2 = temp->next;
    temp->next = NULL;

    Node *newhead1 = merge_sorting(head1);
    Node *newhead2 = merge_sorting(head2);
    return merge_sorted_list(newhead1, newhead2);
}

Node *reverse(Node *head)
{
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *reverse_rec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newhead = reverse(head->next);

    Node *temp = newhead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return newhead;
}

Node *reverse_rec_3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newhead = reverse_rec_3(head->next);

    Node*tail = head->next;
    tail->next = head;    // or head->next->next = head
    head->next = NULL;
    return newhead;
}

Pair reverse_rec_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverse_rec_2(head->next);

    smallans.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}

Node*reverse_rec_better(Node*head){
    return reverse_rec_2(head).head;
}

void print(Node *head)
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
    cout << "Enter the values of 1st list\n";
    Node *head1 = input();
    print(head1);
    // Node *newhead = merge_sorting(head1);
    // print(newhead);

    // cout << len(head1) << endl;
    Node *newhead = reverse_rec_3(head1);
    print(newhead);
    // cout << "Enter the values of 2nd list\n";
    // Node *head2 = input();
    // Node *newhead = merge_sorted_list(head1, head2);
    // print(newhead);

    return 0;
}