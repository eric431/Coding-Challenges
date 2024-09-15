// HACKERRANK //
// Given the pointer to the head node of a doubly linked list, reverse the order of the nodes in place. That is, change the next and prev pointers of the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list.

// Note: The head node might be NULL to indicate that the list is empty.

// Function Description

// Complete the reverse function in the editor below.

// reverse has the following parameter(s):

// DoublyLinkedListNode head: a reference to the head of a DoublyLinkedList
// Returns
// - DoublyLinkedListNode: a reference to the head of the reversed list

// Input Format

// The first line contains an integer , the number of test cases.

// Each test case is of the following format:

// The first line contains an integer , the number of elements in the linked list.
// The next  lines contain an integer each denoting an element of the linked list.
// Constraints

// Output Format

// Return a reference to the head of your reversed list. The provided code will print the reverse array as a one line of space-separated integers for each test case.

// Sample Input

// 1
// 4
// 1
// 2
// 3
// 4
// Sample Output

// 4 3 2 1 
// Explanation

// The initial doubly linked list is: 

// The reversed doubly linked list is: 

// SOLUTION

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
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

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    stack<DoublyLinkedListNode*> reverse_list;
    DoublyLinkedListNode* itr = llist;
    
    reverse_list.push(itr);
    while(itr->next != nullptr)
    {
        itr = itr->next;
        reverse_list.push(itr); 
    }
    itr->prev = nullptr;
    itr->next = reverse_list.top();
    auto reversed_list = itr;
    reverse_list.pop();
    itr = itr->next;
    itr->prev = reversed_list;
    while(!reverse_list.empty())
    {
        auto top = reverse_list.top();
        reverse_list.pop();
        top->prev = itr;
        itr->next = top;        
        itr = itr->next;
    }
    itr->next = nullptr;
    
    return reversed_list;
}