// HACKERRANK 

// You will be given a list of 32 bit unsigned integers. Flip all the bits ( and ) and return the result as an unsigned integer.

// Example

// . We're working with 32 bits, so:



// Return .

// Function Description

// Complete the flippingBits function in the editor below.

// flippingBits has the following parameter(s):

// int n: an integer
// Returns

// int: the unsigned decimal integer result
// Input Format

// The first line of the input contains , the number of queries.
// Each of the next  lines contain an integer, , to process.

// Constraints



// Sample Input

// 3 
// 2147483647 
// 1 
// 0
// Sample Output

// 2147483648 
// 4294967294 
// 4294967295
// Explanation

// Take 1 for example, as unsigned 32-bits is 00000000000000000000000000000001 and doing the flipping we get 11111111111111111111111111111110 which in turn is 4294967294.

// SOLUTION

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {
    auto to_be_flipped = bitset<32>(n);
    
    long flipped = to_be_flipped.flip().to_ulong();    
        
    return flipped;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        long result = flippingBits(n);

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
