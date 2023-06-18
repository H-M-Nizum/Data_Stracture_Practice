#include <bits/stdc++.h>
using namespace std;
// LInked List Node class.
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Calculate or count size in a linked list.
int size(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// ######################################
//              INSERT
// ######################################

// insert any position in a linked list.
void insert(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    // tmp = pos-1
    newNode->next = tmp->next;
    tmp->next = newNode;
}

// insert Head in a linked list.
void insert_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// insert Tail in linked list.
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


// ################################
//              DELETE
// ################################

// delete any node without head.
void delete_node(Node *head, int pos)
{
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next; // 30
    tmp->next = tmp->next->next;
    delete deleteNode;
}

// delete head.
void delete_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}


// #################################
//            PRINT
// #################################

// Print Linked List Normal way
void print_linekd_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Print Linked List using recursion.
// print normal.
void print_recursion(Node *n)
{
    // base case
    if (n == NULL)
        return;
    cout << n->val << " ";
    print_recursion(n->next);
}
// print reverse.
void print_reverse(Node *n)
{
    // base case
    if (n == NULL)
        return;

    print_reverse(n->next);
    cout << n->val << " ";
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }
    print_linekd_list(head);
    cout<<endl;

    cout<<"print after insert head: ";
    int a;
    cin>>a;
    insert_head(head, a);
    print_linekd_list(head);
    cout<<endl;

    cout<<"print after insert in a random position: ";
    int p, b;
    cin>>p>>b;
    insert(head, p, b);
    print_linekd_list(head);
    cout<<endl;

    cout<<"print after insert tail: ";
    int c;
    cin>>c;
    insert_tail(head, tail, c);
    print_linekd_list(head);
    cout<<endl;

    cout<<"Delete head in linked list: ";
    delete_head(head);
    print_linekd_list(head);
    cout<<endl;

    cout<<"Delete any node in linked list: ";
    int d;
    cin>>d;
    delete_node(head, d);
    print_linekd_list(head);
    cout<<endl;

    cout<<"print size in linked list: "<<size(head)<<endl;


    // ############### SORT ########### //
    for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
    cout<< "sorted linked list: ";
    print_linekd_list(head);
    cout<<endl;
    return 0;
}