// You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

// "1" -> 'A'
// "2" -> 'B'
// ...
// "25" -> 'Y'
// "26" -> 'Z'

// However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

// For example, "11106" can be decoded into:

// "AAJF" with the grouping (1, 1, 10, 6)
// "KJF" with the grouping (11, 10, 6)
// The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
// Note: there may be strings that are impossible to decode.

// Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

// The test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: s = "12"

// Output: 2

// Explanation:

// "12" could be decoded as "AB" (1 2) or "L" (12).

// Example 2:

// Input: s = "226"

// Output: 3

// Explanation:

// "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

// Example 3:

// Input: s = "06"

// Output: 0

// Explanation:

// "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

 

// Constraints:

// 1 <= s.length <= 100
// s contains only digits and may contain leading zero(s).


class Solution {
    public:
        string str;
        vector<int> memo;
        
        int decoding_rcs(int i)
        {
            if((i < str.size() && str[i] == '0') || i >= str.size()) 
                return 0;
            else if(memo[i] != -1) 
                return memo[i];
            else if(i == str.size() - 1 && str[i] > '0') 
                return memo[i] = 1;
            else if(i == str.size() - 2 && (str[i] > '0' && str[i] < '3')){
                if(str[i] == '1' || (str[i] == '2' && str[i + 1] < '7'))
                    return memo[i] = 1 + decoding_rcs(i + 1);
            }
            
            if(str[i] == '1' || (str[i] == '2' && str[i + 1] < '7'))
                return memo[i] = decoding_rcs(i + 1) + decoding_rcs(i + 2);
            else if(str[i] > '2' || (str[i] == '2' && str[i + 1] >= '7'))
            {
                return memo[i] = decoding_rcs(i + 1);
            }
            else 
                return memo[i] = 0;
        }
        
        int numDecodings(string s) {
            this->memo.resize(s.size(), -1);
            
            this->str = s;
            
            int num_decodings;
    
            return decoding_rcs(0);
        }
    };