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
 
struct CandyUpdate
{
    long m{};
    long w{};
    long p{};    
};

long minimumPasses(long m, long w, long p, long n) {
    auto future_in_calc = [&](long& m_l, long& w_l, long &machine_, long &worker_, long& candy_retained_, long& future_inventory, long& min_pass, long goal, long& conv_rate, long& prod_rate, CandyUpdate& optimal_purchase)
    {
        long p_l = m_l - machine_ + w_l - worker_;
        long c = m_l * w_l;          

        future_inventory = c + (candy_retained_ -  p_l * conv_rate);
        if(future_inventory >= goal)
        {
            optimal_purchase.m = m_l;
            optimal_purchase.w = w_l;
            optimal_purchase.p = p_l;
            return true;
        }
        else if((goal - future_inventory) / c < min_pass || ((goal - future_inventory) / c == min_pass && c > prod_rate))
        {
            prod_rate = c;
            min_pass = (goal - future_inventory) / c;
            optimal_purchase.m = m_l;
            optimal_purchase.w = w_l;
            optimal_purchase.p = p_l;                    
        }
        return false;      
    };

    // find the optimal purchase using a binary search method
    auto invest_bs = [&](long &machine_, long &worker_, long& candy_retained_, long &purchasing_power_, long goal, long& conv_rate){
        CandyUpdate optimal_purchase{machine_, worker_, purchasing_power_};
        long min_pass{numeric_limits<long>::max()};
        long m_l{machine_}, w_l{worker_}, itr{purchasing_power_};
        long future_inventory{}, prod_rate {machine_ * worker_};
        long upper_worker_bound{}, upper_machine_bound {machine_ + itr};
        
        while(m_l <= upper_machine_bound)
        {
            w_l = worker_;
            upper_worker_bound = (worker_ + itr) - (m_l - machine_);
            while(w_l <= upper_worker_bound)
            {
                if(future_in_calc(m_l, w_l, machine_, worker_, candy_retained_, future_inventory, min_pass, goal, conv_rate, prod_rate, optimal_purchase))
                    return optimal_purchase;
                
                if(w_l < upper_worker_bound - 1)
                {
                    long tmp = 0.5 * (w_l + upper_worker_bound);
                    
                    if(future_in_calc(m_l, tmp, machine_, worker_, candy_retained_, future_inventory, min_pass, goal, conv_rate, prod_rate, optimal_purchase))
                    {
                        upper_worker_bound = tmp;
                    }
                    else 
                    {
                        w_l = tmp;
                    }                  
                }             
                else if(w_l <= upper_worker_bound) ++w_l;
            }
            if(m_l < upper_machine_bound - 1) m_l = 0.5 * (m_l + upper_machine_bound);              
            else if(m_l <= upper_machine_bound) ++m_l;
        }  
        return optimal_purchase;
    };

    long passes{0}, candyAvailable{0}, purchasing_power{0};
    while(candyAvailable < n)
    {
        ++passes;
        
        if((n - candyAvailable) / min(m, w) < max(m, w)) break;        
        
        candyAvailable += m * w;
        purchasing_power = candyAvailable / p;
        auto factory_update = invest_bs(m, w, candyAvailable, purchasing_power, n, p);        
        
        candyAvailable -= factory_update.p * p;
        m = factory_update.m;
        w = factory_update.w;
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
