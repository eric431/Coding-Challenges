/*

Given an integer , find each  such that:

where  denotes the bitwise XOR operator. Return the number of 's satisfying the criteria.

Example

There are four values that meet the criteria:

Return .

Function Description

Complete the sumXor function in the editor below.

sumXor has the following parameter(s):
- int n: an integer

Returns
- int: the number of values found

Input Format

A single integer, .

Constraints

Subtasks

 for  of the maximum score.
Output Format

Sample Input 0

5
Sample Output 0

2
Explanation 0

For , the  values  and  satisfy the conditions:

Sample Input 1

10
Sample Output 1

4
Explanation 1

For , the  values , , , and  satisfy the conditions:



*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
    bitset<64> n_bs(n);
    bitset<64> ref_(1);
    
    vector<bool> n_bvec{};
    
    while(n_bs.any())
    {
        n_bvec.push_back((n_bs & ref_).any());
        n_bs >>= 1;
    }
    
    bool cnt_flag{false};
    int cnter{0};
    for(int i = n_bvec.size() - 1; i > -1; --i)
    {
        if(!cnt_flag && n_bvec[i] == 1)
        {
            cnt_flag = true;
        }
        else if(cnt_flag && n_bvec[i] == 0)
        {
            ++cnter;
        }
    }
    
    return (1ul << cnter);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
