/*
Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

Example


She gives the students candy in the following minimal amounts: . She must buy a minimum of 10 candies.

Function Description

Complete the candies function in the editor below.

candies has the following parameter(s):

int n: the number of children in the class
int arr[n]: the ratings of each student
Returns

int: the minimum number of candies Alice must buy
Input Format

The first line contains an integer, , the size of .
Each of the next  lines contains an integer  indicating the rating of the student at position .

Constraints

Sample Input 0

3
1
2
2
Sample Output 0

4
Explanation 0

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.

Sample Input 1

10
2
4
2
6
1
7
8
9
2
1
Sample Output 1

19
Explanation 1

Optimal distribution will be 

Sample Input 2

8
2
4
3
5
2
6
4
5
Sample Output 2

12
Explanation 2

Optimal distribution will be .
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    if(arr.size() == 1) return 1;
    
    vector<int> candies(n); // candies allocated to each student
    vector<int> min_{};
    vector<int> max_{};
    // identify minimum candy allocated    
    for(auto i{0}; i < n; ++i)
    {
        bool cond_1 = (i == 0 && arr[i] < arr[i + 1]);
        bool cond_2 = (i == n - 1 && arr[i] < arr[i - 1]);
        bool cond_3 = (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]);
      
        if(cond_1 || cond_2 || cond_3)
        {
            candies[i] = 1;
            min_.push_back(i);
        }
    }

    int j = candies.size() - 1;
    int i{0};
    for(; j > -1 && i < candies.size(); ++i, --j)
    {
        bool cond_1 = (i == 0 && candies[i] == 0);
        bool cond_2 = (i > 0 && arr[i] == arr[i - 1]);
        bool cond_3 = (i == n - 1 && arr[i - 1] == arr[i]);
        if(cond_1 || cond_2 || cond_3)
        {
            candies[i] = max(candies[i], 1);        
        }
        else if(i > 0 && arr[i] > arr[i - 1])
        {
            candies[i] = max(candies[i], candies[i - 1] + (arr[i] > arr[i - 1]));   
        }
        
        bool cond_4 = (j == n - 1 && candies[j] == 0);
        bool cond_5 = (j < n - 1 && arr[j] == arr[j + 1]);
        bool cond_6 = (j == 0 && arr[j] == arr[j + 1]);        
        if(cond_4 || cond_5 || cond_6)
        {
            candies[j] = max(candies[j], 1);
        }
        else if(j < n - 1 && arr[j] > arr[j + 1])
        {
            candies[j] = max(candies[j], candies[j + 1] + (arr[j] > arr[j + 1]));   
        }
    }

    long min_candy{0};
    for(auto& el : candies) min_candy += el;
  
    return min_candy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

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
