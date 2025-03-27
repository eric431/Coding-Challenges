#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

static string a_ = "";
static string b_ = "";

static int len_a;
static int len_b;

unordered_set<string> cache{};

bool dp_solver(int i, int j, string a, vector<vector<bool>>& memo)
{
    if(i == len_a && j == len_b) return true; // (a == b_);
    else if((i >= len_a && j < len_b) || (isupper(a_[i]) && j == len_b)) return false;

    // cout << 36 << endl;
    
    bool ans = false;
    if(a_[i] == b_[j] && a.size() == j){
        // a += a_[i];
        auto new_a = a + a_[i];
        ans |= dp_solver(i + 1, j + 1, new_a, memo);
        // a.pop_back();
        
        return ans;
    }
    else if (a.size() != j) return false;

    // cout << 49 << endl;

    if(islower(a_[i])){
        auto suffix = b_.substr(0, j + 1);

        ans |= dp_solver(i + 1, j, a, memo);
        if(ans) return ans;

        auto key = (a + a_[i]) + '#' + suffix;
        cache.insert(key);

        cout << key << " " << a_[i + 1] << endl;
        
        auto upper = toupper(a_[i]);
        auto new_a = a;
        new_a += upper;

        key = new_a + '#' + suffix;
        // cout << key << endl;
        if (upper == b_[j] && !cache.count(key))
        {
            ans |= dp_solver(i + 1, j + 1, new_a, memo);

            if(ans) return ans;

            // a.pop_back();

            // cout << key << endl;

            cache.insert(key);
        }

        return ans;
    }
    else return false;
}

string abbreviation(string a, string b) {
    a_ = a;
    b_ = b;
    len_a = a.size();
    len_b = b.size();

    vector<vector<bool>> memo(a.size(), vector<bool>(26, true));

    string str = "";
    return dp_solver(0, 0, str, memo) ? "YES" : "NO";
}

int main()
{
    ifstream file("abbreviation_input.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int q;
    vector<string> a_vec{};
    vector<string> b_vec{};

    int i{0};
    string line;
    if(file.is_open()){
        while( getline(file, line) ){
            if(i == 0) q = stoi(line);
            else if(i % 2) a_vec.push_back(line);
            else b_vec.push_back(line);

            ++i;
        }
    }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        auto a = a_vec[q_itr];
        auto b = b_vec[q_itr];

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    file.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(),
        s.end()
    );

    return s;
}
