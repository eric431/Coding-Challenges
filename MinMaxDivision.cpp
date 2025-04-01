
/*
You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
*/

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool min_max_sum(int mid, int K, vector<int> &A) {
    int curr_sum {0};
    int split {0};

    for (auto &a : A) {
        if (curr_sum + a <= mid) {
            curr_sum += a;
        } else {
            curr_sum = a;
            ++split;
        }
    }

    return split < K;
}

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here

    int max_sum {0};
    int min_sum {0};

    for(auto &a : A) {
        max_sum += a;
        min_sum = max(a, min_sum);
    }

    int result {0};
    while(min_sum <= max_sum) {
        int mid = (min_sum + max_sum) / 2;

        if(min_max_sum(mid, K, A)) {
            result = mid;
            max_sum = mid - 1;
        } else {
            min_sum = mid + 1;
        }
    }

    return result;
}