#include <bits/stdc++.h>

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

bool is_abbrev(int i, int j, string &a, string &b, vector<vector<int>>& memo)
{        
    if (i == a.size() && j == b.size()) return true;
    else if (i == a.size()) return false;
    
    int l = a.size();
    if(memo[l][i] != -1) return memo[l][i];
    
    if(isupper(a[i])) {
        if (j == b.size() || a[i] != b[j]) {
            return memo[l][i] = false;
        } else {
            return memo[l][i] = is_abbrev(i + 1, j + 1, a, b, memo); 
        }
    } else {
        string a_cpy = a;
        a_cpy.erase(i, 1);
        
        a[i] = toupper(a[i]);

        return memo[l][i] = is_abbrev(i, j, a, b, memo) || is_abbrev(i, j, a_cpy, b, memo);
    }
}

string abbreviation(string a, string b) {
    vector<vector<int>> memo(a.size() + 1, vector<int>(a.size(), -1));
    return is_abbrev(0, 0, a, b, memo) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

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
