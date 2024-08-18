// you can use includes, for example:
// #include <algorithm>
// #include <map>
// #include <set>
#include <limits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void min_avg_slice(vector<int>& prefix_sum, int q, int p, pair<float, int>& rst)
{
    float min_buff = float(prefix_sum[q] - (p > 0) * prefix_sum[p - 1]) / (q - p + 1);
    if (min_buff < rst.first)
    {
        rst.first = min_buff;
        rst.second = p;
        // cout << "(" << p << ", " << q << ")" << min << endl;
    }
    else if (min_buff == rst.first)
    {
        if(p < rst.second)
        {
            rst.second = p;
        }    
    }
    
    if (p == 0)
        return;
    min_avg_slice(prefix_sum, q, p - 1, min, min_idx);
}

int solution(vector<int> &A) {
    // Implement your solution here
    int cum_sum = A[0];
    vector<int> prefix_sum(1, cum_sum);
    pair<float, int> min_avg_slc = {std::numeric_limits<float>::max(), 100000}, global_min_avg_slc = {std::numeric_limits<float>::max(), 100000};

    for(size_t q = 1; q < A.size(); q++)
    {
        cum_sum += A[q];
        prefix_sum.push_back(cum_sum);

        min_avg_slice(prefix_sum, q, q - 1, min_avg_slc);
        if (min_avg_slc.first < global_min_avg_slc.first && min_avg_slc.second < global_min_avg_slc.second)
        {
            global_min_avg_slc = min_avg_slc;
            // cout << "(" << global_idx << ", " << q << ")" << global_min << endl;
        }
    }
    return global_min_avg_slc.second;
}