// A non-empty array A consisting of N integers is given.

// The leader of this array is the value that occurs in more than half of the elements of A.

// An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

// For example, given array A such that:

//     A[0] = 4
//     A[1] = 3
//     A[2] = 4
//     A[3] = 4
//     A[4] = 4
//     A[5] = 2
// we can find two equi leaders:

// 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
// 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
// The goal is to count the number of equi leaders.

// Write a function:

// int solution(vector<int> &A);

// that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

// For example, given:

//     A[0] = 4
//     A[1] = 3
//     A[2] = 4
//     A[3] = 4
//     A[4] = 4
//     A[5] = 2
// the function should return 2, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].


// you can use includes, for example:
// #include <algorithm>
#include <queue>
#include <unordered_map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    priority_queue<pair<int, int>> pq_left;
    priority_queue<pair<int, int>> pq_right;

    unordered_map<int, int> left_map;
    unordered_map<int, int> right_map;

    int sentinel_val = numeric_limits<int>::min();
    vector<int> a_left(A.size(), sentinel_val);
    vector<int> a_right(A.size(), sentinel_val);

    int n = A.size() - 1;
    for(int i{0}; i <= n; ++i){
        ++left_map[A[i]];
        ++right_map[A[n - i]];

        pq_left.push({left_map[A[i]], A[i]});
        pq_right.push({right_map[A[n - i]], A[n - i]});

        auto l_t = pq_left.top().second;
        auto r_t = pq_right.top().second;

        double freq_l = static_cast<double>(left_map[l_t]) / (i + 1);
        double freq_r = static_cast<double>(right_map[r_t]) / (i + 1);
        if (freq_l > 0.5) { a_left[i] = l_t; }
        if (freq_r > 0.5) { a_right[n - i] = r_t; }
    }

    int cnt {0};
    for (int i{1}; i <= n; ++i) {
        if ( (a_left[i - 1] == a_right[i]) && (a_right[i] != sentinel_val) ) ++cnt;
    }

    return cnt;
}