// HACKERRANK

// Given an array of integers and a target value, determine the number of pairs of array elements that have a difference equal to the target value.

// Example


// There are three values that differ by : , , and . Return .

// Function Description

// Complete the pairs function below.

// pairs has the following parameter(s):

// int k: an integer, the target difference
// int arr[n]: an array of integers
// Returns

// int: the number of pairs that satisfy the criterion
// Input Format

// The first line contains two space-separated integers  and , the size of  and the target value.
// The second line contains  space-separated integers of the array .

// Constraints

// each integer  will be unique
// Sample Input

// STDIN       Function
// -----       --------
// 5 2         arr[] size n = 5, k =2
// 1 5 3 4 2   arr = [1, 5, 3, 4, 2]
// Sample Output

// 3
// Explanation

// There are 3 pairs of integers in the set with a difference of 2: [5,3], [4,2] and [3,1]. .

// SOLUTION

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pairs(int k, vector<int> arr) {
    map<int, vector<int>> arr_map;
    int num_pairs = 0;
    
    for(auto i = 0; i < arr.size(); ++i)
    {
        arr_map[arr[i]].push_back(i);
    }
    
    int num_tmp;
    for(auto& [key, v] : arr_map)
    {
        num_tmp = key - k;
        if(arr_map.count(num_tmp) != 0)
        {
            ++num_pairs;
        }
    }
        
    return num_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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
