// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here

    stack<pair<int, int>> fishes;
    for(size_t i{0}; i < A.size(); ++i) {
        if (fishes.empty() || B[i] == 1) {
            fishes.push({A[i], B[i]});
            continue;
        }

        while (A[i] > fishes.top().first && fishes.top().second == 1) {
            fishes.pop();
            if (fishes.empty()) break;
        }

        if ( fishes.empty() || (!fishes.empty() && fishes.top().second == B[i]) ) {
            fishes.push({A[i], B[i]});
        }
    }

    return static_cast<int>(fishes.size());
}