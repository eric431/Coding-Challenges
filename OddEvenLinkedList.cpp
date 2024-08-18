// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// Example 2:


// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]
 

// Constraints:

// The number of nodes in the linked list is in the range [0, 104].
// -106 <= Node.val <= 106

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        if(head->next == nullptr)
        {
            return head;
        }
        else if (head->next->next == nullptr)
        {
            return head;
        }
        
        vector<ListNode*> odd;
        vector<ListNode*> even;
        ListNode* itrHead = head;

        int it = 1;
        while(itrHead != nullptr)
        {
            if(it%2 == 0)
            {
                even.push_back(itrHead);
            }
            else if(it%2 == 1)
            {
                odd.push_back(itrHead);
            }
            itrHead = itrHead->next;
            it++;
        }
        
        for(auto i = 0; i < odd.size(); i++)
        {
            if(i < odd.size()-1)
            {
                odd[i]->next = odd[i+1];
            }
        }
        for(auto i = 0; i < even.size(); i++)
        {
            if(i < even.size()-1)
            {
                even[i]->next = even[i+1];
            }
            else
            {
                even[i]->next = nullptr;
            }
        }
        
        odd[odd.size()-1]->next = even[0];
        
        return odd[0];
    }
};