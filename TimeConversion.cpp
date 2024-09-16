// HACKERRANK

// Given a time in -hour AM/PM format, convert it to military (24-hour) time.

// Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
// - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

// Example


// Return '12:01:00'.


// Return '00:01:00'.

// Function Description

// Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

// timeConversion has the following parameter(s):

// string s: a time in  hour format
// Returns

// string: the time in  hour format
// Input Format

// A single string  that represents a time in -hour clock format (i.e.:  or ).

// Constraints

// All input times are valid
// Sample Input

// 07:05:45PM
// Sample Output

// 19:05:45


// SOLUTION
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string converted_time = "";

    int mil_time = 0;
    for(auto i = 0; i < (int)s.size() - 2; ++i)
    {
        if(i < 2)
        {
            mil_time *= 10;
            mil_time += (s[i] - '0') - ('0' - '0'); 
        }
        else if (i == 2)
        {  
            if(s[s.size() - 2] == 'P')
            {    
                if(mil_time < 12)      
                    mil_time += 12;
                mil_time %= 24; 
            }
            else if(s[s.size() - 2] == 'A')
            {     
                mil_time %= 12;
            }
            if(mil_time < 10)
            {
                converted_time += '0';
            }
            converted_time += to_string(mil_time);
            converted_time += s[i];
        }
        else 
        {
            converted_time += s[i];
        }
    }      
    return converted_time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
