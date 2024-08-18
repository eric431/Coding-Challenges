/* TASK DESCRIPTION */
// A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

// The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

// For example, consider string S = CAGCCTA and arrays P, Q such that:

//     P[0] = 2    Q[0] = 4
//     P[1] = 5    Q[1] = 5
//     P[2] = 0    Q[2] = 6
// The answers to these M = 3 queries are as follows:

// The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
// The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
// The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
// Write a function:

// vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

// that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

// Result array should be returned as a vector of integers.

// For example, given the string S = CAGCCTA and arrays P, Q such that:

//     P[0] = 2    Q[0] = 4
//     P[1] = 5    Q[1] = 5
//     P[2] = 0    Q[2] = 6
// the function should return the values [2, 4, 1], as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// M is an integer within the range [1..50,000];
// each element of arrays P and Q is an integer within the range [0..N - 1];
// P[K] ≤ Q[K], where 0 ≤ K < M;
// string S consists only of upper-case English letters A, C, G, T.

// you can use includes, for example:
// #include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // Implement your solution here
    map<char, int> ntides {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    int l = S.size() + 1;
    vector<vector<int>> genome_pattern(4, vector<int>(l));
    vector<int> cum_sum(4);
    vector<int> rst(P.size());

    for(auto i = 1; i < l; i++)
    {
        for(int y = 0; y < 4; y++)
        {
            if(y == ntides[S[i - 1]] - 1)
            {
                cum_sum[ntides[S[i - 1]] - 1] += ntides[S[i -1]];
                genome_pattern[ntides[S[i - 1]] - 1][i] = cum_sum[ntides[S[i - 1]] - 1];
            }
            else
            {
                genome_pattern[y][i] = cum_sum[y];
            }
        }
    }

    for(size_t j = 0; j < P.size(); j++)
    {
        for(int k = 0; k < 4; k++)
        {
            if(P[j] == Q[j])
            {
                auto idx = P[j];
                rst[j] = ntides[S[idx]];
                break;
            }
            else if(genome_pattern[k][P[j]] != genome_pattern[k][Q[j] + 1])
            {
                rst[j] = k + 1;
                break;
            }
        }
    }

    return rst;
}