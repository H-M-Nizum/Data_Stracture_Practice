#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
Node *input_tree(){
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty()){
        // 1. ber kore ano
        Node *p = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. children gulo ke push koro
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
void level_order(Node *root){
    if (root == NULL){
        cout << "Tree nai" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        cout << f->val << " ";

        // 3. tar children gulo ke rakha
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}



//############# Search ##########
bool search(Node *root, int x){
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (x < root->val)
        return search(root->left, x);
    else
        return search(root->right, x);
}


// ################## Insert in a Binary search tree ##############
void insert(Node *&root, int x){
    if (root == NULL){
        root = new Node(x);
        return;
    }
    if (x < root->val){
        if (root->left == NULL){
            root->left = new Node(x);
        }
        else{
            insert(root->left, x);
        }
    }
    else{
        if (root->right == NULL){
            root->right = new Node(x);
        }
        else{
            insert(root->right, x);
        }
    }
}



//################# Convert Array to BST ##############
Node *convert(int a[], int n, int l, int r){
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(a[mid]);
    Node *leftRoot = convert(a, n, l, mid - 1);
    Node *rootRight = convert(a, n, mid + 1, r);
    root->left = leftRoot;
    root->right = rootRight;
    return root;
}

int main(){
    Node *root = input_tree();
    if (search(root, 100))
        cout << "Yes, Found" << endl;
    else
        cout << "No, Not Found" << endl;
    return 0;
}