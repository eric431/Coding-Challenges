/*
We define the following:

A subarray of array  of length  is a contiguous segment from  through  where .
The sum of an array is the sum of its elements.
Given an  element array of integers, , and an integer, , determine the maximum value of the sum of any of its subarrays modulo .

Example


The following table lists all subarrays and their moduli:

		sum	%2
[1]		1	1
[2]		2	0
[3]		3	1
[1,2]		3	1
[2,3]		5	1
[1,2,3]		6	0
The maximum modulus is .

Function Description

Complete the maximumSum function in the editor below.

maximumSum has the following parameter(s):

long a[n]: the array to analyze
long m: the modulo divisor
Returns
- long: the maximum (subarray sum modulo )

Input Format

The first line contains an integer , the number of queries to perform.

The next  pairs of lines are as follows:

The first line contains two space-separated integers  and (long), the length of  and the modulo divisor.
The second line contains  space-separated long integers .
Constraints

 the sum of  over all test cases 
Sample Input

STDIN       Function
-----       --------
1           q = 1
5 7         a[] size n = 5, m = 7
3 3 9 9 5
Sample Output

6
Explanation

The subarrays of array  and their respective sums modulo  are ranked in order of length and sum in the following list:

 and 
 and 






The maximum value for  for any subarray is 
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY a
 *  2. LONG_INTEGER m
 */
long maximumSum(vector<long> a, long m) {
    long maxSum{0};
    vector<long> pSum(a.size());
    vector<long> modSum;
    
    unordered_map<long, vector<long>> mod_idx_map{};
    long cum_sum{0};
    for(auto i = 0; i < a.size(); ++i)
    {
        cum_sum += a[i];
        pSum[i] = cum_sum;
        long m_ = cum_sum % m;
        if(mod_idx_map.count(m_) == 0)
        {
            maxSum = max(maxSum, m_);
            modSum.push_back(m_);
        }
        mod_idx_map[m_].push_back(i);
    }
    sort(modSum.begin(), modSum.end());
    
    long mod_key{0};
    for(auto i = 1; i < pSum.size(); ++i)
    {
        mod_key = (pSum[i] - (m - 1)) % m;
        if(mod_key >= 0)
        {
            auto mod_value = lower_bound(modSum.begin(), modSum.end(), mod_key);
            if(mod_value == modSum.end()) mod_value = modSum.begin();
            if(*mod_value == mod_key && mod_idx_map[*mod_value][0] < i)
            {
                maxSum = m - 1;
                break;
            }
            else 
            {
                while(mod_idx_map[*mod_value][0] >= i)
                {
                    
                    advance(mod_value, 1);
                    if(mod_value == modSum.end())
                    {
                        mod_value = modSum.begin();
                    }
                }
                auto maxSum_i = (pSum[i] - pSum[mod_idx_map[*mod_value][0]]) % m;
                maxSum = max(maxSum, maxSum_i);
            }
        }       
    }
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        long m = stol(first_multiple_input[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

