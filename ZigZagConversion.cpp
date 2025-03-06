// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

class Solution {
    public:
        string convert(string s, int numRows) {
            string new_string {};
            int m {0};
            int k = 2 * numRows - 2;
            for(auto i{0}; i < numRows; ++i)
            {
                m = -2 * i;
                for(auto j{i}; j < s.size(); j += max(k, 1))
                {
                    new_string += s[j];
                    if(i > 0 && i < numRows - 1)
                    {
                        int itr2 = j + max(k + m, 0);
                        if(itr2 < s.size()) new_string += s[itr2];
                    }
                }
            }
    
            return new_string; 
        }
    };