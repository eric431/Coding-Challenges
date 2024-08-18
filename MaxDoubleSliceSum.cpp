// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int maxc(int a, int b)
{
    return (a >= b) * a + (a < b) * b;
}

int solution(vector<int> &A) {
    // Implement your solution here
    int l = A.size(), max_sum = 0, max_slice = 0;
    bool p_bit = 0;
    pair<int, int> idcs;
    int tmp_first;

    for(int i = 1; i < l - 1; i++)
    {
        max_sum = maxc(0, max_sum + A[i]);  

        if(max_sum != 0 && p_bit == 0)
        {
            p_bit = 1;
            tmp_first = i;
        }
        else if (max_sum == 0) {
            p_bit = 0;
        }

        if(max_sum > max_slice)
        {
            max_slice = max_sum;
            if(p_bit == 1)
            {
                idcs.first = tmp_first;
                idcs.second = i;
            }
        }
    }

    int max = -1, max_tmp = -1;
    for(auto j = idcs.first; j <= idcs.second; j++)
    {
        max_tmp = max_slice - A[j];
        if(max_tmp > max)
        {
            max = max_tmp;
        }
    }

    return max;
}