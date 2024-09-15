// HACKERRANK

// There is a string, , of lowercase English letters that is repeated infinitely many times. Given an integer, , find and print the number of letter a's in the first  letters of the infinite string.

// Example


// The substring we consider is , the first  characters of the infinite string. There are  occurrences of a in the substring.

// Function Description

// Complete the repeatedString function in the editor below.

// repeatedString has the following parameter(s):

// s: a string to repeat
// n: the number of characters to consider
// Returns

// int: the frequency of a in the substring
// Input Format

// The first line contains a single string, .
// The second line contains an integer, .

// Constraints

// For  of the test cases, .
// Sample Input

// Sample Input 0

// aba
// 10
// Sample Output 0

// 7
// Explanation 0
// The first  letters of the infinite string are abaabaabaa. Because there are  a's, we return .

// Sample Input 1

// a
// 1000000000000
// Sample Output 1

// 1000000000000
// Explanation 1
// Because all of the first  letters of the infinite string are a, we return .

// SOLUTION

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    if(s.size() == 1 && s == "a")
    {
        return n;
    }
    else if(s.size() == 1 && s != "a")
    {
        return 0;
    }
    
    long cnt = 0;
    auto end = s.size() > n ? n : s.size();
    for(int i = 0; i < end; i++)
    {
        if(s[i] == 'a') cnt++;
    }
    
    if(end == n) return cnt;
    else
    {
        long rem = n % s.size(), rem_cnt = 0;
        for(long i = 0; i < rem; i++)
        {
            if(s[i] == 'a') rem_cnt++;
        }
        return cnt * (n / s.size()) + rem_cnt;
    }        
}