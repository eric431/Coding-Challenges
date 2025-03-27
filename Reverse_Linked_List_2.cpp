// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n


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
        ListNode* reverse(ListNode* rhead, ListNode* next_head)
        {
            ListNode* prev = next_head;
            ListNode* curr = rhead;
    
            while(curr->next){
                auto next = curr->next;
                curr->next = prev;
    
                prev = curr;
                curr = next;
            }
    
            curr->next = prev;
    
            return curr;
        }
    
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (left == right) return head;
            auto itr = head;
    
            ListNode* left_node = new ListNode;
            ListNode* rhead = new ListNode;
    
            int pos {1};
    
            if (left == 1) {
                left_node = nullptr;
                rhead = head;
            }
            else {
                while(pos < left - 1){itr = itr->next; ++pos;}
                left_node = itr;
                rhead = left_node->next;
            }
    
            while(pos < right) {itr = itr->next; ++pos;}
            auto right_node = itr->next;
    
            itr->next = nullptr;
    
            auto new_head = reverse(rhead, right_node);
    
            if(left_node) {
                left_node->next = new_head;
    
                return head;
            }
            else {
                return new_head;
            }
        }
    };