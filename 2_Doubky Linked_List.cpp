#include <bits/stdc++.h>
using namespace std;
// LInked List Node class.
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
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
void insert_at_position(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;     
    tmp->next = newNode;           
    newNode->next->prev = newNode; 
    newNode->prev = tmp;           
}

// insert Head in a linked list.
void insert_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// insert Tail in linked list.
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}


// ################################
//              DELETE
// ################################

// delete any position in a node.
void delete_at_position(Node *head, int pos)
{
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

// delete head.
void delete_head(Node *&head, Node *&tail)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}


// delete tail.
void delete_tail(Node *&head, Node *&tail)
{
    Node *deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    if (tail == NULL)
    {
        head = NULL;
        return;
    }
    tail->next = NULL;
}

// #################################
//            PRINT
// #################################

// Print Linked List Normal way
void print_normal(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


// print reverse.

void print_reverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
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
    cout<<"normal print link list: ";
    print_normal(head);
    cout<<endl;
    cout<<"reverse print link list: ";
    print_reverse(tail);
    cout<<endl;

    cout<<"print after insert head: ";
    int a;
    cin>>a;
    insert_head(head, tail, a);
    print_normal(head);
    cout<<endl;

    cout<<"print after insert in a random position: ";
    int p, b;
    cin>>p>>b;
    insert_at_position(head, p, b);
    print_normal(head);
    cout<<endl;

    cout<<"print after insert tail: ";
    int c;
    cin>>c;
    insert_tail(head, tail, c);
    print_normal(head);
    cout<<endl;

    cout<<"Delete head in linked list: ";
    delete_head(head, tail);
    print_normal(head);
    cout<<endl;

    cout<<"Delete any position in linked list: ";
    int d;
    cin>>d;
    delete_at_position(head, d);
    print_normal(head);
    cout<<endl;

    cout<<"Delete tail in linked list: ";
    delete_tail(head, tail);
    print_normal(head);
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
    print_normal(head);
    cout<<endl;
    return 0;
}



// // ############ Error Handling ######### //
// int main()
// {
//     Node *head = new Node(10);
//     Node *tail = head;

//     // connection

//     int pos;
//     cin >> pos;

//     if (pos >= size(head))
//     {
//         cout << "Invalid" << endl;
//     }
//     else if (pos == 0)
//     {
//         delete_head(head, tail);
//     }
//     else if (pos == size(head) - 1)
//     {
//         delete_tail(head, tail);
//     }
//     else
//     {
//         delete_at_position(head, pos);
//     }

//     print_normal(head);
//     print_reverse(tail);
//     return 0;
// }


