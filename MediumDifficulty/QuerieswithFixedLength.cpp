/*
Consider an -integer sequence, . We perform a query on  by using an integer, , to calculate the result of the following expression:

In other words, if we let , then you need to calculate .

Given  and  queries, return a list of answers to each query.

Example


The first query uses all of the subarrays of length : . The maxima of the subarrays are . The minimum of these is .

The second query uses all of the subarrays of length : . The maxima of the subarrays are . The minimum of these is .

Return .

Function Description

Complete the solve function below.

solve has the following parameter(s):

int arr[n]: an array of integers
int queries[q]: the lengths of subarrays to query
Returns

int[q]: the answers to each query
Input Format

The first line consists of two space-separated integers,  and .
The second line consists of  space-separated integers, the elements of .
Each of the  subsequent lines contains a single integer denoting the value of  for that query.

Constraints

Sample Input

5 5
1 2 3 4 5
1
2
3
4
5
Sample Output

1
2
3
4
5
Explanation

Each prefix has the least maximum value among the consecutive subsequences of the same size.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> min_max;
    min_max.reserve(queries.size());
    
    for(auto &q : queries){
        auto max_itr = max_element(arr.begin(), arr.begin() + q);
        int max_q = *max_itr;
        int min_q = *max_itr;
        for(auto i{1}; i < arr.size() - q + 1; ++i){
            if (arr[i - 1] == max_q){
                max_itr = max_element(arr.begin() + i, arr.begin() + i + q);
                max_q = *max_itr;
            } else {
                max_q = max(arr[i + q], max_q);
            }
            
            min_q = min(min_q, max_q);
        }
        min_max.push_back(min_q);
    }
    
    return min_max;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
