/*
Palindromes are strings that read the same from the left or right, for example madam or 0110.

You will be given a string representation of a number and a maximum number of changes you can make. Alter the string, one digit at a time, to create the string representation of the largest number possible given the limit to the number of changes. The length of the string may not be altered, so you must consider 's left of all higher digits in your tests. For example  is valid,  is not.

Given a string representing the starting number, and a maximum number of changes allowed, create the largest palindromic string of digits possible or the string '-1' if it is not possible to create a palindrome under the contstraints.

Example


Make  replacements to get .



Make  replacement to get .

Function Description

Complete the highestValuePalindrome function in the editor below.

highestValuePalindrome has the following parameter(s):

string s: a string representation of an integer
int n: the length of the integer string
int k: the maximum number of changes allowed
Returns

string: a string representation of the highest value achievable or -1
Input Format

The first line contains two space-separated integers,  and , the number of digits in the number and the maximum number of changes allowed.
The second line contains an -digit string of numbers.

Constraints

Each character  in the number is an integer where .
Output Format

Sample Input 0

STDIN   Function
-----   --------
4 1     n = 4, k = 1
3943    s = '3943'
Sample Output 0

3993
Sample Input 1

6 3
092282
Sample Output 1

992299
Sample Input 2

4 1
0011
Sample Output 2

-1
Explanation

Sample 0

There are two ways to make  a palindrome by changing no more than  digits:
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {    
    vector<pair<int, int>> chars{};
    for(int l{0}, r = s.size() - 1; l <= r; ++l, --r){
        if(s[l] != s[r]) { chars.push_back({l, r}); }
    }
    
    int c = chars.size();
    if (c > k) {
        return to_string(-1);
    } else if (c == k) {
        for(auto &[l, r] : chars){ s[l] = s[r] = max(s[l] - '0', s[r] - '0') + '0'; }
        return s;
    } else {
        for(auto &[l, r] : chars){
            if(s[l] == '9' || s[r] == '9') {
                s[l] = s[r] = '9';
                --k;
                --c;
            }
        }
        
        for(int l{0}, r = s.size() - 1; k > c && l <= r; ++l, --r){
            if(k > c && s[l] != '9'){
                if (s[l] == s[r] && k - 2 < c) {
                    break;
                } else if (s[l] != s[r]){ --c; }
                
                s[l] = s[r] = '9';
                k -= 2;         
            }
        }
        
        for(auto &[l, r] : chars){
            if(s[l] != s[r]) {
                s[l] = s[r] = max(s[l] - '0', s[r] - '0') + '0';
                --k;
            }
        }
        
        if (k == 1 && s.size() % 2){
            int m = s.size() / 2;
            s[m] = '9';
        }
        
        return s;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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
