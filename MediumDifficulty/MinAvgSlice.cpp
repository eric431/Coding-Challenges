// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    size_t size_A = A.size() + 1;
    vector<int> prefix_sums(size_A);
    vector<int> indices{};
    for(size_t i{1}; i < size_A; ++i)
    {
        prefix_sums[i] = A[i - 1] + prefix_sums[i - 1];
        if((i == 1 && A[i - 1] < A[i]) || (i > 1 && A[i - 1] < A[i - 2] && A[i - 1] <= A[i]) || (i == size_A - 2 && A[i - 1] < A[i - 2])) indices.push_back(i);
    }

    double min_avg = numeric_limits<double>::max();
    double tmp{};
    int p{1}, q{2};
    int min_i{0};

    for(size_t i{0}; i < indices.size(); ++i)
    {
        p = indices[i];
        q = indices[i] + 1;

        if(p - 2 > 0 && A[p - 2] < A[q - 1])
        {
            tmp = static_cast<double>(prefix_sums[p] - prefix_sums[p - 2]) / (q - p + 1);
            if(tmp < min_avg)
            {
                min_avg = tmp;
                min_i = p - 2;
            }
        }
        else
        {
            tmp = static_cast<double>(prefix_sums[q] - prefix_sums[p - 1]) / (q - p + 1);
            if(tmp < min_avg)
            {
                min_avg = tmp;
                min_i = p - 1;
            }            
        }

        if(tmp == 0 && A[q] < 0)
        {
            while(q < int(size_A) - 1 && A[q] < tmp)
            {
                ++q;

                tmp = static_cast<double>(prefix_sums[q] - prefix_sums[p - 1]) / (q - p + 1);
                if(tmp < min_avg)
                {
                    min_avg = tmp;
                    min_i = p - 1;
                }
            }
        }
    }

    return min_i;
}