// This is a demo task.

// Write a function:

// int solution(vector<int> &A);

// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

// Given A = [1, 2, 3], the function should return 4.

// Given A = [−1, −3], the function should return 1.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].

// you can use includes, for example:
// #include <algorithm>

#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here

    set<int> A_set(A.begin(), A.end());

    int lowest_pos_int = 1;

    for(auto& el : A_set)
    {
        if(A_set.find(lowest_pos_int)!=A_set.end())
        {
            lowest_pos_int++;
        }
        else
        {
            break;
        }
    }

    return lowest_pos_int;
}
