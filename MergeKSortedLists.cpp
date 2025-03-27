// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.


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
        struct greater_node
        {
            bool operator()(ListNode* a, ListNode* b)
            {
                if (a && b && a->val > b->val)
                {
                    return true;
                }
                return false;
            }
        };
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(!lists.size()) return nullptr;
    
            priority_queue<ListNode*, vector<ListNode*>, greater_node> heap {};
    
            for (auto l : lists)
            {
                if(l) heap.push(l);
            }
    
            if(!heap.size()) return nullptr;
    
            auto dummy_node = heap.top();
            heap.pop();
            auto head = dummy_node;
            while(!heap.empty())
            {
                if(dummy_node && dummy_node->next)
                {
                    heap.push(dummy_node->next);
    
                    dummy_node->next = heap.top();
                }
    
                if(dummy_node)
                {
                    dummy_node->next = heap.top();
                    dummy_node = dummy_node->next;
                }
                heap.pop();
            }
    
            return head;
        }
    };