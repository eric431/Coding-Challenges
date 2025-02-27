/**
 * @file VWAPer.cpp
 * @brief Read file in with the following format:
 * [Stock],[Interval],[Volume Traded],[High],[Low]
 * 
 * Calculate the total volume traded per Stock
 * Calculate the total volume traded per Stock&Interval
 * 
 * Write the total volume traded per Stock&Interval as a percentage of 
 * the total volume traded per Stock to stdout:
 * [Stock],[Interval],[%Volume Traded]
 * 
 * Write the delimiter '#' to stdout
 * 
 * Write the maximum High and minimum Low for each Stock to stdout:
 * [Stock],[Day High],[Day Low]
 * 
 * Example input:
 * VOD.L 1 100 184 183.7
 * BT.LN 1 300 449.4 448.2
 * VOD.L 2 25 184.1 182.4
 * BT.LN 2 900 449.8 449.5
 * 
 * Example output:
 * VOD.L,1,80
 * BT.LN,1,25
 * VOD.L,2,20
 * BT.LN,2,75
 * #
 * VOD.L,184.1,182.4
 * BT.LN,449.8,448.2
 * 
 * Example usage 1:
 *  const char* file_name = "Input.text";
 *  std::unique_ptr<VWAP> vwap(new VWAP(file_name));
 *  vwap->print_interval_volume_weights();
 *  std::cout << DELIMITER << std::endl;
 *  vwap->print_high_low();
 *  
 * Example usage 2:
 * VWAPer "example_file_name.txt"
 * 
 * @note Assumptions:
 * - Daily ticker data does not exceed 1000
 * - Order in which maximum high and low for each stock is returned is      
 *   irrelevant, priority is on correct pricing, as problem description does
 *   not explicitly mention order
 * - Modern C++ is used
 * - STL coding Standard use, i.e. snake_case naming for functions and
 *   variables
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <memory>

#define DELIMITER "#"
#define MAX_SIZE 1000 // Assume 1000 represents the maximum number of ticker data per day.

typedef std::pair<double, double> high_low;

/**
 * @class VWAP
 * @brief A class to read in daily stock prices and print the daily
 * high and lows for each stock, as well as its weighted volume over
 * the day
 */
class VWAP
{
public:
   /**
    * @brief Constructor to initialize the VWAP object
    * @param file_name The name of the file from which daily stock prices
    * are stored
    * @throws int if file contains corrupted data such as negative volume or
    * prices and unparseable data
    * 
    */
    VWAP(const char* file_name) 
    : m_num_trades(0) {
        std::ifstream file(file_name);
    
        std::string line;

        int i {0};

        // replaced fgets with getline to use std::istringstream
        while (std::getline(file, line))
        {
            // Replaced sscanf with std::istringstream to add exception 
            // throwing functionality for data that cannot be correctly parsed.
            std::istringstream iss(line);
            
            if (!(iss >> m_stocks[i] >> m_intervals[i] >> m_volumes[i] >> m_highs[i] >> m_lows[i]))
            {
                throw(1);
            }
            else if (m_volumes[i] <= 0)
            {
                throw(2);
            }
            else if (m_highs[i] < 0 || m_lows[i] < 0)
            {
                throw(3);
            }

            m_total_volume[m_stocks[i]] += m_volumes[i];

            if (!m_high_low.count(m_stocks[i]))
            {
                m_high_low[m_stocks[i]] = std::make_pair(m_highs[i], m_lows[i]);
            }
            else 
            {
                this->update_high_low(m_stocks[i], m_highs[i], m_lows[i]);
            }

            ++i;
        }

        m_num_trades = i;
    }

   /**
    * @brief Method to update the observed high and low stock prices for 
    * each interval
    *
    * @param[in] stock, the stock name to update
    * @param[in] high, the highest observed price for the interval
    * @param[in] low, the lowest observed price for each interval
    */
    void update_high_low(std::string stock, double high, double low)
    {
        if (high > m_high_low[stock].first)
        {
            m_high_low[stock].first = high;
        }

        if (low < m_high_low[stock].second)
        {
            m_high_low[stock].second = low;
        }
    }

   /**
    * @brief Method to print the weighted volume for the stocks at each 
    * time interval
    * @throw Error code 4: if total volume is 0 to avoid division by 0 error
    */
    void print_interval_volume_weights()
    {
        for (int i = 0; i < m_num_trades; ++i)
        {
            if(m_total_volume[m_stocks[i]] == 0)
            {
                throw(4);
            }

            std::cout << m_stocks[i] << "," << m_intervals[i] << "," <<
                    static_cast<double>(m_volumes[i]) / m_total_volume[m_stocks[i]] * 100 << std::endl;
        }
    }

    /**
     * @brief Method to print the observed highest and lowest price for the 
     * stocks over the day.
    */
    void print_high_low()
    {
        for (auto& [stock, high_low] : m_high_low)
        {
            std::cout << stock << "," << high_low.first << "," <<
            high_low.second << std::endl;            
        }
    }

   /**
     * @brief Method to update the observed high and low stock prices for 
     * each interval
     *
     * @param[in] stock, the stock name to update
     * @return high, the highest observed price for day for the stock
    */
    double get_daily_high(std::string stock)
    {
        return m_high_low[stock].first;
    }

   /**
     * Method to update the observed high and low stock prices for each interval
     *
     * @param[in] stock, the stock name
     * @return high, the lowest observed price for day for the stock
    */
    double get_daily_low(std::string stock)
    {
        return m_high_low[stock].first;
    }

private:
    char	m_stocks[MAX_SIZE][10];
    int     m_intervals[MAX_SIZE];
    int     m_volumes[MAX_SIZE];
    double	m_highs[MAX_SIZE];
    double	m_lows[MAX_SIZE];

    int     m_num_trades {};

    std::unordered_map<std::string, int> m_total_volume {};
    std::unordered_map<std::string, high_low> m_high_low {};
};

int main(int argc, char* argv[])
{
    try
    {
        // unique_ptr used to ensure only one instance of this class is 
        // running 
        std::unique_ptr<VWAP> vwap(new VWAP(argv[1]));

        vwap->print_interval_volume_weights();
        std::cout << DELIMITER << std::endl;
        vwap->print_high_low();
    }
    catch(int x)
    {
        if(x == 1)
        {
            std::cerr << "Error code (1): Corrupted data! Unable to parse due to incorrect data type" << std::endl;  
        }
        else if(x == 2)
        {
            std::cerr << "Error code (2): Corrupted data! Volume cannot be negative nor can it be zero." << std::endl;
        }
        else if(x == 2)
        {
            std::cerr << "Error code (3): Corrupted data! stock price is negative." << std::endl;                
        }
        else if(x == 5)
        {
            std::cerr << "Error code (4): Division by zero! File may contain corrupted or missiing volume data." << std::endl; 
        }
    }

    return 0;
}
