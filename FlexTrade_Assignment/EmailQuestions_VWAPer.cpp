#include <cstdio> 
#include <cstring>
#include <map>
#include <iostream>
#include <string>


/**
VWAPer v0.1

// Read file in with the following format:
// [Stock],[Interval],[Volume Traded],[High],[Low]

// Calculate the total volume traded per Stock
// Calculate the total volume traded per Stock&Interval

// Write the total volume traded per Stock&Interval as a percentage of the total volume traded per Stock to stdout:
// [Stock],[Interval],[%Volume Traded]

// Write the delimiter '#' to stdout

// Write the maximum High and minimum Low for each Stock to stdout:
// [Stock],[Day High],[Day Low]

// example input:
VOD.L 1 100 184 183.7
BT.LN 1 300 449.4 448.2
VOD.L 2 25 184.1 182.4
BT.LN 2 900 449.8 449.5

// example output:
VOD.L,1,80
BT.LN,1,25
VOD.L,2,20
BT.LN,2,75
#
VOD.L,184.1,182.4
BT.LN,449.8,448.2

**/

#define DELIMITER "#"

using namespace std;

typedef basic_string<char> string; 

class	CUpperLower
{
public:
    CUpperLower() : nCurLwr(0), nCurUpr(0) {};


    void	add(int nHigh, int nLow)
    {
        if (nHigh > nCurUpr)
            nCurUpr = nHigh;

        if (nLow < nCurLwr) 
            nCurLwr = nLow;
    }

    int& getSum() 
    {
        int sum = nCurLwr + nCurUpr;
        return sum;
    }

    int         nCurLwr; 
    int         nCurUpr; 
};

int main(int argc, char* argv[])
{
    if (!strcmp("version", argv[1]))
    {
        cerr << "VWAPer version 0.1" << endl; 
        return 0; 
    }

    FILE*	file = fopen(argv[2], "r");

    cerr << "Reading file" << argv[2] << endl; 

    char	line[256];
    char	Stocks[1000][10]; 
    int         Intervals[1000]; 
    int         Volumes[1000];
    float	Highs[1000];
    float	Lows[1000];

    int         i = 0;
    int         sum = 0; 

    while (fgets(line, 256, file))
    {
        sscanf(line, "%s %d %d %f %f",
               Stocks[i], &Intervals[i],
               &Volumes[i], &Highs[i], &Lows[i++]); 
    }

    cerr << "Calculating total volumes" << endl; 

    map<std::string, int>		TotalVolumes; 

    for (int s = 0; s <= i; ++s)
    {
        std::string	stockname = Stocks[s]; 

        for (int j =0; j <= i; ++j)
        {
            if (!strcmp(Stocks[j], stockname.c_str()))
            {
                TotalVolumes[stockname] += Volumes[j];
            }
        }
    }

    cerr << "Calculating high lows" << endl;

    map<std::string, CUpperLower>	HighLows;

    for (int s = 0; s <= i; ++s)
    {
        HighLows[Stocks[s]].add(Highs[s], Lows[s]); 
        cout << HighLows[Stocks[s]].getSum(); 
    }

    cerr << "Writing files" << endl; 

    for (int s = 0; s <= i; ++s)
    {
        cout << Stocks[s] << "," << Intervals[s] << "," <<
                TotalVolumes[Stocks[s]] / Volumes[s] * 100 << endl;
    }

    cout << DELIMITER << endl;

    map<std::string, CUpperLower>::iterator itr = HighLows.begin();
    while (itr != HighLows.end())
    {
        cout << (*itr).first << "," << (*itr).second.nCurLwr << "," <<
                (*itr).second.nCurUpr << endl; 

        ++itr;
    }

    return 1;
}


/*
COMMENTS:
Directed towards intern.

I have left comments below highlighting areas of issue into three areas (coding practices, bugs and inefficiency), to enable you understand areas of improvement and how to improve.

CODING PRACTICES:
-----------------

* #include <cstdlib> and #include <cstring> are not necessary

* File description should be added before the libraries not after

* using namespace std in the global scope is controversial due to potential conflicts or ambiguity between function names, it is better to use the namespace in a local scope as opposed to global

* typedef of basic_string<char> on line 47 is not necessary, as the string library takes care of that for us

* Use of tabs for spacing is not good practice, in addition to the inconsistent spacing in different parts of the code

* Class name CUpperLower is bad naming, as it is not self evident what this does, a better name could have been `DailyHighLows` or StockHighLows`

* poor naming convention, as it is both inconsistent and snake_case naming should be used for functions and variables (assuming STL standards)

* Inconsistent use of scope braces, although this is not a semantic error, consistent coding standards should be followed.

* rather than implementing nCurLwr or nCurUpr as public variables, make them private and modify or view them using getter and setter methods.

* getSum() is a redundant method, you might have to explain to me your reasoning behind implementing this when it is not required as part of the file description.

* I am unsure why a check of the version if performed, there might be a valid reason, but sometimes it is best to leave comments in code for other engineers to easily follow the intentions and thought process behind your methods.
    - Following on, I would presume we would always want to use the most up-to-date version of VWAP, so why would a version check be necessary?

* Within the main function, several while loops are implemented for statements that can be moved to a single loop where the contents of the line are being read from the file.

* I noticed alot of cerr lines in your code, which I presume is due to you running tests of your code / breakpoints when running tests, however you should remove them before pushing to the repository for production ready code.

* Your class only contains public functions and only has one method, as such a struct could have been used instead.

* Use of magic numbers / literals is bad practice, because if you need to change the literal you will have to search codebase to find where you have implemented it, it is best to give literals a name that explains what it does or why it is a constant

* When printing high lows, pointer dereferencing is semantically valid, but it can also be achieved by -> which makes it neater.

BUGS:

* Lack of exception handling to handle or catch potential run-time bugs.

* getSum returns a reference to the sum, however this will lead to dangling references because the variable will be destroyed when it exits the scope

* The first bug I noticed is the use of the post incrementer in the sscanf function. Your desired behaviour is to increment `i` after reading in the file line into the arrays but in reality what happens is that i is incremented within the parameter, and as such the actual location of memeory you want to write to is ignored leaving garbage data for index 0, and shifting the actual data for each index forward.
    - Instead increment outside of the function after the appropriate lines have been read in.

* Use of sscanf can be problematic down the line as it does not throw an exception if there is an issue parsing the file. Instead it returns an error code which can make it difficult to deduce whether this from the actual data or from a parsing mismatch.

* When printing daily highs and lows, the order in which it is printed is not consistent with the problem description format, high prices should be returned first followed by low prices

* main returns 1 instead of 0, which signals that the code did not execute correctly, instead use 0 for successful execution and 1 for unsuccesful execution

INEFFIECNIES:

* Use of std::map is alright but has O(logn) time complexity for inserting and retrieval
    - std::unordered_map has amortized access and insertion times, in this code
    we do not care about order so unordered_map is better here.

*/