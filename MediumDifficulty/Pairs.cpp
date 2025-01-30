 /*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */
 int pairs(int k, vector<int> arr) {
    int num_pairs{0};
    sort(arr.begin(), arr.end());
    for(auto i{1}; i < arr.size(); ++i)
    {
        auto lb = lower_bound(arr.begin(), arr.end(), arr[i] - k);
        if(*lb == arr[i] - k) ++num_pairs;
    }
    return num_pairs;
 }