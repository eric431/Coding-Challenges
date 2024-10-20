// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].


class Solution {
public:
    void recursive_perm(vector<string>& com, string& digits, int i, map<char, string>& lc)
    {
        vector<string> new_com;
        if(i == digits.size())
        {
            return;
        }
        else
        {
            if(i == 0)
            {
                for(auto el2 : lc[digits[i]])
                {
                    string s = "";
                    s += el2;
                    new_com.push_back(s);
                }
            }
            else 
            {
                for(auto e : com)
                {
                    for(auto e2 : lc[digits[i]])
                    {
                        string s = e + e2;
                        new_com.push_back(s);
                    }
                }
            }
        }
        recursive_perm(new_com, digits, i + 1, lc);
        com = new_com;
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> phone_pad = {{'2', "abc"},
                                       {'3', "def"},
                                       {'4', "ghi"},
                                       {'5', "jkl"},
                                       {'6', "mno"},
                                       {'7', "pqrs"},
                                       {'8', "tuv"},
                                       {'9', "wxyz"}};
        vector<string> combinations{};

        recursive_perm(combinations, digits, 0, phone_pad);

        return combinations;
    }
};