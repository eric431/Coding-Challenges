/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string>> anagram__map;
        map<char, int> anagram_checker;
        
        vector<char> element_map;
        vector<vector<string>> result;
        
        string buffer = "";
        
        for(auto& el : strs)
        {
            for(auto& c : el)
            {
                element_map.push_back(c);
            }
            sort(element_map.begin(), element_map.end());
            anagram__map[element_map].push_back(el);   
            element_map.clear();
        }
        
        for(auto& [Key, Value] : anagram__map)
        {
            result.push_back(Value);
        }
        
        return result;
    }
};