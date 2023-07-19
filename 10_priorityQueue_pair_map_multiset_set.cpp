#include<bits/stdc++.h>
using namespace std;
int main(){


    // ######## Priority Queue #########
    // stl heap.
    // In a time maintain line and priority.
    // priority_queue<data_type> queue_name;
    // Max Heap
    priority_queue<int> pq;
    // push(), pop() :---- O(log(n));
    // top() :---- O(1)

    // min heap
    priority_queue<int, vector<int>, greater<int>> pqqqq; 

    pq.push(5);
    pq.push(2);
    pq.push(1);
    pq.push(2);
    pq.push(1);

    cout<<pq.top()<<endl;

    pq.pop();

    cout<<pq.top()<<endl;


    //##### pair ######
    pair<int, int> p;
    p.first = 10;
    p.second = 20;
    cout<<p.first<<" "<<p.second<<endl;

    // or
    p = make_pair(1, 2);
    cout<<p.first<<" "<<p.second<<endl;
    //or
    p = {5, 6};
    cout<<p.first<<" "<<p.second<<endl;


    // ############ map ###########

    // Maps are associative containers that store elements in a mapped fashion. 
    // Each element has a key value and a mapped value. 
    // No two mapped values can have the same key values.
    /*
    begin() – Returns an iterator to the first element in the map.
    end() – Returns an iterator to the theoretical element that follows the last element in the map.
    size() – Returns the number of elements in the map.
    max_size() – Returns the maximum number of elements that the map can hold.
    empty() – Returns whether the map is empty.
    pair insert(keyvalue, mapvalue) – Adds a new element to the map.
    erase(iterator position) – Removes the element at the position pointed by the iterator.
    erase(const g)– Removes the key-value ‘g’ from the map.
    clear() – Removes all the elements from the map.
    */
    map<int , int> mp;
    mp[10] = 100;
    cout<<mp[10]<<endl;


    // ##################### set vs Multiset #####################
    /*
    set :---- Sets are a type of associative container in 
    which each element has to be unique because the value of the element identifies it. 
    The values are stored in a specific sorted order i.e. either ascending or descending.
    */
    set<int>s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(2);
    for(auto it=s.begin(); it!=s.end(); it++){
        cout<< *it<<" ";
    }
    // output : 1 2 3
    cout<<endl;


    /*
    Multiset :---- Multisets are a type of associative containers similar to the set, 
    with the exception that multiple elements can have the same values. 
    Some Basic Functions associated with multiset: 
        begin() – Returns an iterator to the first element in the multiset –>  O(1)
        end() – Returns an iterator to the theoretical element that follows the last element in the multiset –> O(1)
        size() – Returns the number of elements in the multiset –> O(1)
        max_size() – Returns the maximum number of elements that the multiset can hold –> O(1)
        empty() – Returns whether the multiset is empty –> O(1)
        insert (x) – Inserts the element x in the multiset –> O(log n)
        clear () – Removes all the elements from the multiset –> O(n)
        erase(x) – Removes all the occurrences of x –> O(log n)
    */

    multiset<int>ml;
    ml.insert(3);
    ml.insert(2);
    ml.insert(1);
    ml.insert(3);
    ml.insert(2);
    ml.insert(1);
    ml.insert(2);
    for(auto it=ml.begin(); it!=ml.end(); it++){
        cout<< *it<<" ";
    }
    // output : 1 1 2 2 2 3 3
    cout<<endl;
}