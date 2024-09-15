// HACKERRANK PROBLEM
// Given two strings, determine if they share a common substring. A substring may be as small as one character.

// Example


// These share the common substring .



// These do not share a substring.

// Function Description

// Complete the function twoStrings in the editor below.

// twoStrings has the following parameter(s):

// string s1: a string
// string s2: another string
// Returns

// string: either YES or NO
// Input Format

// The first line contains a single integer , the number of test cases.

// The following  pairs of lines are as follows:

// The first line contains string .
// The second line contains string .
// Constraints

//  and  consist of characters in the range ascii[a-z].
// Output Format

// For each pair of strings, return YES or NO.

// Sample Input

// 2
// hello
// world
// hi
// world
// Sample Output

// YES
// NO
// Explanation

// We have  pairs to check:

// , . The substrings  and  are common to both strings.
// , .  and  share no common substrings.


// SOLUTION
string twoStrings(string s1, string s2) {
    int len = (s1.size() > s2.size()) ? s1.size() : s2.size();
    string larger_string = (s1.size() > s2.size()) ? s1 : s2;    
    
    int len2 = (s1.size() <= s2.size()) ? s1.size() : s2.size();
    string smaller_string = (s1.size() <= s2.size()) ? s1 : s2;
    
    map<char, int> common_substring;
    for(int i = 0; i < len2; i++)
    {
        common_substring[smaller_string[i]] = -1;
    }
    for(int j = 0; j < len; j++)
    {
        if(common_substring[larger_string[j]] == -1)
        {
            return "YES";
        }
    }
    return "NO";
}