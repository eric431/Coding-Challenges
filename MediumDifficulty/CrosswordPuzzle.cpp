#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<int> row(crossword[0].size());
    vector<vector<int>> horizontal_words(crossword.size(), row);
    vector<vector<int>> vertical_words(crossword.size(), row);
    
    auto delimit_string = [&](string& words)
    {
        words += ';';
        unordered_map<int, vector<string>> words_;
        int i{0}, j{0};
        for(; j < words.size(); ++j)
        {
            if(words[j] == ';')
            {
                auto word_ = words.substr(i, j - i);
                i = j + 1;                
                words_[word_.size()].push_back(word_);
            }
        }
        return words;
    };   
    auto words_ = delimit_string(words);
    
    int h_cnt{0};
    for(int r = crossword.size() - 1; r > -1; --r)
    {
        for(int c = crossword[r].size() - 1; c > -1; --c)
        {
            h_cnt = 0;
            while(crossword[r][c] == '-' && c > -1)
            {
                horizontal_words[r][c] = (++h_cnt);
                
                if(r < crossword.size() - 1)
                    vertical_words[r][c] = vertical_words[r + 1][c] + 1;
                else if (r == crossword.size() - 1)
                    vertical_words[r][c] = 1;
                --c;
            }
        }
    }
    
    // for(auto el : vertical_words)
    // {
    //     for(auto el_ : el)
    //     {
    //         cout << el_ << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    // for(auto el : horizontal_words)
    // {
    //     for(auto el_ : el)
    //     {
    //         cout << el_ << " ";
    //     }
    //     cout << endl;
    // }
    
    for(auto r{0}; r < crossword.size(); ++r)
    {
        for(auto c{0}; c < crossword[r].size(); ++c)
        {
            if(horizontal_words[r][c] > 0 || vertical_words[r][c] > 0)
            {
                if(words_[horizontal_words[r][c]].size() == 1)
                {
                    
                }
                else if(words_[horizontal_words[r][c]].size() > 1)
            }
        }
    }
    
    return{};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
