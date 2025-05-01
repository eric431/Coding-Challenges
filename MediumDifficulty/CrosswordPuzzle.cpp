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

void fill_h(vector<string>& crossword, string& word, int r, int c) {
    for(int i{0}; i < word.size(); ++i) { crossword[r][c + i] = word[i]; }
}

void fill_v(vector<string>& crossword, string& word, int r, int c) {
    for(int i{0}; i < word.size(); ++i) { crossword[r + i][c] = word[i]; }
}

void backtrack_fill(vector<string>& crossword, vector<string>& words, int r, int c, bool direction) {
    for(auto& w : words) {
        if(direction) {
            for(int i{0}; i < w.size(); ++i) {
                if(r > 1 && crossword[r - 1][c] == '-') {
                    int r_itr = r;
                    while(r_itr > -1 && crossword[r_itr][c] == '-') --r_itr;
                    ++r_itr;
                    
                    fill_control(crossword, horizontal_words, vertical_words, words_, r_itr, c);
                }
                crossword[r][c + i] = w[i];
            }        
        } else {
            for(int i{0}; i < w.size(); ++i) {
                if(c > 1 && crossword[r][c - 1] == '-') {
                    int c_itr = c;
                    while(c_itr > -1 && crossword[r][c_itr] == '-') --c_itr;
                    ++c_itr;
                    
                    fill_control(crossword, horizontal_words, vertical_words, words_, r_itr, c);
                }
                crossword[r + i][c] = w[i];
            }              
        }        
    }
}

void fill_control(vector<string>& crossword, vector<vector<int>>& horizontal_words, vector<vector<int>>& vertical_words, unordered_map<int, vector<string>>& words_, int r, int c) {
    if(horizontal_words[r][c] > 1 && words_[horizontal_words[r][c]].size() == 1) {
        auto word_ = words_[horizontal_words[r][c]][0];
        fill_h(crossword, word_, r, c);
        words_.erase(horizontal_words[r][c]);
    } else if(vertical_words[r][c] > 1 && words_[vertical_words[r][c]].size() == 1) {
        auto word_ = words_[vertical_words[r][c]][0];
        fill_v(crossword, word_, r, c);
        words_.erase(vertical_words[r][c]);
    } else if(horizontal_words[r][c] > 1 && words_[horizontal_words[r][c]].size() > 2) {
        
    } else if(vertical_words[r][c] > 1 && words_[vertical_words[r][c]].size() > 2) {
        
    }
}

void fill_puzzle(vector<string>& crossword, vector<vector<int>>& horizontal_words, vector<vector<int>>& vertical_words, unordered_map<int, vector<string>>& words_) {
    for(auto r{0}; r < crossword.size(); ++r)
        for(auto c{0}; c < crossword[r].size(); ++c)
            fill_control(crossword, horizontal_words, vertical_words, words_, r, c);   
}

void create_dmaps(vector<string>& crossword, vector<vector<int>>& vertical_words, vector<vector<int>>& horizontal_words) {
    int h_cnt{0};
    for(int r = crossword.size() - 1; r > -1; --r) {
        for(int c = crossword[r].size() - 1; c > -1; --c) {
            h_cnt = 0;
            while(crossword[r][c] == '-' && c > -1) {
                ++h_cnt;
                --c;
            }
            if(c + 1 < crossword[r].size()) horizontal_words[r][c + 1] = h_cnt;
        }
    }
    
    int v_cnt{};
    for(int c = crossword[0].size() - 1; c > -1; --c) {
        for(int r = crossword.size() - 1; r > -1; --r) {
            v_cnt = 0;
            while(crossword[r][c] == '-' && r > -1) {
                ++v_cnt;
                --r;
            }
            if(r + 1 < crossword[r].size()) vertical_words[r + 1][c] = v_cnt;
        }
    }    
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<int> row(crossword[0].size());
    vector<vector<int>> horizontal_words(crossword.size(), row);
    vector<vector<int>> vertical_words(crossword.size(), row);
    
    auto delimit_string = [&](string& words) {
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
        return words_;
    };   
    auto words_ = delimit_string(words); 
    
    create_dmaps(crossword, vertical_words, horizontal_words);
    fill_puzzle(crossword, horizontal_words, vertical_words, words_);
    
    return crossword;
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
