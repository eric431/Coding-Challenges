// Question:
// A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

// For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

// Write a function:

// int solution(int N);

// that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

// For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..2,147,483,647].


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

vector<int> DecimalToBinary(int N){
    vector<int> binary;
    int rem;

    while(N!=0)
    {
        rem=N%2;
        binary.push_back(rem);

        N=N/2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int solution(int N) {
    // Implement your solution here
    vector<int> Binary_num = DecimalToBinary(N);

    int gap_count = 0;
    int max_count = 0;
    bool eog = false;

    // cout << Binary_num.size() << endl;

    for(auto& el : Binary_num)
    {
        // max_count++;
        if (el==1 && eog==false)
        {
            eog = true;
        }
        else if (el==0 && eog==true)
        {
            gap_count++;
        }
        else if(el==1 && eog==true)
        {
            eog=false;
            if(gap_count>max_count)
            {
                max_count=gap_count;
            }
            gap_count=0;
        }

    }
    return max_count;
}

int main()
{
    vector<int> Binary = DecimalToBinary(5);   

    for 
}
