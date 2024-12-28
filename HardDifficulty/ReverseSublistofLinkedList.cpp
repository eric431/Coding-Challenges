/*
Given a linked list and positions a and b. Reverse the linked list from position a to b and return the head of the resultant linked list.

Examples:

Input: a = 1, b = 8, Linked List = 1->7->5->3->9->8->10->2->2->5->NULL
Output: 2 10 8 9 3 5 7 1 2 5

Explanation: The nodes from position 1 to 8 are reversed, resulting in 2 10 8 9 3 5 7 1 2 5.
Input: a = 2, b = 4, Linked List = 1->2->3->4->5->6->NULL
Output: 1 4 3 2 5 6

Explanation: Nodes from position 2 to 4 are reversed resulting in 1 4 3 2 5 6.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
 
Constraints:
1<= size of linked list <=10^5
1<= a<=b<= size of linked list
1<= data of nodes <=109


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        
        if(a == b)
            return head;
        
        auto reverse = [&](Node* nodeHead, Node* nodeTail)
        {
            auto currHead = nodeHead;
            
            while(currHead)
            {
               auto tmp = currHead->next;
               currHead->next = nodeTail;
               
               nodeTail = currHead;
               currHead = tmp;
            }
            
            return nodeTail;
        };
        
        int itr{0};
        auto itrHead = head;
        Node* revHead = nullptr;
        Node* revTail = nullptr;
        Node* prevHead = nullptr;
        Node* prevItrHead = nullptr;
        
        while(itrHead)
        {
            ++itr;
            
            if(itr == a)
            {
                prevHead = prevItrHead;
                revHead = itrHead;
            }
            else if(itr == b)
            {
                revTail = itrHead->next;
                
                if(prevHead) prevHead->next = nullptr;
                itrHead->next = nullptr;
                
                break;
            }
            
            prevItrHead = itrHead;
            itrHead = itrHead->next;
        }
        
        auto newRevHead = reverse(revHead, revTail);
        
        if(prevHead)
        {
            prevHead->next = newRevHead;
            return head;
        }
        else if(!prevHead)
        {
            return newRevHead;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int a = arr[0], b = arr[1];

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        if (arr2.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr2[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr2.size(); ++i) {
            data = arr2[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* newhead = ob.reverseBetween(a, b, head);
        printList(newhead);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends