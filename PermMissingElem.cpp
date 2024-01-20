// An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

// Your goal is to find that missing element.

// Write a function:

// int solution(vector<int> &A);

// that, given an array A, returns the value of the missing element.

// For example, given array A such that:

//   A[0] = 2
//   A[1] = 3
//   A[2] = 1
//   A[3] = 5
// the function should return 4, as it is the missing element.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// the elements of A are all distinct;
// each element of array A is an integer within the range [1..(N + 1)].


// you can use includes, for example:
// #include <algorithm>

#include<unordered_map>
#include<vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> B;
    unordered_map<int, int> map_A;
    int result = 0;
    int i=0;
    for(auto& el : A)
    {
        map_A[el] = i;
        i++;
    }

    int len = A.size()+1;
    for(auto j=1; j <= len; j++)
    {
        // B.push_back(j);
        if (!map_A.contains(j))
        {
            result = j;
            break;
        }
    }

    return result;
}