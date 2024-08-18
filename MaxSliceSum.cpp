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
    int max = 0, max_neg = -2147483648;
    for(int i = 0; i < l; i++)
    {
        max_slice = maxc(0, max_sum + A[i]);
        max_sum = max_slice;
        if(max_sum > max)
        {
            max = max_sum;
        }
        if(max == 0)
        {
            if(A[i] > max_neg)
            {
                max_neg = A[i];
            }
        }
    }
    if(max == 0) return max_neg;
    return max;
}