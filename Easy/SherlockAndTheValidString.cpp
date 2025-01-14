/*
Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times. Given a string , determine if it is valid. If so, return YES, otherwise return NO.

Example

This is a valid string because frequencies are .


This is a valid string because we can remove one  and have  of each character in the remaining string.


This string is not valid as we can only remove  occurrence of . That leaves character frequencies of .

Function Description

Complete the isValid function in the editor below.

isValid has the following parameter(s):

string s: a string
Returns

string: either YES or NO
Input Format

A single string .

Constraints

Each character 
Sample Input

aabbcd
Sample Output

NO
Explanation

 is the minimum number of removals required to make it a valid string. It can be done in following two ways:

Remove c and d to get aabb.
Or remove a and b to get abcd.
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    unordered_map<char, int> c_map{};
    for(auto& el : s)
    {
        ++c_map[el];
    }
    if(c_map.size() == 1) return "YES";
        
    map<int, int> freq_map{};
    for(auto el : c_map)
    {
        ++freq_map[el.second];
        if(freq_map.size() > 2) return "NO";
    }
    
    for(auto el : freq_map) cout << el.first << " " << el.second << endl;
    cout << endl;
    
    if(freq_map.size() == 1) return "YES";
    else if(!(freq_map.rbegin()->second == 1 && (freq_map.rbegin()->first - freq_map.begin()->first) == 1 || (freq_map.begin()->first == 1 && freq_map.begin()->second == 1)))
        return "NO";

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
