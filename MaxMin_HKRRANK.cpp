// // HACKERRANK 

// You will be given a list of integers, , and a single integer . You must create an array of length  from elements of  such that its unfairness is minimized. Call that array . Unfairness of an array is calculated as

// Where:
// - max denotes the largest integer in 
// - min denotes the smallest integer in 

// Example



// Pick any two elements, say .

// Testing for all pairs, the solution  provides the minimum unfairness.

// Note: Integers in  may not be unique.

// Function Description

// Complete the maxMin function in the editor below.
// maxMin has the following parameter(s):

// int k: the number of elements to select
// int arr[n]:: an array of integers
// Returns

// int: the minimum possible unfairness
// Input Format

// The first line contains an integer , the number of elements in array .
// The second line contains an integer .
// Each of the next  lines contains an integer  where .

// Constraints




// Sample Input 0

// 7
// 3
// 10
// 100
// 300
// 200
// 1000
// 20
// 30
// Sample Output 0

// 20
// Explanation 0

// Here ; selecting the  integers , unfairness equals

// max(10,20,30) - min(10,20,30) = 30 - 10 = 20
// Sample Input 1

// 10
// 4
// 1
// 2
// 3
// 4
// 10
// 20
// 30
// 40
// 100
// 200
// Sample Output 1

// 3
// Explanation 1

// Here ; selecting the  integers , unfairness equals

// max(1,2,3,4) - min(1,2,3,4) = 4 - 1 = 3
// Sample Input 2

// 5
// 2
// 1
// 2
// 1
// 2
// 1
// Sample Output 2

// 0
// Explanation 2

// Here .  or  give the minimum unfairness of .

// SOLUTION

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min_unfairness = std::numeric_limits<int>::max();
    int unfair_tmp = 0;
    for(int i = 0; i < arr.size() - (k - 1); i++)
    {
        unfair_tmp = arr[i + k - 1] - arr[i];
        if(unfair_tmp < min_unfairness)
        {
            min_unfairness = unfair_tmp;
        }
    }
    
    return min_unfairness;
}
