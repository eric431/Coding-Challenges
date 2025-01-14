/*

Louise and Richard have developed a numbers game. They pick a number and check to see if it is a power of . If it is, they divide it by . If not, they reduce it by the next lower number which is a power of . Whoever reduces the number to  wins the game. Louise always starts.

Given an initial value, determine who wins the game.

Example

It's Louise's turn first. She determines that  is not a power of . The next lower power of  is , so she subtracts that from  and passes  to Richard.  is a power of , so Richard divides it by  and passes  to Louise. Likewise,  is a power so she divides it by  and reaches . She wins the game.

Update If they initially set counter to , Richard wins. Louise cannot make a move so she loses.

Function Description

Complete the counterGame function in the editor below.

counterGame has the following parameter(s):

int n: the initial game counter value
Returns

string: either Richard or Louise
Input Format

The first line contains an integer , the number of testcases.
Each of the next  lines contains an integer , the initial value for each game.

Constraints

Sample Input

1
6
Sample Output

Richard
Explanation

As  is not a power of , Louise reduces the largest power of  less than  i.e., , and hence the counter reduces to .
As  is a power of , Richard reduces the counter by half of  i.e., . Hence the counter reduces to .
As we reach the terminating condition with , Richard wins the game.

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

string counterGame(long n) {
    bitset<64> n_b(n);
    bitset<64> r_(1); // reference bit
    vector<bool> v_(64);
    
    int i{0};
    long num_of_rounds{0};
    while(n_b.any())
    {
        v_[i] = (n_b & r_).any();
        n_b >>= 1;
        ++i;
    }
    
    for(int i = v_.size() - 1; i > -1; --i)
    {
        if(v_[i] == 1)
        {
            if(n == (1ul << i))
            {
                num_of_rounds += i;
                break;
            }
            else if(n > (1ul << i))
            {
                ++num_of_rounds;
                n -= (1ul << i);

                if(n == 2)
                {
                    ++num_of_rounds;
                    break;
                }
                else if(n == 1)
                {
                    break;
                }
            }
        }
    }

    if(num_of_rounds % 2 == 0) return "Richard";
    else return "Louise";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

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