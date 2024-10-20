// Seven different symbols represent Roman numerals with the following values:

// Symbol	Value
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000
// Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

// If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
// If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
// Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
// Given an integer, convert it to a Roman numeral.

 

// Example 1:

// Input: num = 3749

// Output: "MMMDCCXLIX"

// Explanation:

// 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC as 500 (D) + 100 (C) + 100 (C)
//   40 = XL as 10 (X) less of 50 (L)
//    9 = IX as 1 (I) less of 10 (X)
// Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
// Example 2:

// Input: num = 58

// Output: "LVIII"

// Explanation:

// 50 = L
//  8 = VIII
// Example 3:

// Input: num = 1994

// Output: "MCMXCIV"

// Explanation:

// 1000 = M
//  900 = CM
//   90 = XC
//    4 = IV
 

// Constraints:

// 1 <= num <= 3999

// This code can be otimized further by integereting the second loop into the first loop, however optimize outsid eof leetcode in order to prevent
// potential plagiarism

class Solution {
public:
    map<int, char> num_map = {{1, 'I'},
                              {5, 'V'},
                              {10, 'X'},
                              {50, 'L'},
                              {100, 'C'},
                              {500, 'D'},
                              {1000, 'M'}};

    string intToRoman(int num) {
        string roman_numeral = "";

        int num_copy = num, r;
        vector<int> place_val;

        while(true)
        {
            r = num_copy % 10;
            if(num_copy == 0 && r == 0) break;
            place_val.push_back(r);
            num_copy /= 10;
        }

        int val, power = 1;;
        for(auto i = 0; i < place_val.size(); ++i)
        {
            if(place_val[i] == 0) 
            {
                power *= 10;
                continue;
            }
            val = (place_val[i] + 1) * power;
            if (val != 1 && num_map.count(val) != 0)
            {
                char subt_ = num_map[power];
                roman_numeral += num_map[val];
                roman_numeral += subt_;
            }
            else 
            {
                val = place_val[i] * power;
                if(num_map.count(val) != 0)
                {
                    roman_numeral += num_map[val];
                }
                else if(place_val[i] > 5)
                {
                    int j = 0;
                    while(j < (place_val[i] - 5))
                    {
                        roman_numeral += num_map[power];
                        ++j;
                    }

                    int num_ = 5 * power;
                    roman_numeral += num_map[num_];
                }
                else if (place_val[i] < 4)
                {
                    int j = 0;
                    while(j < place_val[i])
                    {
                        roman_numeral += num_map[power];
                        ++j;
                    }
                }
            }
            power *= 10;
        }

        string rom_num = "";
        for(int i = roman_numeral.size() - 1; i >= 0; i--)
        {
            rom_num += roman_numeral[i];
        }
        return rom_num;
    }
};