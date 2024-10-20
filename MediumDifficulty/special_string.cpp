// HACKERANK 

// A string is said to be a special string if either of two conditions is met:

// All of the characters are the same, e.g. aaa.
// All characters except the middle one are the same, e.g. aadaa.
// A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

// Example

//  contains the following  special substrings: .

// Function Description

// Complete the substrCount function in the editor below.

// substrCount has the following parameter(s):

// int n: the length of string s
// string s: a string
// Returns
// - int: the number of special substrings

// Input Format

// The first line contains an integer, , the length of .
// The second line contains the string .

// Constraints


// Each character of the string is a lowercase English letter, .

// Sample Input 0

// 5
// asasd
// Sample Output 0

// 7 
// Explanation 0

// The special palindromic substrings of  are 

// Sample Input 1

// 7
// abcbaba
// Sample Output 1

// 10 
// Explanation 1

// The special palindromic substrings of  are 

// Sample Input 2

// 4
// aaaa
// Sample Output 2

// 10
// Explanation 2

// The special palindromic substrings of  are 

// SOLUTION

#include <bits/stdc++.h>

using namespace std;

long count_all_perms(int n)
{
    return n * (n + 1) / 2;
}

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long cnt = 0;
    int i = 0, j = 0, k = 0;
    char ref_char;
    for(; i < s.size(); ++i)
    {
        if(s[i + 1] == s[i])
        {
            j = i + 1;
            while(s[j] == s[i])
            {
                ++j;
            }
            cnt += count_all_perms(j - i);
            i = j - 1;
            continue;
        }
        else  
        {
            ++cnt;
        }
        if(s[i - 1] == s[i + 1])
        {
            j = i + 1;
            k = i - 1;
            ref_char = s[i - 1];
            
            while(s[j] == ref_char && s[k] == ref_char)
            {
                ++j;
                --k;
                ++cnt;
            }
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
