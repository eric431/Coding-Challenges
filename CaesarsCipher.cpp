/*
Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's cipher shifts each letter by a number of letters. If the shift takes you past the end of the alphabet, just rotate back to the front of the alphabet. In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc
Example


The alphabet is rotated by , matching the mapping above. The encrypted string is .

Note: The cipher only encrypts letters; symbols, such as -, remain unencrypted.

Function Description

Complete the caesarCipher function in the editor below.

caesarCipher has the following parameter(s):

string s: cleartext
int k: the alphabet rotation factor
Returns

string: the encrypted string
Input Format

The first line contains the integer, , the length of the unencrypted string.
The second line contains the unencrypted string, .
The third line contains , the number of letters to rotate the alphabet by.

Constraints



 is a valid ASCII string without any spaces.

Sample Input

11
middle-Outz
2
Sample Output

okffng-Qwvb
Explanation

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +2:    cdefghijklmnopqrstuvwxyzab

m -> o
i -> k
d -> f
d -> f
l -> n
e -> g
-    -
O -> Q
u -> w
t -> v
z -> b
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    string encrypted_string{};
    
    for(auto& el : s)
    {
        if((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z'))
        {
            if(el >= 'a' && el <= 'z' && el + k > 'z')
            {
                encrypted_string += 'a' + (el + k - 'z' - 1) % 26;
            }
            else if(el >= 'A' && el <= 'Z' && el + k > 'Z')
            {
                encrypted_string += 'A' + (el + k - 'Z' - 1) % 26;
            }
            else 
            {
                encrypted_string += el + k;              
            }
        }
        else {
            encrypted_string += el;
        }
    }
    
    return encrypted_string;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

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


// Alternative implementation

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    string encrypted_string = "";
    
    char start_lowercase_alpha = 'a';
    char end_lowercase_alpha = 'z';
    
    char start_uppercase_alpha = 'A';
    char end_uppercase_alpha = 'Z';
    for(auto i{0}; i < s.size(); ++i)
    {
        if((s[i] >= start_lowercase_alpha && s[i] <= end_lowercase_alpha) || (s[i] >= start_uppercase_alpha && s[i] <= end_uppercase_alpha))
        {
            if (s[i] >= start_lowercase_alpha)
            {
                int rem = (s[i] + k - (start_lowercase_alpha)) % 26;
                encrypted_string += (start_lowercase_alpha + rem);                
            }
            else if(s[i] >= start_uppercase_alpha)
            {
                int rem = (s[i] + k - (start_uppercase_alpha)) % 26;
                encrypted_string += (start_uppercase_alpha + rem);
            }
        }
        else {
            encrypted_string += s[i];
        }
    }
    
    return encrypted_string;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

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
