// HACKERRANK
// Given a reference to the head of a doubly-linked list and an integer, , create a new DoublyLinkedListNode object having data value  and insert it at the proper location to maintain the sort.

// Example

//  refers to the list 

// Return a reference to the new list: .

// Function Description

// Complete the sortedInsert function in the editor below.

// sortedInsert has two parameters:

// DoublyLinkedListNode pointer head: a reference to the head of a doubly-linked list

// int data: An integer denoting the value of the  field for the DoublyLinkedListNode you must insert into the list.

// Returns

// DoublyLinkedListNode pointer: a reference to the head of the list
// Note: Recall that an empty list (i.e., where ) and a list with one element are sorted lists.

// Input Format

// The first line contains an integer , the number of test cases.

// Each of the test case is in the following format:

// The first line contains an integer , the number of elements in the linked list.
// Each of the next  lines contains an integer, the data for each node of the linked list.
// The last line contains an integer, , which needs to be inserted into the sorted doubly-linked list.
// Constraints

// Sample Input

// STDIN   Function
// -----   --------
// 1       t = 1
// 4       n = 4
// 1       node data values = 1, 3, 4, 10
// 3
// 4
// 10
// 5       data = 5
// Sample Output

// 1 3 4 5 10
// Explanation

// The initial doubly linked list is:  .

// The doubly linked list after insertion is: 
// SOLUTION
/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if(data < llist->data)
    {
        DoublyLinkedListNode* newHead = new DoublyLinkedListNode(data);
        newHead->next = llist;
        newHead->prev = nullptr;
        llist->prev = newHead;
        return newHead;
    }
    
    auto itr = llist;
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data); 
    while(itr)
    {
        if(data <= itr->data)
        {
            itr->prev->next = newNode;
            newNode->prev = itr->prev;
            newNode->next = itr;
            itr->prev = newNode;
            break;
        }
        else if(data > itr->data && !itr->next)
        {
            itr->next = newNode;
            newNode->prev = itr;
            newNode->next = nullptr;
            break;
        }
        itr = itr->next;
    }
    return llist;
}