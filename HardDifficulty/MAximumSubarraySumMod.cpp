#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY a
 *  2. LONG_INTEGER m
 */
 
long search(const vector<long>& pSum, long i, long el)
{
    auto idx = lower_bound(pSum.begin(), pSum.begin() + i, el);
    return *idx;
}

long maximumSum(vector<long> a, long m) {
    long maxSum{0};
    long cumSum{0};
    long modSum{0};
    long idx{0};

    // long min_ = numeric_limits<long>::max();

    vector<long> pSum(a.size());    
    for(long i{0}; i < a.size(); ++i)
    {
        // min_ = min(min_, a[i]);
        
        cumSum += a[i];
        pSum[i] = cumSum;
        
        if(cumSum < m)
            ++idx;
        
        modSum = pSum[i] % m;
        maxSum = max(maxSum, modSum);
    }
 
    long sub{0}, el{0};
    long j{0};
    
    // long incr = min_ - (min_ % m);
    // incr = max(incr, m);
    
    if(idx != 0)
        for(long i{idx}; i < pSum.size(); ++i)
        {
            sub = m - 1;
            while(sub < pSum[i])
            {
                el = pSum[i] - sub;
                j = search(pSum, i, el);

                modSum = (pSum[i] - j) % m;
                maxSum = max(maxSum, modSum);            
                
                sub += m;
            }
        }
    else if(idx == 0)
        for(long i = idx; i < pSum.size(); ++i)
        {
            for(long j = 0; j < i; ++j)
            {
                modSum = (pSum[i] - pSum[j]) % m;
                maxSum = max(maxSum, modSum);
            }
        }

    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        long m = stol(first_multiple_input[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

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

