#include <vector>
#include <iostream>

using namespace std;


void swap(int a, int b)
{
    auto tmp = move(a);
    a = move(b);
    b = move(a);
}

void Merge(vector<int>& v1, vector<int>& v2)
{
    vector<int> v3;

    if (v2[0] > v1[0])
    {
        v3.push_back(v1[0]);
        v3.push_back(v2[0]);
    }
    else if (v1[0] > v1[0])
    {
        v3.push_back(v2[0]);
        v3.push_back(v1[0]);
    }
}

void MergeSort(vector<int>& v)
{
    int n = v.size()/2;
    vector<int> first_subarray;
    vector<int> second_subarray;

    move(v.begin(), v.begin()+n, first_subarray.begin());
    move(v.begin()+n+1, v.end(), second_subarray.begin());

    if(v.size() == 1)
    {
        Merge();
    }

    if(sorted_vector == prev_sorted)
    {
        return sorted_vector;
    }
    else{
        MergeSort(v); 
    }
}