/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

Example




There are  and  cylinders in the three stacks, with their heights in the three arrays. Remove the top 2 cylinders from  (heights = [1, 2]) and from  (heights = [1, 1]) so that the three stacks all are 2 units tall. Return  as the answer.

Note: An empty stack is still a stack.

Function Description

Complete the equalStacks function in the editor below.

equalStacks has the following parameters:

int h1[n1]: the first array of heights
int h2[n2]: the second array of heights
int h3[n3]: the third array of heights
Returns

int: the height of the stacks when they are equalized
Input Format

The first line contains three space-separated integers, , , and , the numbers of cylinders in stacks , , and . The subsequent lines describe the respective heights of each cylinder in a stack from top to bottom:

The second line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
The third line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
The fourth line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
Constraints

Sample Input

STDIN       Function
-----       --------
5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4  
3 2 1 1 1   h1 = [3, 2, 1, 1, 1]
4 3 2       h2 = [4, 3, 2]
1 1 4 1     h3 = [1, 1, 4, 1]
Sample Output

5
Explanation

Initially, the stacks look like this:

initial stacks

To equalize thier heights, remove the first cylinder from stacks  and , and then remove the top two cylinders from stack  (shown below).

modified stacks

The stack heights are reduced as follows:

All three stacks now have , the value to return.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    stack<int> stack_height{};
    
    int i = h1.size() - 1;
    int j = h2.size() - 1;
    int k = h3.size() - 1;    
    // calculate suffix_sums
    vector<int> h1_s(h1.size());
    vector<int> h2_s(h2.size());
    vector<int> h3_s(h3.size());
    while(true)
    {
        if(i + 1 < h1.size()) h1_s[i] = h1[i] + h1_s[i + 1];
        else h1_s[i] = h1[i];
        
        if(j + 1 < h2.size()) h2_s[j] = h2[j] + h2_s[j + 1];
        else h2_s[j] = h2[j];
    
        if(k + 1 < h3.size()) h3_s[k] = h3[k] + h3_s[k + 1];
        else h3_s[k] = h3[k];
        
        if(i == 0 && j == 0 && k == 0) break;        
        
        if(i > 0) --i;
        if(j > 0) --j;
        if(k > 0) --k;
    } 
    
    i = h1.size() - 1;
    j = h2.size() - 1;
    k = h3.size() - 1;
    int m{}; // max equal height
    for(; i > -1 && j > -1 && k > -1;)
    {
        m = max({h1_s[i], h2_s[j], h3_s[k]});
        if(h1_s[i] < m) --i;
        if(h2_s[j] < m) --j;
        if(h3_s[k] < m) --k;
        
        if((i == 0 && j == 0 && k == 0) && (h1_s[i] == m && h2_s[j] == m && h3_s[k] == m))
        {
            stack_height.push(m);
            break;
        }
        else if(i == 0 && j == 0 && k == 0)
        {
            break;
        }
        else if(h1_s[i] == m && h2_s[j] == m && h3_s[k] == m) {
            stack_height.push(m);
            if(i > 0)--i;
            if(j > 0) --j;
            if(k > 0) --k;
        }
    }
    
    // if(i == -1 && j == -1 && k == -1) return 0;
    // else return stack_height.top();
    if(stack_height.empty()) return 0;
    else return stack_height.top();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

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
