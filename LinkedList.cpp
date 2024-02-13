class MyLinkedList {
public:
    MyLinkedList() {
        
    }
    
    ~MyLinkedList() {
        delete L;
        delete tmp;
    }
    
    int get(int index) {
        if(index < ind_v.size())
        {
            if(ind_v[index] != nullptr)
            {                
                return ind_v[index]->val;
            }            
        }

        return -1;
    }
    
    void addAtHead(int val) {
        if(L->val < 0)
        {
            L->val = val;
        }
        else
        {
            LinkedList* newHead = new LinkedList;
            auto oL = L;
            
            newHead->val = val;
            newHead->next = oL;
            oL->prev = newHead;
            L=newHead;
        }
        
        ind_v.insert(ind_v.begin(), L);
    }
    
    void addAtTail(int val) { 
        if(L->val < 0)
        {
            addAtHead(val);
            return;
        }
        
        LinkedList *newTail = new LinkedList;
        newTail->val = val;
        
        int len = ind_v.size();  
        ind_v.push_back(newTail);
        ind_v[len-1]->next = newTail;
        newTail->prev = ind_v[len-1];

    }
    
    void addAtIndex(int index, int val) {
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        else if(index > ind_v.size())
        {
            return;
        }
        
        LinkedList *indexNode = new LinkedList;   
        indexNode->val = val;
        ind_v[index-1]->next = indexNode;
        
        if(index < ind_v.size())
        {
            indexNode->next = ind_v[index];            
        }

        ind_v.insert(ind_v.begin()+index, indexNode);
        
        indexNode->prev = ind_v[index-1];  
    }
    
    void deleteAtIndex(int index) {
        if(index == 0)
        {
            L = L->next;
            if(L != nullptr)
            {
                L->prev = nullptr;
            }

            if(index < ind_v.size())
            {
                ind_v.erase(ind_v.begin()+index);
            }            
        }
        else
        {
            if(index+1 < ind_v.size())
            {
                ind_v[index-1]->next = ind_v[index+1];
                ind_v[index+1]->prev = ind_v[index-1];
            }

            if(index < ind_v.size())
            {
                ind_v.erase(ind_v.begin()+index);
            }
        }       
    }
    
private:
    struct LinkedList {
        int val;
        LinkedList *prev = nullptr;
        LinkedList *next = nullptr;
    };
    
    LinkedList *L = new LinkedList;
    LinkedList *tmp = new LinkedList;
    vector<LinkedList*> ind_v;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */