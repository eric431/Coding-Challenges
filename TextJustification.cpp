/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 
*/

class Solution {
public:
    void format_text(vector<string>& line_v, vector<string>& justified_text, vector<string>& words, int& char_count, int& letter_count, int maxWidth, int i)
    {
        int num_spaces {0};
        int rem {0};
        int extra_space{0};
        string line{};

        if(line_v.size() > 1)
        {
            num_spaces = (maxWidth - letter_count) / (line_v.size() - 1);
            rem = (maxWidth - letter_count) % (line_v.size() - 1);
            if(rem) extra_space = 1;
        }
        else
        {
            num_spaces = maxWidth - letter_count;
        }

        for(auto i_{0}; i_ < line_v.size(); ++i_)
        {
            line += line_v[i_];

            if(i_ < line_v.size() - 1)
            {
                for(auto j{0}; j < num_spaces + extra_space; ++j)
                    line += " ";

                if(i_ >= rem - 1) extra_space = 0;
            }
            else if (line_v.size() == 1)
            {
                for(auto j{0}; j < num_spaces; ++j) line += " ";
            }
        }
        justified_text.push_back(line);

        line = "";
        line_v.clear();
        char_count  = 0;
        letter_count = 0;        
    }

    void format_text2(vector<string>& line_v, vector<string>& justified_text, vector<string>& words, int& char_count, int& letter_count, int maxWidth, int i)
    {
        string line = "";
        int num_spaces {};

        for(auto i_{0}; i_ < line_v.size(); ++i_)
        {
            line += line_v[i_];
            if(i_ < line_v.size() - 1) line += " ";
        }

        num_spaces = maxWidth - (char_count - 1);
        for(auto j{0}; j < num_spaces; ++j) line += " ";

        justified_text.push_back(line);
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int char_count{};
        int letter_count{};
        int num_spaces{};
        int rem {};
        string line {};
        vector<string> line_v{};
        vector<string> justified_text{};

        for(auto i{0}; i < words.size(); ++i)
        {
            line_v.push_back(words[i]);
            char_count += words[i].size() + 1; // add 1 to represent spacing 
            letter_count += words[i].size();

            if(i < words.size() - 1 && char_count + words[i + 1].size() > maxWidth)
            {
                format_text(line_v, justified_text, words, char_count, letter_count, maxWidth, i);
            }
            else if(i == words.size() - 1)
            {
                format_text2(line_v, justified_text, words, char_count, letter_count, maxWidth, i);
            }
        }

        return justified_text;
    }
};