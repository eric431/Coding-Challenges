// HACKERRANK

// In an array, , the elements at indices  and  (where ) form an inversion if . In other words, inverted elements  and  are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

// Example


// To sort the array, we must perform the following two swaps to correct the inversions:

// The sort has two inversions:  and .
// Given an array , return the number of inversions to sort the array.

// Function Description

// Complete the function countInversions in the editor below.

// countInversions has the following parameter(s):

// int arr[n]: an array of integers to sort
// Returns

// int: the number of inversions
// Input Format

// The first line contains an integer, , the number of datasets.

// Each of the next  pairs of lines is as follows:

// The first line contains an integer, , the number of elements in .
// The second line contains  space-separated integers, .
// Constraints

// Sample Input

// STDIN       Function
// -----       --------
// 2           d = 2
// 5           arr[] size n = 5 for the first dataset
// 1 1 1 2 2   arr = [1, 1, 1, 2, 2]
// 5           arr[] size n = 5 for the second dataset     
// 2 1 3 1 2   arr = [2, 1, 3, 1, 2]
// Sample Output

// 0  
// 4   
// Explanation

// We sort the following  datasets:

//  is already sorted, so there are no inversions for us to correct.
// We performed a total of  swaps to correct inversions.

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void merge(vector<int>& arr, int l, int r, long& cnt)
{
    int m = (l + r) / 2;
    int size_l = m - l + 1, size_r = r - m;
    vector<int> left_vector(size_l), right_vector(size_r);
    
    int l_itr = l;
    for(auto i = 0; l_itr <= m; ++i, ++l_itr)
    {
        left_vector[i] = arr[l_itr];
    }
    
    int r_itr = m + 1;
    for(auto i = 0; r_itr <= r; ++i, ++r_itr)
    {
        right_vector[i] = arr[r_itr];
    }
    
    int i = 0, j = 0, itr = 0;
    while(i < size_l && j < size_r)
    {
        if(left_vector[i] <= right_vector[j])
        {
            arr[l + itr] = left_vector[i];
            ++i;
        }
        else if(right_vector[j] < left_vector[i])
        {
            cnt += (m + 1 + j) - (l + itr);
            arr[l + itr] = right_vector[j];
            ++j;
        }
        ++itr;
    }
    
    itr = l + itr;
    while(i < size_l)
    {
        arr[itr] = left_vector[i];
        ++i;
        ++itr;
    }
    
    while(j < size_r)
    {
        arr[itr] = right_vector[j];
        ++j;
        ++itr;
    }
}

void merge_sort(vector<int>& arr, int l, int r, long& cnt)
{
    if(l < r)
    {
        if(l < r - 1)
        {
            int m = (l + r) / 2;
            merge_sort(arr, l, m, cnt);
            merge_sort(arr, m + 1, r, cnt);
        }
        merge(arr, l, r, cnt);      
    }
}

long countInversions(vector<int> arr) {
    long cnt = 0;
    int l = 0, r = arr.size() - 1;
    merge_sort(arr, l, r, cnt);
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

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
