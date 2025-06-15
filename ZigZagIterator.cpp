class ZigzagIterator {
    public:
        int cnt;
        int i;
        int j;
        vector<int> v1;
        vector<int> v2;
    
        ZigzagIterator(vector<int>& v1, vector<int>& v2) {
            i = 0;
            j = 0;
            cnt = 0;
    
            this->v1 = v1;
            this->v2 = v2;
        }
    
        int next() {
            if((cnt % 2 == 0 && i < v1.size()) || (j == v2.size() && i < v1.size())){
                ++cnt;
                return v1[i++];
            } else if ((cnt % 2 && j < v2.size()) || (i == v1.size() && j < v2.size())){
                ++cnt;
                return v2[j++];
            }
            return -1;
        }
    
        bool hasNext() {
            return !(i == v1.size() && j == v2.size());
        }
    };
    
    /**
     * Your ZigzagIterator object will be instantiated and called as such:
     * ZigzagIterator i(v1, v2);
     * while (i.hasNext()) cout << i.next();
     */