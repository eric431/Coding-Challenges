// HACKERRANK 
// Given pointers to the head nodes of  linked lists that merge together at some point, find the node where the two lists merge. The merge point is where both lists point to the same node, i.e. they reference the same memory location. It is guaranteed that the two head nodes will be different, and neither will be NULL. If the lists share a common node, return that node's  value.

// Note: After the merge point, both lists will share the same node pointers.

// Example

// In the diagram below, the two lists converge at Node x:

// [List #1] a--->b--->c
//                      \
//                       x--->y--->z--->NULL
//                      /
//      [List #2] p--->q
// Function Description

// Complete the findMergeNode function in the editor below.

// findMergeNode has the following parameters:

// SinglyLinkedListNode pointer head1: a reference to the head of the first list
// SinglyLinkedListNode pointer head2: a reference to the head of the second list
// Returns

// int: the  value of the node where the lists merge
// Input Format

// Do not read any input from stdin/console.

// The first line contains an integer , the number of test cases.

// Each of the test cases is in the following format:
// The first line contains an integer, , the node number where the merge will occur.
// The next line contains an integer,  that is the number of nodes in the first list.
// Each of the following  lines contains a  value for a node. The next line contains an integer,  that is the number of nodes in the second list.
// Each of the following  lines contains a  value for a node.

// Constraints

// The lists will merge.
// .
//  .

// Sample Input

// The diagrams below are graphical representations of the lists that input nodes  and  are connected to.

// Test Case 0

//  1
//   \
//    2--->3--->NULL
//   /
//  1
// Test Case 1

// 1--->2
//       \
//        3--->Null
//       /
//      1
// Sample Output

// 2
// 3
// Explanation

// Test Case 0: As demonstrated in the diagram above, the merge node's data field contains the integer .
// Test Case 1: As demonstrated in the diagram above, the merge node's data field contains the integer .
// SOLUTION
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    map<SinglyLinkedListNode*, int> merged_node;
    SinglyLinkedListNode* itr1 = head1;
    SinglyLinkedListNode* itr2 = head2;
    auto result = itr1;
    
    while(itr1 != nullptr || itr2 != nullptr)
    {
        if(itr1 != nullptr) 
        {
            if(merged_node[itr1] == 1)
            {
                result = itr1;
                break;
            }
            else
            {
                merged_node[itr1]++;
            }
            itr1 = itr1->next;
        }
        if(itr2 != nullptr) 
        {
            if(merged_node[itr2] == 1)
            {
                result = itr2;
                break;
            }
            else
            {
                merged_node[itr2]++;
            }
            itr2 = itr2->next;
        }
    }
    return result->data;
}