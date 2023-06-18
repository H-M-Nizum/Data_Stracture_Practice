// ##### List Built-in Functions: ######

// 1. Constructor

//        Name                              Details                          Time Complexity
// list<type>myList;           Construct a list with 0 elements.                O(1)

// list<type>myList(N);        Construct a list with N elements and             O(N)
//                             the value will be garbage.  

// list<type>myList(N,V);      Construct a list with N elements                  O(N)
//                             and the value will be V.

// list<type>myList(list2);    Construct a list by copying                       O(N)
//                                 another list list2.

// list<type>myList(A,A+N);    Construct a list by copying all elements           O(N)
//                                 from an array A of size N.



// Capacity
	
//     Name                     Details                         Time Complexity

// myList.size()       Returns the size of the list.                    O(1)


// myList.max_size()   Returns the maximum size that the                O(1)
//                         vector can hold.


// myList.clear()      Clears the list elements. Do not delete          O(N)
//                      the memory, only clear the list.


// myList.empty()      Return true/false if the list is empty or not.   O(1)



// myList.resize()    Change the size of the list.                     O(K); where K is the difference 
//                                                                     between new size and current size.


