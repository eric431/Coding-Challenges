// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

 

// Example 1:

// Input: s = "42"

// Output: 42

// Explanation:

// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)
//            ^
// Example 2:

// Input: s = " -042"

// Output: -42

// Explanation:

// Step 1: "   -042" (leading whitespace is read and ignored)
//             ^
// Step 2: "   -042" ('-' is read, so the result should be negative)
//              ^
// Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
//                ^
// Example 3:

// Input: s = "1337c0d3"

// Output: 1337

// Explanation:

// Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
//              ^
// Example 4:

// Input: s = "0-1"

// Output: 0

// Explanation:

// Step 1: "0-1" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
//           ^
// Example 5:

// Input: s = "words and 987"

// Output: 0

// Explanation:

// Reading stops at the first non-digit character 'w'.

 

// Constraints:

// 0 <= s.length <= 200
// s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

class Solution {
    public:
        int myAtoi(string s) {
            bool sign {false}; // false represents positive
            bool integer_detected {false}; // set to true when first non-zero detected
            bool pos_sign {false};
    
            int integer {0};
            vector<int> integer_v {};
            for(auto i{0}; i < s.size(); ++i)
            {
                if((sign || pos_sign) && !integer_detected && s[i] == ' ')
                {
                    return 0;
                }
    
                if(!integer_detected && (s[i] == '-' || s[i] == '+'))
                {
                    if(pos_sign || sign) return 0;
    
                    if(s[i] == '-') sign = true;
                    else if(s[i] == '+') pos_sign = true;
                }
                else if(!integer_detected && (s[i] >= '0' && s[i] <= '9'))
                {
                    integer_detected = true;
                    integer_v.push_back(s[i] - '0');
                }
                else if(s[i] >= '0' && s[i] <= '9')
                {
                    integer_v.push_back(s[i] - '0');
                }
                else if(!integer_detected && s[i] != '+' && s[i] != ' ' && (s[i] < '0' || s[i] > '9'))
                {
                    return 0;
                }
                else if(integer_detected)
                {
                    break;
                }
            }
    
            for(auto &el : integer_v)
            {
                if(integer == numeric_limits<int>::max() / 10)
                {
                    if(!sign && el >= 7)
                    {
                        return numeric_limits<int>::max();
                    }
                    else if(sign && el >= 8)
                    {
                        return numeric_limits<int>::min();
                    }
                }
                else if(integer > numeric_limits<int>::max() / 10)
                {
                    cout << 65 << endl;
                    return sign ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }
    
                integer *= 10;
                integer += el;
            }
    
            return sign ? -1 * integer : integer;
        }
    };