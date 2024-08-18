#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int solution(vector<int> T, vector<int> A)
{
    set<int> skills_required;
    stack<int> skills_desired;

    for(size_t i = 0; i < A.size(); i++)
    {
        skills_desired.push(T[A[i]]);
        skills_required.insert(A[i]);
    }

    while(!skills_desired.empty())
    {
        auto t = skills_desired.top();

        if(!skills_required.count(T[t]))
        {
            skills_required.insert(T[t]);
            skills_desired.push(T[t]);
        }
        skills_desired.pop();
    }

    return skills_desired.size();
}