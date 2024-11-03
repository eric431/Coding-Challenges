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

// void traversePuzzleRcs(const vector<string>& crossword, const map<int, vector<string>>& str_map, 
// pair<int, int> cell, set<pair<int, int>>& visited_cells)
// {
//     if(cell.first >= crossword.size() || cell.second >= crossword[0].size())
//         return;
        
//     if(crossword[cell.first][cell.second] == '-')
//     {
//         pair<int, int> new_cell = make_pair(cell.first, cell.second + 1);
//         traversePuzzleRcs(crossword, str_map, new_cell, visited_cells); 
        
//         new_cell = make_pair(cell.first + 1, cell.second);
//         traversePuzzleRcs(crossword, str_map, new_cell, visited_cells);
//     }
// }

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    // breakup word into individual words;
    words += ';';
    map<int, vector<string>> str_map{};
    string str_tmp;
    int start{0}, len{0};
    for(auto i = 0; i < words.size(); ++i)
    {
        if(words[i] == ';')
        {
            len = i - start;
            str_tmp = words.substr(start, len);
            start = i + 1;
            
            str_map[len].emplace_back(str_tmp);
        }
    }
    
    map<int, vector<pair<int, int>>> v_map;
    map<int, vector<pair<int, int>>> h_map;

    set<pair<int, int>> visited_cells;
    // traverse through crossword and solve unique problems first
    for(auto i = 0; i < crossword.size(); ++i)
    {
        for(auto j = 0; j < crossword[i].size(); ++j)
        {
            if(visited_cells.count(make_pair(i, j)) == 0 && crossword[i][j] == '-')
            {
                if(crossword[i][j + 1] == '-')
                {
                    int j_itr = j;
                    int cnt{0};
                    while(j_itr < crossword[i].size() && crossword[i][j_itr] == '-')
                    {
                        ++j_itr;
                        ++cnt;
                        visited_cells.insert(make_pair(i, j));
                    }
                    h_map[cnt].push_back(make_pair(i, j));
                    
                    j = --j_itr;
                } 
                else if(crossword[i + 1][j] == '-')
                {
                    int i_itr = i;
                    int cnt{0};
                    while(i_itr < crossword.size() && crossword[i_itr][j] == '-')
                    {
                        ++i_itr;
                        ++cnt;
                        visited_cells.insert(make_pair(i, j));
                    }
                    v_map[cnt].push_back(make_pair(i, j));                
                }
            }
        }
    }
    
    return {};
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
