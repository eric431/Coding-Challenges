// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int max_diff = 0, tmp = 0, min_pc = 0;
    for(size_t i = 0; i < A.size(); i++)
    {
        if (i == 0)
        {
            min_pc = A[i];
            continue;
        } 
        if(A[i] < min_pc)
        {
            min_pc = A[i];
        }
        else if (A[i] > min_pc)
        {
            tmp = A[i] - min_pc;
            if (tmp > max_diff)
            {
                max_diff = tmp;
            }
        }
    }

    if(max_diff < 0) return 0;

    return max_diff;
}