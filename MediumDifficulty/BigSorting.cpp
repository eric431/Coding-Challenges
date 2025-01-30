 /*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */ 
 
 vector<string> bigSorting(vector<string> unsorted) {
    map<int, set<string>> str_len_to_size_map{};
    unordered_map<string, int> freq_map{}; // to handle duplicate entries
    for(auto s : unsorted)
    {
        str_len_to_size_map[s.size()].insert(s);
        ++freq_map[s];
    }

    vector<string> sorted_vec{};
    for(auto el : str_len_to_size_map)
    {
        for(auto e : el.second)
        {
            int n = freq_map[e];
    
            for(auto i{0}; i < n; ++i)
            {
                sorted_vec.push_back(e);
            }
        }
    }
    return sorted_vec;
 }