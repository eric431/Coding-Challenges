/*
VWAPer v0.1

Read file in with the following format:
[Stock],[Interval],[Volume Traded],[High],[Low]

Calculate the total volume traded per Stock
Calculate the total volume traded per Stock&Interval

Write the total volume traded per Stock&Interval as a percentage of the total volume traded per Stock to stdout:
[Stock],[Interval],[%Volume Traded]

Write the delimiter '#' to stdout

Write the maximum High and minimum Low for each Stock to stdout:
[Stock],[Day High],[Day Low]

Example input:
VOD.L 1 100 184 183.7
BT.LN 1 300 449.4 448.2
VOD.L 2 25 184.1 182.4
BT.LN 2 900 449.8 449.5

Example output:
VOD.L,1,80
BT.LN,1,25
VOD.L,2,20
BT.LN,2,75
#
VOD.L,184.1,182.4
BT.LN,449.8,448.2
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>

#define DELIMITER "#"
#define MAX_SIZE 1000 // Assume that the ticket description for VWAPer is given a max size of 1000 hence the motivation for the intern to use 1000
// otherwise std::vector could be used instead

class VWAP
{
public:
    VWAP(const char* file_name) 
    : m_num_trades(0)
    , m_current_low(std::numeric_limits<float>::max())
    , m_current_high(0) {
        FILE*	file = fopen(file_name, "r");
    
        char line[256];

        int i {0};
        while (fgets(line, 256, file))
        {
            sscanf(line, "%s %d %d %f %f",
                   Stocks[i], &Intervals[i],
                   &Volumes[i], &Highs[i], &Lows[i]);

            m_total_volume[Stocks[i]] += Volumes[i];
    
            // this->updateHighLow(Highs[i], Lows[i]);

            m_high_low[Stocks[i]] = std::make_pair(Highs[i], Lows[i]);

            ++i;
        }

        m_num_trades = i;
    };

    void add(float nHigh, float nLow)
    {
        if (nHigh > m_current_high)
        {
            m_current_high = nHigh;
        }

        if (nLow < m_current_low)
        {
            m_current_low = nLow;
        }
    }

    void updateHighLow(double nHigh, double nLow)
    {
        if (nHigh > m_current_high)
        {
            m_current_high = nHigh;
        }

        if (nLow < m_current_low)
        {
            m_current_low = nLow;
        }
    }

    void printPercentageVolume()
    {
        for (int i = 0; i < m_num_trades; ++i)
        {
            std::cout << Stocks[i] << "," << Intervals[i] << "," <<
                    static_cast<double>(Volumes[i]) / m_total_volume[Stocks[i]] * 100 << std::endl;
        }        
    }

    void printHighLow()
    {
        for(auto& [stock, high_low] : m_high_low)
        {
            std::cout << stock << "," << high_low.first << "," <<
            high_low.second << std::endl;            
        }
    }

    double getSum()
    {
        float sum = m_current_high + m_current_low;
        return sum;
    }

private:
    char	Stocks[MAX_SIZE][10];
    int     Intervals[MAX_SIZE];
    int     Volumes[MAX_SIZE];
    double	Highs[MAX_SIZE];
    double	Lows[MAX_SIZE];

    int m_num_trades {};
    double m_current_low {}; 
    double m_current_high {};

    std::unordered_map<std::string, int> m_total_volume {};
    std::unordered_map<std::string, std::pair<double, double>> m_high_low {};
};

int main(int argc, char* argv[])
{
    FILE*	file = fopen(argv[2], "r");

    char	line[256];
    char	Stocks[MAX_SIZE][10];
    int     Intervals[MAX_SIZE];
    int     Volumes[MAX_SIZE];
    float	Highs[MAX_SIZE];
    float	Lows[MAX_SIZE];

    int     i = 0;

    while (fgets(line, 256, file))
    {
        sscanf(line, "%s %d %d %f %f",
               Stocks[i], &Intervals[i],
               &Volumes[i], &Highs[i], &Lows[i]);

        ++i;
    }

    std::unordered_map<std::string, int> TotalVolumes;

    for (int s = 0; s < i; ++s)
    {
        TotalVolumes[Stocks[s]] += Volumes[s];
    }

    std::unordered_map<std::string, DailyHighLows> HighLows;

    for (int s = 0; s < i; ++s)
    {
        HighLows[Stocks[s]].add(Highs[s], Lows[s]);
    }

    for (int s = 0; s < i; ++s)
    {
        std::cout << Stocks[s] << "," << Intervals[s] << "," <<
                static_cast<float>(Volumes[s]) / TotalVolumes[Stocks[s]] * 100 << std::endl;
    }

    std::cout << DELIMITER << std::endl;

    std::unordered_map<std::string, DailyHighLows>::iterator itr = HighLows.begin();
    while (itr != HighLows.end())
    {
        std::cout << itr->first << "," << itr->second.m_current_high << "," <<
                itr->second.m_current_low << std::endl;

        ++itr;
    }

    return 0;
}
