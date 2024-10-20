/*

You are given an array and you need to find number of tripets of indices  such that the elements at those indices are in geometric progression for a given common ratio  and .

Example
 

There are  and  at indices  and . Return .

Function Description

Complete the countTriplets function in the editor below.

countTriplets has the following parameter(s):

int arr[n]: an array of integers
int r: the common ratio
Returns

int: the number of triplets
Input Format

The first line contains two space-separated integers  and , the size of  and the common ratio.
The next line contains  space-seperated integers .

Constraints

Sample Input 0

4 2
1 2 2 4
Sample Output 0

2
Explanation 0

There are  triplets in satisfying our criteria, whose indices are  and 

Sample Input 1

6 3
1 3 9 9 27 81
Sample Output 1

6
Explanation 1

The triplets satisfying are index , , , ,  and .

Sample Input 2

5 5
1 5 5 25 125
Sample Output 2

4
Explanation 2

The triplets satisfying are index , , , .

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


struct Node
{
    long val;
    long p_branches = 0;
    long c_branches = 0;
    
    Node(int x) : val(x) {}
    
    long num_triplets()
    {
        return p_branches * c_branches;
    }
};

long choose(long n)
{
    long lower_limit = n - 3, permutation = 1;
    while(n > lower_limit)
    {
        permutation *= n;
        --n;
    }
    return permutation / 6; // 6 represents the 3! 
}

// Complete the countTriplets function below.
long countTriplets(vector<long>& arr, long r) {
    if(r == 1)
    {
        map<int, int> trp_map;
        
        for(auto num : arr)
        {
            ++trp_map[num];
        }
        
        long cnt = 0, n = 0;
        for(auto const &el : trp_map)
        {
            n = long(el.second);
            cnt += choose(n);
        }
        return cnt;
    }
    
    map<int, vector<Node*>> node_map;
    long num_triplets = 0;
    for(auto i = 0; i < arr.size(); ++i)
    {
        Node* n1 = new Node(arr[i]);
        node_map[arr[i]].push_back(move(n1));
                    
        if(arr[i] % r == 0)
        {   
            long num = arr[i] / r;
            if(node_map.count(num) != 0)
            {
                n1->p_branches = node_map[num].size();
                for(auto el : node_map[num])
                {
                    el->c_branches++;
                }
            }
        }
    }
    
    for(auto el : node_map)
    {
        for(auto el2 : el.second)
        {
            num_triplets += el2->num_triplets();
        }
    }
        
    return num_triplets;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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
