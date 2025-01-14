/*
Input Format

A single line containing the string .

Constraints

 contains only lower-case English letters, ascii[a-z]
Output Format

Find and return the string which is the lexicographically smallest valid .

Sample Input 0

eggegg
Sample Output 0

egg
Explanation 0

Split "eggegg" into strings of like character counts: "egg", "egg"
reverse("egg") = "gge"
shuffle("egg") can be "egg"
"eggegg" belongs to the merge of ("gge", "egg")

The merge is: gge.

'egg' < 'gge'

Sample Input 1

abcdefgabcdefg
Sample Output 1

agfedcb
Explanation 1

Split the string into two strings with like characters:  and .
Reverse  = 
Shuffle  can be 
Merge to bcdefga

Sample Input 2

aeiouuoiea
Sample Output 2

aeiou
Explanation 2

Split the string into groups of like characters: 
Reverse  = 
These merge to uoiea
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reverseShuffleMerge(string s) {    
    unordered_map<char, int> discarded_characters_{};
    unordered_map<char, int> result_characters_{};
    unordered_map<char, int> string_characters_{};
    for(auto& el : s) ++string_characters_[el];
    
    string result(1, s.back());    
    ++result_characters_[result[0]];
    for(int i = s.size() - 2; i > -1; --i)
    {
        if(result_characters_[s[i]] < 0.5 * string_characters_[s[i]] && s[i] < result.back())
        {
            while(result != "" && s[i] < result.back())
            {
                if(discarded_characters_[result.back()] == 0.5 * string_characters_[result.back()]) break;
                
                --result_characters_[result.back()];
                ++discarded_characters_[result.back()];
                result.pop_back();                
            }
        }
        
        if(result_characters_[s[i]] < 0.5 * string_characters_[s[i]] || discarded_characters_[s[i]] == 0.5 * string_characters_[s[i]])
        {
            result += s[i];
            ++result_characters_[s[i]];
        }
        else if(result_characters_[s[i]] == 0.5 * string_characters_[s[i]] && discarded_characters_[s[i]] < 0.5 * string_characters_[s[i]])
        {
            ++discarded_characters_[s[i]];
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
