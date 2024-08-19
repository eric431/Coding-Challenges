// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
struct fish
{
    int size; // Size of the fish
    int dir; // Direction the fish is moving 
};

void eat(stack<fish>& f, fish& ref)
{
    if (f.empty()) return;
    auto t = f.top();
    if(t.dir - ref.dir > 0)
    {
        if (t.size - ref.size < 0)
        {
            f.pop();
            eat(f, ref);
        }
        return;
    }
    f.push(ref);
}

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    int N = A.size();
    stack<fish> fishes;
    for(int i = 0; i < N; i++)
    {
        fish fish_i{.size = A[i], .dir = B[i]};
        if (i == 0)
        {
            fishes.push(fish_i);
            continue;
        }
        eat(fishes, fish_i);
    }
    return fishes.size();
}