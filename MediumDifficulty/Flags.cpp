// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here   
    if(A.size() == 1) return 0;

    // create a vector of peaks 
    vector<int> peaks{};
    for(size_t i = 1; i < A.size() - 1; ++i)
    {
        if(A[i] > A[i - 1] && A[i] > A[i + 1])
        {
            peaks.push_back(i);
            ++i;
        }
    }

    if(peaks.size() <= 1) return peaks.size();

    // find previous flags 
    int p = peaks.size(); // number of peaks
    int max_flags{0};

    int r = peaks[p - 1] - peaks[0]; // range of flags
    int k = 0; // starting point for number of flags based on peak range and number of flags

    for(int f{1}; f * f <= r; ++f) k = max(k, min(r / f, f));

    for(int k_{k}; k > -1; --k)
    {
        if(k_ < max_flags) break;
        int p_i{peaks[0]};
        int tmp{1};
        while(true)
        {
            p_i += k_;
            auto itr = lower_bound(peaks.begin(), peaks.end(), p_i);
            if(itr == peaks.end()) break;
            else
            {
                p_i = *itr;
                ++tmp;
                if(tmp == k_) break;
            }
        }
        max_flags = max(max_flags, tmp);
    }

    return max_flags;
}