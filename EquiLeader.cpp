// you can use includes, for example:
// #include <algorithm>
#include <map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int count = 0, N = A.size();
    map<int, map<int, int>> el_trk2;

    for(int s = 0; s < N; s++)
    {
        el_trk2[A[s]][s + 1] = el_trk2[A[s]].size() + 1;
    }

    int idx, el, el_len;
    float check1, check2;
    for(int j = 0; j < N - 1; j++)
    {
        map<int, int>& ref = el_trk2[A[j]];
        el = j + 1, el_len = ref.size();
        idx = ref[el] - 1;
        check1 = float(idx) / el;
        check2 = float(el_len - idx) / (N - el);
        if(check1 >  0.5 && check2 > 0.5)
        {
            count++;
        }
    }
    return count;
}