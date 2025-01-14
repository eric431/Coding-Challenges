/*

Karl loves playing games on social networking sites. His current favorite is CandyMaker, where the goal is to make candies.

Karl just started a level in which he must accumulate  candies starting with  machines and  workers. In a single pass, he can make  candies. After each pass, he can decide whether to spend some of his candies to buy more machines or hire more workers. Buying a machine or hiring a worker costs  units, and there is no limit to the number of machines he can own or workers he can employ.

Karl wants to minimize the number of passes to obtain the required number of candies at the end of a day. Determine that number of passes.

For example, Karl starts with  machine and  workers. The cost to purchase or hire,  and he needs to accumulate  candies. He executes the following strategy:

Make  candies. Purchase two machines.
Make  candies. Purchase  machines and hire  workers.
Make  candies. Retain all  candies.
Make  candies. With yesterday's production, Karl has  candies.
It took  passes to make enough candies.

Function Description

Complete the minimumPasses function in the editor below. The function must return a long integer representing the minimum number of passes required.

minimumPasses has the following parameter(s):

m: long integer, the starting number of machines
w: long integer, the starting number of workers
p: long integer, the cost of a new hire or a new machine
n: long integer, the number of candies to produce
Input Format

A single line consisting of four space-separated integers describing the values of , , , and , the starting number of machines and workers, the cost of a new machine or a new hire, and the the number of candies Karl must accumulate to complete the level.

Constraints

Output Format

Return a long integer denoting the minimum number of passes required to accumulate at least  candies.

Sample Input

3 1 2 12
Sample Output

3
Explanation

Karl makes three passes:

In the first pass, he makes  candies. He then spends  of them hiring another worker, so  and he has one candy left over.
In the second pass, he makes  candies. He spends  of them on another machine and another worker, so  and  and he has  candies left over.
In the third pass, Karl makes  candies. Because this satisfies his goal of making at least  candies, we print the number of passes (i.e., ) as our answer.

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumPasses' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER m
 *  2. LONG_INTEGER w
 *  3. LONG_INTEGER p
 *  4. LONG_INTEGER n
 */

long minimumPasses(long m, long w, long p, long n) {
    long passes{0};
    unsigned long n_{0}; // num of created candy
    
    auto calculate_remaining_days = [&](long c, long m_, long w_, long n)
    {
        return static_cast<long double>(n - c) / (m_ * w_);
    };
    auto rem_days = [&](long& m_i, long& w_i, long m, long w, long i, long c)
    {
        if(m_i <= w_i)
        {
            if(i <= w - m)
            {
                m_i = m + i;
                w_i = w;
            }
            else
            {
                long rem = i - (w - m);
                m_i = m + (w - m);
                m_i += rem / 2;
                w_i = w + rem - (rem / 2);                    
            }
        }
        else
        {
            if(i <= m - w)
            {
                w_i = w + i;
                m_i = m;
            }
            else
            {
                long rem = i - (m - w);
                w_i = w + (m - w);
                w_i += rem / 2;
                m_i = m + rem - (rem / 2);           
            }
        }
        
        long c_ = c - p * i;
        return calculate_remaining_days(c_, m_i, w_i, n);        
    };
    auto buy_candy = [&](long m, long w, long q, long c)
    {
        long m_lo{}, m_hi{}, w_lo{}, w_hi{};
        long m_{}, w_{}; 
        long lo{0}, hi{q};
        
        while(lo < hi)
        {
            m_lo = m;
            w_lo = w;
            
            m_hi = m;
            w_hi = w;
            long double d_lo = rem_days(m_lo, w_lo, m, w, lo, c);
            long double d_hi = rem_days(m_hi, w_hi, m, w, hi, c);

            if(d_lo < d_hi)
            {
                hi = (hi - lo) / 2 + lo;
                if (d_lo == 0) return make_pair(m_lo, w_lo);
                m_ = m_lo;
                w_ = w_lo;
            }
            else if(d_hi <= d_lo)
            {
                lo = (hi - lo) / 2 + lo;
                if (d_hi == 0) return make_pair(m_hi, w_hi);
                m_ = m_hi;
                w_ = w_hi;
            }
            
            if(hi - lo == 1) break;
        }

        return make_pair(m_, w_);
    };
    auto acquire_more_candy = [&](long i, unsigned long &n_, long &m, long &w, long &passes)
    {
        long num_passes{};
        if(i / m < w || i / w < m)
            num_passes = 1;
        else 
            num_passes = ceil(static_cast<long double>(i - (n_ % i)) / (m * w));

        passes += num_passes;
        n_ += (num_passes * m * w);      
    };
       
    long search_param_{};
    if(n > p) search_param_ = p;
    else if(n <= p) search_param_ = n;

    while(n_ < n)
    {        
        if(n / m < w || n / w < m)
        {
            acquire_more_candy(n, n_, m, w, passes);
            break;
        }
        else
        {
            if(n_ > p && n_ < n) search_param_ = min(search_param_, static_cast<long>(n - n_));
            acquire_more_candy(search_param_, n_, m, w, passes);   
        }

        if(n_ >= n) break;
        else if (n_ >= p)
        {
            long q_ = n_ / p; // quantity of machine or workers to buy
            auto inventory = buy_candy(m, w, q_, n_);

            n_ -= p * ((inventory.first - m) + (inventory.second - w));
            m = inventory.first;
            w = inventory.second;    
        }
    }
    
    return passes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long m = stol(first_multiple_input[0]);

    long w = stol(first_multiple_input[1]);

    long p = stol(first_multiple_input[2]);

    long n = stol(first_multiple_input[3]);

    long result = minimumPasses(m, w, p, n);

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