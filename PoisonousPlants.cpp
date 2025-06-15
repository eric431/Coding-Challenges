#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'poisonousPlants' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY p as parameter.
 */

int poisonousPlants(vector<int> p) {
    stack<int> m_stack {};
    vector<int> days(p.size(), 0);

    int d {0}, j{0}, prev{0};
    for(int i = p.size() - 1; i > -1; --i){  
        while(!m_stack.empty() && p[i] < p[m_stack.top()]){
            j = m_stack.top();

            if (i != (j - 1)) {
                // days[j] = max(days[prev], days[j]) + 1;
                days[i] = max(days[prev], days[i]) + 1;
            } else {
                ++days[j];
            }
            
            d = max({d, days[j], days[i]});
            prev = j;

            m_stack.pop();
        }
        m_stack.push(i);

        // for(auto& el : days){
        //     cout << el << " ";
        // }
        // cout << endl;
    }
    
    return d;    
}

int main()
{
    ifstream fin("poisonous_plants_inputs.txt");

    string n_temp;
    getline(fin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(fin, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    // for(auto& el : p){
    //     cout << el << " ";
    // }
    // cout << endl;

    int result = poisonousPlants(p);

    cout << result << "\n";

    fin.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
