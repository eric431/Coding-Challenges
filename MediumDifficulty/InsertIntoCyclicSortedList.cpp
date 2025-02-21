/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head)
        {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        auto add_node = [&](Node* &itr, int insertVal)
        {
            auto tmp = itr->next;
            Node* newNode = new Node(insertVal);

            itr->next = newNode;
            newNode->next = tmp;            
        };
        
        unordered_set<Node*> visited {};

        int i{0};
        int n{0};
        Node* itr = head;
        while(true)
        {
            if(!visited.contains(itr))
            {
                ++n;
                visited.insert(itr);
            }
            else if(visited.contains(itr) && i == n - 1)
            {
                add_node(itr, insertVal);
                
                break;                
            }
            else if(visited.contains(itr))
            {
                ++i;
            }
            
            bool term_1 = itr->val <= insertVal && itr->next->val > insertVal;
            bool term_2 = itr->val == insertVal && itr->next->val != insertVal;
            bool term_3 = itr->val > itr->next->val && (insertVal < itr->next->val || insertVal > itr->val);
            if(term_1 || term_2 || term_3)
            {
                add_node(itr, insertVal);
                
                break;
            }

            itr = itr->next;
        }
        
        return head;
    }
};