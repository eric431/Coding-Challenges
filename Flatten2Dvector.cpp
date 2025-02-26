class Vector2D {
    vector<int> m_flattened_vec {};
    int m_ptr {};
    int m_sz {};
public:
    Vector2D(vector<vector<int>>& vec) {
        m_ptr = 0;
        m_sz = 0;
        for(auto& el : vec)
            m_flattened_vec.insert(m_flattened_vec.end(), el.begin(), el.end());

        m_sz = m_flattened_vec.size();
    }
    
    int next() {
        return m_flattened_vec[m_ptr++];
    }
    
    bool hasNext() {
        return (m_ptr != m_sz);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Alternative implementation
class Vector2D {
    vector<int> m_flattened_vec {};
    vector<int>::iterator itr = m_flattened_vec.begin();

public:
    Vector2D(vector<vector<int>>& vec) {
        for(auto& el : vec)
            m_flattened_vec.insert(m_flattened_vec.end(), el.begin(), el.end());

        itr = m_flattened_vec.begin();
    }
    
    int next() {
        return *(itr++);
    }
    
    bool hasNext() {
        return (itr != m_flattened_vec.end());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */