// You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

// A 0-indexed string num of length n + 1 is created using the following conditions:

// num consists of the digits '1' to '9', where each digit is used at most once.
// If pattern[i] == 'I', then num[i] < num[i + 1].
// If pattern[i] == 'D', then num[i] > num[i + 1].
// Return the lexicographically smallest possible string num that meets the conditions.

 

// Example 1:

// Input: pattern = "IIIDIDDD"
// Output: "123549876"
// Explanation:
// At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
// At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
// Some possible values of num are "245639871", "135749862", and "123849765".
// It can be proven that "123549876" is the smallest possible num that meets the conditions.
// Note that "123414321" is not possible because the digit '1' is used more than once.
// Example 2:

// Input: pattern = "DDD"
// Output: "4321"
// Explanation:
// Some possible values of num are "9876", "7321", and "8742".
// It can be proven that "4321" is the smallest possible num that meets the conditions.
 

// Constraints:

// 1 <= pattern.length <= 8
// pattern consists of only the letters 'I' and 'D'.


class Solution {
    public:
        string smallestNumber(string pattern) {
            unordered_set<char> visited;
            int min {1};
    
            string smallest_number = "";
            for(auto i{0}; i < pattern.size(); ++i)
            {
                if(pattern[i] == 'I')
                {
                    for(int j = 1; j < 10; ++j)
                    {
                        if(!visited.contains(j + '0'))
                        {
                            smallest_number += j + '0';
                            visited.insert(j + '0');
    
                            ++min;
                            break;
                        }
                    }
    
                    if(i + 1 == pattern.size())
                    {
                        for(int j = 1; j < 10; ++j)
                        {
                            if(!visited.contains(j + '0'))
                            {
                                smallest_number += j + '0';
                                visited.insert(j + '0');
    
                                break;
                            }
                        }
                    }
                }
                else if(pattern[i] == 'D')
                {
                    int itr = 0;
                    while(i + itr < pattern.size() && pattern[i + itr] == 'D')
                    {
                        ++itr;
                    }
                    
                    int itr2 = min + itr;
                    int tmp = itr2;
                    for(int j {0}; j < itr; ++j)
                    {
                        if(!visited.contains(itr2 + '0'))
                        {
                            smallest_number += '0' + itr2;
                            visited.insert(itr2 + '0');
                        }
                        --itr2;
                    }
    
                    if(i + itr == pattern.size())
                    {
                        smallest_number += '0' + itr2;
                    }
                    i += itr - 1;
    
                    min = tmp;
                }
            }
    
            return smallest_number;
        }
    };