 /*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */
 int truckTour(vector<vector<int>> petrolpumps) {
    int index{-1};
    int tank{0};
    for(int i{0}; i < petrolpumps.size(); ++i)
    {
        if(index == i)
            break;
        if(tank == 0) index = i;
        tank += (petrolpumps[i][0] - petrolpumps[i][1]);

        if(tank < 0)
        {
            tank = 0;

            index = -1;
            continue;
        }
        if(i == petrolpumps.size() - 1) i = -1;
    }
 
    return index;
 }


 

// ALTERNATIVELY
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */

int truckTour(vector<vector<int>> petrolpumps) {
    int tank {0};
    int start {-1};
    
    int i{0};
    int n = petrolpumps.size();
    while(true)
    {
        tank += petrolpumps[i][0];
        
        if(tank < petrolpumps[i][1])
        {
            start = -1;
            tank = 0;
        }
        else if(tank >= petrolpumps[i][1])
        {
            if(start == -1) start = i;
            else if(start == i) return start;
            
            tank -= petrolpumps[i][1];
        }        
        
        (++i) %= n;
    }

    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> petrolpumps(n);

    for (int i = 0; i < n; i++) {
        petrolpumps[i].resize(2);

        string petrolpumps_row_temp_temp;
        getline(cin, petrolpumps_row_temp_temp);

        vector<string> petrolpumps_row_temp = split(rtrim(petrolpumps_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int petrolpumps_row_item = stoi(petrolpumps_row_temp[j]);

            petrolpumps[i][j] = petrolpumps_row_item;
        }
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

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

