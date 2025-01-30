// Kadanes Algorithm for a window of size k

/*
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.
Input: arr[] = [100, 200, 300, 400] , k = 4
Output: 1000
Explanation: arr1 + arr2 + arr3 + arr4 = 1000, which is maximum.
Input: arr[] = [100, 200, 300, 400] , k = 1
Output: 400
Explanation: arr4 = 400, which is maximum.
Constraints:
1 <= arr.size() <= 106
1 <= arr[i]<= 106
1 <= k<= arr.size()
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        
        int max_sum{0};
        int curr_sum{0};
        
        int i{0}, j{0};
        for(; j < arr.size(); ++j)
        {
            curr_sum = max(curr_sum + arr[j], arr[j]);
            max_sum = max(max_sum, curr_sum);
            
            if(j - i + 1 == k && curr_sum > 0)
            {
                curr_sum -= arr[i];
                ++i;
            }
            else if(curr_sum < 0)
            {
                curr_sum = 0;
                i = j + 1;
            }
        }
        
        return max_sum;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends