/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

 class PeekingIterator : public Iterator {
    public:
        int peek_v;
    
        PeekingIterator(const vector<int>& nums) : Iterator(nums) {
            // Initialize any member here.
            // **DO NOT** save a copy of nums and manipulate it directly.
            // You should only use the Iterator interface methods.
            peek_v = -1;
        }
        
        // Returns the next element in the iteration without advancing the iterator.
        int peek() {
            if(peek_v == -1){
                peek_v = Iterator::next();
            }
    
            return peek_v;
        }
        
        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next() {
            if (peek_v != -1){
                auto nxt = peek_v;
                peek_v = -1;
    
                return nxt;
            }
    
    
            return Iterator::next();
        }
        
        bool hasNext() const {
            if (peek_v != -1){
                return true;
            }
            return Iterator::hasNext();
        }
    };