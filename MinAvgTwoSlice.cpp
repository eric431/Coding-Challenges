// A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

// For example, array A such that:

//     A[0] = 4
//     A[1] = 2
//     A[2] = 2
//     A[3] = 5
//     A[4] = 1
//     A[5] = 5
//     A[6] = 8
// contains the following example slices:

// slice (1, 2), whose average is (2 + 2) / 2 = 2;
// slice (3, 4), whose average is (5 + 1) / 2 = 3;
// slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
// The goal is to find the starting position of a slice whose average is minimal.

// Write a function:

// int solution(vector<int> &A);

// that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

// For example, given array A such that:

//     A[0] = 4
//     A[1] = 2
//     A[2] = 2
//     A[3] = 5
//     A[4] = 1
//     A[5] = 5
//     A[6] = 8
// the function should return 1, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [2..100,000];
// each element of array A is an integer within the range [−10,000..10,000].


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here

    vector<int> P(A.size() + 1);
    for (size_t i{1}; i < P.size(); ++i) { P[i] = A[i - 1] + P[i - 1]; }

    double min_avg = numeric_limits<double>::max();
    double curr_avg_2;
    double curr_avg_3;
    
    int start_index = 0;
    for (size_t i{2}; i < P.size(); ++i) {
        if (i > 2){
            curr_avg_3 = static_cast<double>(P[i] - P[i - 3]) / 3;
            if (curr_avg_3 < min_avg) {
                min_avg = curr_avg_3;
                start_index = i - 3;
            }
        }

        curr_avg_2 = static_cast<double>(P[i] - P[i - 2]) / 2;
        if (curr_avg_2 < min_avg) {
            min_avg = curr_avg_2;
            start_index = i - 2;
        }
    }

    return start_index;
}