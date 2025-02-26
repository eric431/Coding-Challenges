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


// ALTERNATIVELY

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1) return head2;
    else if (!head2) return head1;

    auto itr1 = head1;
    auto itr2 = head2;
    SinglyLinkedListNode* mergedHead = nullptr;
    auto newHead = mergedHead;
    while(itr1 && itr2)
    {
        if(itr1->data <= itr2->data)
        {
            if(!mergedHead)
            {
                mergedHead = new SinglyLinkedListNode(itr1->data);
                newHead = mergedHead; 
            }
            else mergedHead->data = itr1->data;
            
            itr1 = itr1->next;
        }
        else {
            if(!mergedHead)
            {
                mergedHead = new SinglyLinkedListNode(itr2->data);  
                newHead = mergedHead;  
            }
            else mergedHead->data = itr2->data;    
            
            itr2 = itr2->next;        
        }
        
        mergedHead->next = new SinglyLinkedListNode(0);
        mergedHead = mergedHead->next;
    }

    if(itr1)
    {
        mergedHead->data = itr1->data;
        mergedHead->next = itr1->next;
    }
    else if(itr2)
    {
        mergedHead->data = itr2->data;
        mergedHead->next = itr2->next;        
    }
    else if(!itr1 && !itr2)
    {
        mergedHead = nullptr;
    }

    return newHead;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
