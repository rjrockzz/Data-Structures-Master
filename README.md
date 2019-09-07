# :memo: **Data-Structures-Master**
### A Data-Structures implementation session in C , C++ , Java randomly.
### Every Popular Data Structure will be covered. 

##### **__coding bloke__**
1. [Linked Lists Skeletal Structure](https://github.com/rjrockzz/Data-Structures-Master/blob/master/SimpleLinkedLists.c)<br><br>
    - **Advantages over Arrays:**
* Dynamic size
* Ease of insertion/deletion <br><br>
  - **Drawbacks:**<br><br>
* Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists efficiently with its default implementation. Read about it here.
* Extra memory space for a pointer is required with each element of the list.
* Not cache friendly. Since array elements are contiguous locations, there is locality of reference which is not there in case of linked lists.  <br>
See [Linked List vs Arrays](https://github.com/rjrockzz/Data-Structures-Master/blob/master/Linked%20List%20vs%20Arrays) for more.<br><br>
2. [Linked Lists Traversal](https://github.com/rjrockzz/Data-Structures-Master/blob/master/LinkedListsTraversal.c)<br><br>
    Simply printing out the linked lists element using while loop until last node is encountered.
    <br><br>
3. [Linked Lists Insertion](https://github.com/rjrockzz/Data-Structures-Master/blob/master/LinkedListsInsertions.c)<br><br>
     - **At front - 4 step process:**<br>
     - **After given node - 5 step process:**<br>
     - **At end - 6 step process:**<br>[See More](https://github.com/rjrockzz/Data-Structures-Master/blob/master/Linked%20List%20Insertion%20Details)
    <br><br>
4. [Linked Lists Deletion](https://github.com/rjrockzz/Data-Structures-Master/blob/master/Linked%20List%20Deletion%20Details)<br><br>
  - **Keywise** : [See Code](https://github.com/rjrockzz/Data-Structures-Master/blob/master/LinkedListsDeletion.c)<br>
  - **Positionwise** : [See code](https://github.com/rjrockzz/Data-Structures-Master/blob/master/LinkedListsDeletionPosition.c)<br>
<br><br>
5. [Linked Lists Length](https://github.com/rjrockzz/Data-Structures-Master/blob/master/Linked%20Lists%20Length)<br><br>
    - Can be performed [Iteratively](https://github.com/rjrockzz/Data-Structures-Master/blob/master/LinkedListsNodesIteratively.c) or [Recursively](https://github.com/rjrockzz/Data-Structures-Master/blob/master/LinkedListsNodesRecursively.c)
