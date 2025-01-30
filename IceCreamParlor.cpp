// Ice Cream Parlor - HACKERRANK

// Each time Sunny and Johnny take a trip to the Ice Cream Parlor, they pool their money to buy ice cream. On any given day, the parlor offers a line of flavors. Each flavor has a cost associated with it.

// Given the value of  and the  of each flavor for  trips to the Ice Cream Parlor, help Sunny and Johnny choose two distinct flavors such that they spend their entire pool of money during each visit. ID numbers are the 1- based index number associated with a . For each trip to the parlor, print the ID numbers for the two types of ice cream that Sunny and Johnny purchase as two space-separated integers on a new line. You must print the smaller ID first and the larger ID second.

// Example



// They would purchase flavor ID's  and  for a cost of . Use  based indexing for your response.

// Note:

// Two ice creams having unique IDs  and  may have the same cost (i.e., ).
// There will always be a unique solution.
// Function Description

// Complete the function whatFlavors in the editor below.

// whatFlavors has the following parameter(s):

// int cost[n] the prices for each flavor
// int money: the amount of money they have to spend
// Prints

// int int: the indices of the two flavors they will purchase as two space-separated integers on a line
// Input Format

// The first line contains an integer, , the number of trips to the ice cream parlor.

// Each of the next  sets of  lines is as follows:

// The first line contains .
// The second line contains an integer, , the size of the array .
// The third line contains  space-separated integers denoting the .
// Constraints

// Sample Input

// STDIN       Function
// -----       --------
// 2           t = 2
// 4           money = 4
// 5           cost[] size n = 5
// 1 4 5 3 2   cost = [1, 4, 5, 3, 2]
// 4           money = 4
// 4           cost[] size n = 4
// 2 2 4 3     cost = [2, 2, 4, 3]
// Sample Output

// 1 4
// 1 2
// Explanation

// Sunny and Johnny make the following two trips to the parlor:

// The first time, they pool together  dollars. There are five flavors available that day and flavors  and  have a total cost of .
// The second time, they pool together  dollars. There are four flavors available that day and flavors  and  have a total cost of .

// SOLUTION

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

void whatFlavors(vector<int> cost, int money) {
    map<int, int> cost_map;
    
    for(auto i = 0; i < cost.size(); ++i)
    {
        cost_map[cost[i]] = i + 1; 
    }
    
    for(auto j = 0; j < cost.size(); ++j)
    {
        if(cost_map[money - cost[j]] != 0)
        {
            if(cost_map[money - cost[j]] == j + 1)
            {
                continue;
            }
            break;
        }
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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


// Solution without map
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

vector<int> icecreamParlor(int m, vector<int> arr) {
    vector<pair<int, int>> arr_pair(arr.size());
    
    for(auto i{0}; i < arr.size(); ++i)
    {
        arr_pair[i] = make_pair(arr[i], i + 1);
    }
    sort(arr_pair.begin(), arr_pair.end());
        
    vector<int> result{};
    
    int i{0};
    int j = arr.size() - 1;
    while(i < j)
    {
        if((arr_pair[i].first + arr_pair[j].first) < m)
        {
            ++i;
        }
        else if((arr_pair[i].first + arr_pair[j].first) > m)
        {
            --j;
        }
        else if ((arr_pair[i].first + arr_pair[j].first) == m)
        {
            result = {arr_pair[i].second, arr_pair[j].second};
            break;
        }
    }
    
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

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

        vector<int> result = icecreamParlor(m, arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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

