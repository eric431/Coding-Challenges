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



// Sample Input 0

// 3
// 2147483647
// 1
// 0
// Sample Output 0

// 2147483648
// 4294967294
// 4294967295
// Explanation 0







// Sample Input 1

// 2
// 4
// 123456
// Sample Output 1

// 4294967291
// 4294843839
// Explanation 1





// Sample Input 2

// 3
// 0
// 802743475
// 35601423
// Sample Output 2

// 4294967295
// 3492223820
// 4259365872
// Explanation 2


// SOLUTION - FURTHER OPTIMIZATION required

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {
    vector<bool> n_bit(32);
    bool rem = 0;
    int idx = 0;
    long flipped_long = 0, pow = 1;
    
    while(n != 0 || rem != 0)
    {
        rem = n % 2;
        n_bit[idx] = rem;
        n /= 2;
        idx++;
    }
    n_bit.flip();

    for(auto i = 0; i < n_bit.size(); i++)
    {
        flipped_long += n_bit[i] * pow;
        pow *= 2;
    }
    return flipped_long;
}