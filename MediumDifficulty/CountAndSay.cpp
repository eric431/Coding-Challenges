/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

 

Constraints:

1 <= n <= 30
*/

class Solution {
public:
    string rle(const string& str)
    {
        string s_encoded = "";
        int cnt{1};
        char num;
        for(int i = 1; i < str.size(); ++i)
        {
            if(i > 0 && str[i] == str[i - 1])
            {
                ++cnt;
            }
            else if(str[i] != str[i - 1])
            {
                if(cnt < 10) 
                {
                    num = '0' + cnt;
                    s_encoded += num;
                    s_encoded += str[i - 1];
                }
                else if(cnt > 10)
                {
                    int r;
                    stack<int> s;
                    while(cnt > 0)
                    {
                        r = cnt % 10;
                        cnt /= 10;

                        s.push(r);
                    }
                    while(!s.empty())
                    {
                        cnt = s.top();
                        s.pop();

                        num = '0' + cnt;
                        s_encoded += num;
                    }
                    s_encoded += str[i - 1];
                }
                cnt = 1;
            }
        }

        num = '0' + cnt;
        s_encoded += num;
        s_encoded += *str.rbegin();

        return s_encoded;
    }

    string countAndSay(int n) {
        string str = "1";

        for(int i = 0; i < n - 1; ++i)
        {
            str = rle(str);
            cout << str << endl;
        }

        return str;   
    }
};