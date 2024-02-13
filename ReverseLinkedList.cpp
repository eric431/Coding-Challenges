// Given the head of a singly linked list, reverse the list, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000
 

// Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Iterative Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reversedHead = nullptr;
        ListNode* itrHead = head;
        int vl;
        
        while(itrHead != nullptr)
        {
            vl = itrHead->val;
            
            ListNode* newHead = new ListNode;
            newHead->val = vl;
            newHead->next = reversedHead;
            reversedHead = newHead;
            
            itrHead = itrHead->next;
        }
        
        return reversedHead;
    }
};