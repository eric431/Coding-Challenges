// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if(list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        else if(list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }  

        map<int, vector<ListNode*>> sortedList;
        while(list1)
        {
            sortedList[list1->val].push_back(list1);
            list1 = list1->next;
        }
        while(list2)
        {
            sortedList[list2->val].push_back(list2);
            list2 = list2->next;
        }
        
        vector<ListNode*> v;
        for(auto itr = sortedList.begin(); itr!=sortedList.end(); itr++)
        {
            v = itr->second;
            for(auto i = 0; i < v.size(); i++)
            {
                if(i < v.size()-1)
                {
                    v[i]->next = v[i+1];
                }
                else if (i == v.size()-1)
                {
                    
                    if(itr != --sortedList.end())
                    {
                        v[i]->next = (++itr)->second[0];
                        --itr;
                    }
                }
            }
        }
        v[v.size()-1]->next = nullptr;
        
        return sortedList.begin()->second[0];
        
    }
};