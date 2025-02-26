#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <string>


// File desctiption should be added to before includes and use /* instead of /**
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

using namespace std; // it is bad practice to call in global namespace due to the risk of accessing functions with the same name in the std namespace

typedef basic_string<char> string; // string already exists without the typedef/ unnecessary spacing 

// Inconsistent use of spacingscope brackets

// class name is ambiguous and does not make it easily clear its function
class	CUpperLower // unnecessary spacing 
{
public:
    CUpperLower() : nCurLwr(0), nCurUpr(0) {}; // intiailising nCurLwr to 0 will never update nCurLwr unless 

    // implicit argument conversion of High and Low, leading to loss of data
    // poor naming convention, what is being added?
    void	add(int nHigh, int nLow) // inconsistent and unnecessary spacing
    {
        if (nHigh > nCurUpr) // Inconsistent use of scope brackets
            nCurUpr = nHigh;

        if (nLow < nCurLwr) // Inconsistent use of scope brackets
            nCurLwr = nLow;
    }

    // wrong type returned
    int& getSum() // returning sum by reference can lead to destruction of element before its use leading to a dangling reference
    {
        int sum = nCurLwr + nCurUpr;
        return sum;
    }

    int         nCurLwr; // improper and unnecessary spacing
    int         nCurUpr; // improper and unnecessary spacing
};

int main(int argc, char* argv[])
{
    // If statement is not necessary within the confines of the problem description described above
    // Also logically, what would be the reason for checking the version number if all we always want to use the most up-to-date VWAPer
    if (!strcmp("version", argv[1]))
    {
        cerr << "VWAPer version 0.1" << endl; // error log line is ambiguous and not descriptive
        return 0; // return 0 means the function executed successfully, which is not what is intended, instead return 1
    }

    FILE*	file = fopen(argv[2], "r");

    cerr << "Reading file" << argv[2] << endl; // log lines need to be removed in production code
    // lack of spacing between file and argv[2] can make reading the output unclear

    // Use of magic numbers is not good practice, as if there is a change in code requirements then new developers will have to manually update every occurrence of the magic number, it is also not self explanatory why 1000 has been chosen.
    char	line[256];
    char	Stocks[1000][10]; // use of an array without dynamic updates leads to errors when a file size containing more than 1000 stocks is given, use vector instead
    int         Intervals[1000]; // Inconsistent and unnecessary use of space
    int         Volumes[1000]; // Inconsistent and unnecessary use of space
    float	Highs[1000];
    float	Lows[1000];

    int         i = 0;
    int         sum = 0; // No need for sum as it is not used for any calculations

    while (fgets(line, 256, file))
    {
        sscanf(line, "%s %d %d %f %f",
               Stocks[i], &Intervals[i],
               &Volumes[i], &Highs[i], &Lows[i++]); // incrementing i as a parameter increments location that sscanf writes to
    }

    cerr << "Calculating total volumes" << endl; // log lines need to be removed in production code

    // Use unordered_map when the use case is retrieving the values associated with a key as it is more efficient with a O(1) access time complexity
    map<std::string, int>		TotalVolumes; // Inconsistent and unnecessary use of space

    for (int s = 0; s <= i; ++s)
    {
        // naming convention is inefficient 
        // Use snake case naming is preferred
        std::string	stockname = Stocks[s]; // use of std namespace when it has already been given access on line 43
        // either use the namespaces specifier or don't but ensure consistency

        // This code block is unnecessary and leads to multiple summation,
        // the desired result can be achieved by adding Volumes[s] to the corresponding key entry for TotalVolumes
        for (int j =0; j <= i; ++j) // inconsistent spacing between = and 0
        {
            if (!strcmp(Stocks[j], stockname.c_str()))
            {
                TotalVolumes[stockname] += Volumes[j];
            }
        }
    }

    cerr << "Calculating high lows" << endl; // log lines need to be removed

    map<std::string, CUpperLower>	HighLows;

    for (int s = 0; s <= i; ++s)
    {
        HighLows[Stocks[s]].add(Highs[s], Lows[s]); 
        cout << HighLows[Stocks[s]].getSum(); 
    }

    cerr << "Writing files" << endl; // Log lines need to be renmoved in production code 

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
                (*itr).second.nCurUpr << endl; // Highs should be printed first, followed by lows

        ++itr;
    }

    return 1; // function should return 0 at the end if executed successfully
}
