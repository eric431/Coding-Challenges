// An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.

// A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.

// For example, consider integer M = 6 and array A such that:

//     A[0] = 3
//     A[1] = 4
//     A[2] = 5
//     A[3] = 5
//     A[4] = 2
// There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

// The goal is to calculate the number of distinct slices.

// Write a function:

// int solution(int M, vector<int> &A);

// that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.

// If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.

// For example, given integer M = 6 and array A such that:

//     A[0] = 3
//     A[1] = 4
//     A[2] = 5
//     A[3] = 5
//     A[4] = 2
// the function should return 9, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// M is an integer within the range [0..100,000];
// each element of array A is an integer within the range [0..M].


// you can use includes, for example:
// #include <algorithm>
#include <unordered_map>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // Implement your solution here

    unordered_map<int, int> ds_map;

    int distinct_slices {0};
    int limit = 1000000000;

    int w_end {0};
    int w_start {0};
    int n = A.size();
    while(w_end < n && w_start < n) {
        if (w_end < n && ds_map[A[w_end]] == 0) {
            distinct_slices += (w_end - w_start + 1);

            if (distinct_slices >= limit) return limit;

            ++ds_map[A[w_end]];
            ++w_end;
        }
        else {
            --ds_map[A[w_start]];
            ++w_start;
        }
    }

    return distinct_slices;
}