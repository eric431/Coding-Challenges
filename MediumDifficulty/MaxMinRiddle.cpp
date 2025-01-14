// HACKERRANK 

// Given an integer array of size , find the maximum of the minimum(s) of every window size in the array. The window size varies from  to .

// For example, given , consider window sizes of  through . Windows of size  are . The maximum value of the minimum values of these windows is . Windows of size  are  and their minima are . The maximum of these values is . Continue this process through window size  to finally consider the entire array. All of the answers are .

// Function Description

// Complete the riddle function in the editor below. It must return an array of integers representing the maximum minimum value for each window size from  to .

// riddle has the following parameter(s):

// arr: an array of integers
// Input Format

// The first line contains a single integer, , the size of .
// The second line contains  space-separated integers, each an .

// Constraints



// Output Format

// Single line containing  space-separated integers denoting the output for each window size from  to .

// Sample Input 0

// 4
// 2 6 1 12
// Sample Output 0

// 12 2 1 1
// Explanation 0

// Here  and 

// window size	window1	window2	window3	window4	maximum of all windows
// 1	2	6	1	12	12
// 2	2	1	1		2
// 3	1	1			1
// 4	1				1
// Sample Input 1

// 7
// 1 2 3 5 1 13 3
// Sample Output 1

// 13 3 2 1 1 1 1
// Explanation 1

// Here  and 

// win size	w_1	w_2	w_3	w_4	w_5	w_6	w_7	maximum of all windows
// 1	1	2	3	5	1	13	3	13
// 2	1	2	3	1	1	3		3
// 3	1	2	1	1	1			2
// 4	1	1	1	1				1
// 5	1	1	1					1
// 6	1	1						1
// 7	1							1
// Sample Input 2

// 6
// 3 5 4 7 6 2
// Sample Output 2

// 7 6 4 4 3 2
// Explanation 2

// Here  and 

// win size	w_1	w_2	w_3	w_4	w_5	w_6	maximum of all windows
// 1	3	5	4	7	6	2	7
// 2	3	4	4	6	2		6
// 3	3	4	4	2			4
// 4	3	4	2				4
// 5	3	2					3
// 6	2	

// SOLUTION

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<long> riddle(vector<long>& arr)
{
    auto next_smallest_element = [&](vector<long>& arr)
    {
        stack<pair<long, int>> s_{};
        int sentinel_val{-1};
        vector<long> nse(arr.size(), sentinel_val);
        for(auto i{0}; i < arr.size(); ++i)
        {
            while(!s_.empty() && arr[i] < s_.top().first)
            {
                auto tmp = s_.top();
                s_.pop();
                
                int idx = tmp.second;
                nse[idx] = i - idx;
            }
            s_.push(make_pair(arr[i], i));
        }
        
        while(!s_.empty())
        {
            auto tmp = s_.top();
            s_.pop();
            
            int idx = tmp.second;
            nse[idx] = arr.size() - idx;   
        }
        return nse;
    };
  
    auto previous_smallest_element = [&](vector<long>& arr)
    {
        stack<pair<long, int>> s_{};
        int sentinel_val{-1};
        vector<long> lse(arr.size(), sentinel_val);
        for(int i = arr.size() - 1; i > -1; --i)
        {
            while(!s_.empty() && arr[i] < s_.top().first)
            {
                auto tmp = s_.top();
                s_.pop();
                
                int idx = tmp.second;
                lse[idx] = idx - i - 1;
            }
            s_.push(make_pair(arr[i], i));
        }
        
        while(!s_.empty())
        {
            auto tmp = s_.top();
            s_.pop();
            
            int idx = tmp.second;
            lse[idx] = idx;   
        }
        return lse;
    };    
    
    auto nse_ = next_smallest_element(arr);
    auto lse_ = previous_smallest_element(arr);
    
    vector<int> k_(arr.size());
    for(auto i{0}; i < k_.size(); ++i) k_[i] = nse_[i] + lse_[i];

    vector<long> ans_(k_.size(), -1);
    for(auto i{0}; i < ans_.size(); ++i) ans_[k_[i] - 1] = max(ans_[k_[i] - 1], arr[i]);
    
    for(int i = ans_.size() - 1; i > -1; --i)
    {
        if(ans_[i] == -1) ans_[i] = ans_[i + 1];
        else if(i < ans_.size() - 1) ans_[i] = max(ans_[i], ans_[i + 1]);
    }
    
    return ans_;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
