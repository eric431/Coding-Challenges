// HACKERRANK

// You are given  queries. Each query is of the form two integers described below:
// -  : Insert x in your data structure.
// -  : Delete one occurence of y from your data structure, if present.
// -  : Check if any integer is present whose frequency is exactly . If yes, print 1 else 0.

// The queries are given in the form of a 2-D array  of size  where  contains the operation, and  contains the data element.

// Example

// The results of each operation are:

// Operation   Array   Output
// (1,1)       [1]
// (2,2)       [1]
// (3,2)                   0
// (1,1)       [1,1]
// (1,1)       [1,1,1]
// (2,1)       [1,1]
// (3,2)                   1
// Return an array with the output: .

// Function Description

// Complete the freqQuery function in the editor below.

// freqQuery has the following parameter(s):

// int queries[q][2]: a 2-d array of integers
// Returns
// - int[]: the results of queries of type 

// Input Format

// The first line contains of an integer , the number of queries.
// Each of the next  lines contains two space-separated integers,  and .

// Constraints

// All 
// Sample Input 0

// 8
// 1 5
// 1 6
// 3 2
// 1 10
// 1 10
// 1 6
// 2 5
// 3 2
// Sample Output 0

// 0
// 1
// Explanation 0

// For the first query of type , there is no integer whose frequency is  (). So answer is .
// For the second query of type , there are two integers in  whose frequency is  (integers =  and ). So, the answer is .

// Sample Input 1

// 4
// 3 4
// 2 1003
// 1 16
// 3 1
// Sample Output 1

// 0
// 1
// Explanation 1

// For the first query of type , there is no integer of frequency . The answer is . For the second query of type , there is one integer,  of frequency  so the answer is .

// Sample Input 2

// 10
// 1 3
// 2 3
// 3 2
// 1 4
// 1 5
// 1 5
// 1 4
// 3 2
// 2 4
// 3 2
// Sample Output 2

// 0
// 1
// 1
// Explanation 2

// When the first output query is run, the array is empty. We insert two 's and two 's before the second output query,  so there are two instances of elements occurring twice. We delete a  and run the same query. Now only the instances of  satisfy the query.

// SOLUTION

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> frequencyQuery;
    map<int, map<int, int>> bi_freq_query;
    vector<int> result;
    
    for(auto el : queries)
    {
        if(el[0] == 1)
        {
            bi_freq_query[frequencyQuery[el[1]]].erase(el[1]);
            frequencyQuery[el[1]]++;
            bi_freq_query[frequencyQuery[el[1]]][el[1]] = 1;
        }
        else if (el[0] == 2)
        {
            if(frequencyQuery[el[1]] > 0)
            {
                bi_freq_query[frequencyQuery[el[1]]].erase(el[1]);
                frequencyQuery[el[1]]--;
                bi_freq_query[frequencyQuery[el[1]]][el[1]] = 1;
            }   
        }
        else if (el[0] == 3)
        {
            if(bi_freq_query[el[1]].size() != 0)
            {
                result.push_back(1);
            }
            else 
            {
                result.push_back(0);
            }
        }
    }
    return result;

}