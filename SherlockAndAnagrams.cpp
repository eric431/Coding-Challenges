// HACKERRANK 
// Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

// Example

// The list of all anagrammatic pairs is  at positions  respectively.

// Function Description

// Complete the function sherlockAndAnagrams in the editor below.

// sherlockAndAnagrams has the following parameter(s):

// string s: a string
// Returns

// int: the number of unordered anagrammatic pairs of substrings in 
// Input Format

// The first line contains an integer , the number of queries.
// Each of the next  lines contains a string  to analyze.

// Constraints



//  contains only lowercase letters in the range ascii[a-z].

// Sample Input 0

// 2
// abba
// abcd
// Sample Output 0

// 4
// 0
// Explanation 0

// The list of all anagrammatic pairs is  and  at positions  and  respectively.

// No anagrammatic pairs exist in the second query as no character repeats.

// Sample Input 1

// 2
// ifailuhkqq
// kkkk
// Sample Output 1

// 3
// 10
// Explanation 1

// For the first query, we have anagram pairs  and  at positions  and  respectively.

// For the second query:
// There are 6 anagrams of the form  at positions  and .
// There are 3 anagrams of the form  at positions  and .
// There is 1 anagram of the form  at position .

// Sample Input 2

// 1
// cdcd
// Sample Output 2

// 5
// Explanation 2

// There are two anagrammatic pairs of length :  and .
// There are three anagrammatic pairs of length :  at positions  respectively.


// SOLUTION
/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int cnt_pairs(int n)
{
    return (n * (n + 1)) / 2;
}

int sherlockAndAnagrams(string s) {
    int num_pairs = 0;
    map<string, int> anagram_map;
    
    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 0; j <= s.size() - i; j++)
        {
            auto substr = s.substr(j, i);
            sort(substr.begin(), substr.end());
            anagram_map[substr]++;      
        }
    }
    
    for(auto& [k, v] : anagram_map)
    {
        num_pairs += cnt_pairs(v - 1);
    }
    
    return num_pairs;
}