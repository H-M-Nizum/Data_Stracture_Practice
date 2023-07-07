/*
#####################################
#### Stack implement using Array ####
#####################################
*/

#include <bits/stdc++.h>
using namespace std;
class myStack{
    public:
        vector<int> v;

        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int top(){
            return v.back();
        }

        int size(){
            return v.size();
        }

        bool empty(){
            if (v.size() == 0) return true;
            else return false;
        }
};
int main(){
    myStack st;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while(st.empty() == false){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}


/*
#####################################
#### Stack implement using List  ####
#####################################
*/

#include <bits/stdc++.h>
using namespace std;
class myStack{
    public:
        list<int> l;

        void push(int val){
            l.push_back(val);
        }

        void pop(){
            l.pop_back();
        }

        int top(){
            return l.back();
        }

        int size(){
            return l.size();
        }

        bool empty(){
            if (l.size() == 0) return true;
            else return false;
        }
};
int main(){
    myStack st;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}



/*
###########################################
#### Stack implement using Linked List ####
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
class Node{
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
class myStack{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int sz = 0;

        void push(int val){
            sz++;
            Node *newNode = new Node(val);
            if (head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }

        void pop(){
            sz--;
            Node *deleteNode = tail;
            tail = tail->prev;
            if (tail == NULL){
                head = NULL;
            }
            else{
                tail->next = NULL;
            }

            delete deleteNode;
        }

        int top(){
            return tail->val;
        }

        int size(){
            return sz;
        }

        bool empty(){
            if (sz == 0) return true;
            else return false;
        }
};
int main(){
    myStack st;
    // st.pop();
    // cout << st.top() << endl;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}


/*
#########################################
#### Stack implement using STL stack ####
#########################################
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    
    return 0;
}