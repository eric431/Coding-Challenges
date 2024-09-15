// HACKERRANK

// Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back to him through his handwriting. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use only whole words available in the magazine. He cannot use substrings or concatenation to create the words he needs.

// Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

// Example
//  = "attack at dawn"  = "Attack at dawn"

// The magazine has all the right words, but there is a case mismatch. The answer is .

// Function Description

// Complete the checkMagazine function in the editor below. It must print  if the note can be formed using the magazine, or .

// checkMagazine has the following parameters:

// string magazine[m]: the words in the magazine
// string note[n]: the words in the ransom note
// Prints

// string: either  or , no return value is expected
// Input Format

// The first line contains two space-separated integers,  and , the numbers of words in the  and the , respectively.
// The second line contains  space-separated strings, each .
// The third line contains  space-separated strings, each .

// Constraints

// .
// Each word consists of English alphabetic letters (i.e.,  to  and  to ).
// Sample Input 0

// 6 4
// give me one grand today night
// give one grand today
// Sample Output 0

// Yes
// Sample Input 1

// 6 5
// two times three is not four
// two times two is four
// Sample Output 1

// No
// Explanation 1

// 'two' only occurs once in the magazine.

// Sample Input 2

// 7 4
// ive got a lovely bunch of coconuts
// ive got some coconuts
// Sample Output 2

// No
// Explanation 2

// Harold's magazine is missing the word .

// SOLUTION

/*
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */

void checkMagazine(vector<string> magazine, vector<string> note) {
    if(note.size() > magazine.size()) 
    {
        cout << "No" << endl;
        return;
    }
    
    map<string, int> note_map, magazine_map;
    for(int i = 0; i < magazine.size(); i++)
    {
        magazine_map[magazine[i]]++;
        if(i < note.size())
        {
            note_map[note[i]]++;
        }
    }
    
    for(auto& [k, v] : note_map)
    {
        if(magazine_map[k] != 0 && magazine_map[k] >= v)
        {
            continue;
        }
        cout << "No" << endl;
        return;
    }
    
    cout << "Yes" << endl;
}