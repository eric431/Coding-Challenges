/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        auto binary_add = [&](bool a_, bool b_, bool carry)
        {
            bool r = carry ^ (a_ ^ b_);
            bool c = ((carry && a_) || (carry && b_)) || (a_ && b_);
            
            return make_pair(c, r);
        };
        
        vector<bool> result{};
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        bool carry {false};
        while(i > -1 && j > -1)
        {
            bool a_i = a[i] - '0';
            bool b_i = b[j] - '0';
            auto sum = binary_add(a_i, b_i, carry);
            
            result.push_back(sum.second);
            carry = sum.first;
            
            --i;
            --j;
        }
        
        while(i > -1)
        {
            bool a_i = a[i] - '0';
            auto sum = binary_add(carry, a_i, false);
            carry = sum.first;
            result.push_back(sum.second);
            
            --i;
        }
        
        while(j > -1)
        {
            bool b_i = b[j] - '0';
            auto sum = binary_add(carry, b_i, false);
            carry = sum.first;
            result.push_back(sum.second);
            
            --j;
        }
        
        if(i == -1 && j == -1 && carry)
        {
            result.push_back(carry);
        }
        
        ranges::reverse(result);
        string a_plus_b = "";
        for(auto el : result)
        {
            a_plus_b += to_string(el);
        }
        
        return a_plus_b;
    }
};