// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// Follow-up: Can you solve the problem in O(1) extra memory space?

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
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head) return nullptr;
    
            vector<ListNode*> list_vec {};
    
            for(auto itr = head; itr; itr = itr->next)
            {
                list_vec.push_back(itr);
            }
    
            for(auto i = 0; i < list_vec.size(); i += k)
            {
                if(i + k <= list_vec.size()) reverse(list_vec.begin() + i, list_vec.begin() + i + k);
            }
    
            int i {0};
            for(; i < list_vec.size() - 1; ++i)
            {
                list_vec[i]->next = list_vec[i + 1];
            }
            list_vec[i]->next = nullptr;
    
            return list_vec[0];
        }
    };