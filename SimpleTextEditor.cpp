/*
Implement a simple text editor. The editor initially contains an empty string, . Perform  operations of the following  types:

append - Append string  to the end of .
delete - Delete the last  characters of .
print - Print the  character of .
undo - Undo the last (not previously undone) operation of type  or , reverting  to the state it was in prior to that operation.
Example



operation
index   S       ops[index]  explanation
-----   ------  ----------  -----------
0       abcde   1 fg        append fg
1       abcdefg 3 6         print the 6th letter - f
2       abcdefg 2 5         delete the last 5 letters
3       ab      4           undo the last operation, index 2
4       abcdefg 3 7         print the 7th characgter - g
5       abcdefg 4           undo the last operation, index 0
6       abcde   3 4         print the 4th character - d
The results should be printed as:

f
g
d
Input Format

The first line contains an integer, , denoting the number of operations.
Each line  of the  subsequent lines (where ) defines an operation to be performed. Each operation starts with a single integer,  (where ), denoting a type of operation as defined in the Problem Statement above. If the operation requires an argument,  is followed by its space-separated argument. For example, if  and , line  will be 1 abcd.

Constraints

The sum of the lengths of all  in the input .
The sum of  over all delete operations .
All input characters are lowercase English letters.
It is guaranteed that the sequence of operations given as input is possible to perform.
Output Format

Each operation of type  must print the  character on a new line.

Sample Input

STDIN   Function
-----   --------
8       Q = 8
1 abc   ops[0] = '1 abc'
3 3     ops[1] = '3 3'
2 3     ...
1 xy
3 2
4 
4 
3 1
Sample Output

c
y
a
Explanation

Initially,  is empty. The following sequence of  operations are described below:

. We append  to , so .
Print the  character on a new line. Currently, the  character is c.
Delete the last  characters in  (), so .
Append  to , so .
Print the  character on a new line. Currently, the  character is y.
Undo the last update to , making  empty again (i.e., ).
Undo the next to last update to  (the deletion of the last  characters), making .
Print the  character on a new line. Currently, the  character is a.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class TextEditor
{
    string m_string {};
    stack<string> undo_history {};
    public:
        TextEditor(string& s){
            m_string = s;
        }
        
        TextEditor(){
            m_string = "";
            undo_history.push(m_string);
        }
        
        void append(string& w){
            m_string += w;
            undo_history.push(m_string);
        }
        
        void text_delete(int k){
            for(auto i {0}; i < k; ++i) {
                if(m_string == "") break;
                m_string.pop_back();   
            }
            
            undo_history.push(m_string);
        }
        
        char print(int k){
            return m_string[k - 1];    
        }        
        
        void undo() {
            if(!undo_history.empty()) {
                undo_history.pop();
                m_string = undo_history.top();                
            } else {
                m_string = "";
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    TextEditor editor;
    
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);
    
    int q = stoi(ltrim(rtrim(q_temp)));
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string input_temp;
        getline(cin, input_temp);

        vector<string> input = split(rtrim(input_temp));
        
        if (input[0] == "1") {
            editor.append(input[1]);
        } else if (input[0] == "2") {
            editor.text_delete(stoi(input[1]));
        } else if (input[0] == "3") {
            fout << editor.print(stoi(input[1])) << "\n";
        } else if (input[0] == "4") {
            editor.undo();
        }
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