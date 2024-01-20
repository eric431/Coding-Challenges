// A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars on a road.

// Array A contains only 0s and/or 1s:

// 0 represents a car traveling east,
// 1 represents a car traveling west.
// The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 ≤ P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.

// For example, consider array A such that:

//   A[0] = 0
//   A[1] = 1
//   A[2] = 0
//   A[3] = 1
//   A[4] = 1
// We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

// Write a function:

// int solution(vector<int> &A);

// that, given a non-empty array A of N integers, returns the number of pairs of passing cars.

// The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.

// For example, given:

//   A[0] = 0
//   A[1] = 1
//   A[2] = 0
//   A[3] = 1
//   A[4] = 1
// the function should return 5, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer that can have one of the following values: 0, 1.


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here

    vector<int> east_tracker;
    vector<int> west_tracker;
    vector<pair<int, int>> result;

    int len = A.size();
    for(int i=0; i<len; i++)
    {
        if(A[i] == 0)
        {
            east_tracker.push_back(i);
        }
        else if(A[i] == 1)
        {
            west_tracker.push_back(i);
        }
    }

    for(auto& east_key : east_tracker)
    {
        for(auto& west_key : west_tracker)
        {
            if(east_key < west_key)
            {
                result.push_back(make_pair(east_key, west_key));
            }
            else
            {
                continue;
            }
        }
    }

    int pair_length = result.size();
    if (pair_length > 1000000)
    {
        return -1;
    }
    else
    {
        return pair_length;
    }
}
