// you can use includes, for example:
// #include <algorithm>
#include <map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    map<int, int> leader;
    int N = A.size(), idx = 0;
    for(auto& el : A)
    {
        leader[el]++;
        if (leader[el] > N / 2)
        {
            return idx;
        }
        idx++;
    }
    return -1;
}