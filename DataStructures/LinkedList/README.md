Tùy nhu cầu sử dụng Linked List có thể biến thành Queue, Ring Buffer, Pool memory,.. Linked List có 2 dạng để duyệt list.

Linked List Đơn (Singly Linked List): List chỉ duyệt từ đầu tới đuôi.
Linked List Đôi (Doubly Linked List): List có thể duyệt từ đầu đến đuôi và ngược lại từ đuôi đến đầu.

# Feature
Ease of insertion and deletion
    In lists, inserting or deleting an element at any position other than the end requires shifting all the subsequent items to a different position. 
    adding or removing nodes can be achieved in O(1) time while it took O(n) in link list 
Dynamic size
    In list, resize involves a series of complex operations, including reallocating the array to a new, larger memory block.
Memory efficiency
    This structure leads to better memory utilization since memory for new elements can be allocated as they are added.

Linked lists are most useful when:
    You need to frequently insert and delete many elements
    The data size is unpredictable or likely to change frequently
    Direct access to elements is not a requirement
    The dataset contains large elements or structures

Operations
enqueue (add), dequeue (remove) 
# Problem
Reverse a linked list by just one loop
https://www.geeksforgeeks.org/reverse-a-linked-list/

Reverse a sublist in a linked list
https://www.geeksforgeeks.org/reverse-sublist-linked-list/