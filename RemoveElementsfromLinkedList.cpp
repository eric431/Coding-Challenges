// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

// Example 1:


// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50


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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
        {
            return head;
        }
        else if(head->next == nullptr && head->val != val)
        {
            return head;
        }
        else if(head->next == nullptr && head->val == val)
        {
            return nullptr;
        }
        
        vector<ListNode*> newList;
        ListNode* itrHead = head;
        
        while(itrHead != nullptr)
        {
            if(itrHead->val != val)
            {
                newList.push_back(itrHead);
            }
            
            itrHead = itrHead->next;
        }
        
        if(newList.size() < 1)
        {
            return nullptr;
        }
        
        for(auto it = 0; it < newList.size(); it++)
        {
            if(it < newList.size()-1)
            {
                newList[it]->next = newList[it+1];
            }
            else
            {
                newList[it]->next = nullptr;
            }
        }

        return newList[0];
    }
};