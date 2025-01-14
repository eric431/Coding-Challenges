/*
A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Letters cannot be rearranged. Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

Example



These strings have two children with maximum length 3, ABC and ABD. They can be formed by eliminating either the D or C from both strings. Return .

Function Description

Complete the commonChild function in the editor below.

commonChild has the following parameter(s):

string s1: a string
string s2: another string
Returns

int: the length of the longest string which is a common child of the input strings
Input Format

There are two lines, each with a string,  and .

Constraints

 where  means "the length of "
All characters are upper case in the range ascii[A-Z].
Sample Input

HARRY
SALLY
Sample Output

 2
Explanation

The longest string that can be formed by deleting zero or more characters from  and  is , whose length is 2.

Sample Input 1

AA
BB
Sample Output 1

0
Explanation 1

 and  have no characters in common and hence the output is 0.

Sample Input 2

SHINCHAN
NOHARAAA
Sample Output 2

3
Explanation 2

The longest string that can be formed between  and  while maintaining the order is .

Sample Input 3

ABCDEF
FBDAMN
Sample Output 3

2
Explanation 3
 is the longest child of the given strings.
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    vector<int> rows(s1.size(), 0);
    vector<vector<int>> dp{s1.size(), rows};
    
    int lcs{0};
    for(auto r{0}; r < s2.size(); ++r)
    {
        for(auto c{0}; c < s1.size(); ++c)
        {
            if(r == 0 || c == 0)
            {
                if(r == 0 && c == 0) dp[r][c] = (s2[r] == s1[c]);
                else if(r == 0) dp[r][c] = max(static_cast<int>(s2[r] == s1[c]), dp[r][c - 1]);
                else if(c == 0) dp[r][c] = max(static_cast<int>(s2[r] == s1[c]), dp[r - 1][c]);
            }
            else 
            {
                if(s2[r] == s1[c])
                {
                    int tmp = max(dp[r - 1][c], dp[r][c - 1]);
                    dp[r][c] = max(1 + dp[r - 1][c - 1], tmp);   
                }
                else if(s2[r] != s1[c])
                {
                    dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
                }
            }
            lcs = max(lcs, dp[r][c]);
        }
    }
    
    return lcs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}


