/*
You are planning production for an order. You have a number of machines that each have a fixed number of days to produce an item. Given that all the machines operate simultaneously, determine the minimum number of days to produce the required order.

For example, you have to produce  items. You have three machines that take  days to produce an item. The following is a schedule of items produced:

Day Production  Count
2   2               2
3   1               3
4   2               5
6   3               8
8   2              10
It takes  days to produce  items using these machines.

Function Description

Complete the minimumTime function in the editor below. It should return an integer representing the minimum number of days required to complete the order.

minimumTime has the following parameter(s):

machines: an array of integers representing days to produce one item per machine
goal: an integer, the number of items required to complete the order
Input Format

The first line consist of two integers  and , the size of  and the target production.
The next line contains  space-separated integers, .

Constraints

Output Format

Return the minimum time required to produce  items considering all machines work simultaneously.

Sample Input 0

2 5
2 3
Sample Output 0

6
Explanation 0

In  days  can produce  items and  can produce  items. This totals up to .

Sample Input 1

3 10
1 3 4
Sample Output 1

7
Explanation 1

In  minutes,  can produce  items,  can produce  items and  can produce  item, which totals up to .

Sample Input 2

3 12
4 5 6
Sample Output 2

20
Explanation 2

In  days  can produce  items,  can produce , and  can produce .
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long count_produced_items(unordered_map<long, long>& machine_map, long fastest_machine_rate)
{
    long produced_items{0};
    for(auto& el : machine_map)
    {
        produced_items += (fastest_machine_rate / el.first) * el.second;
    }
    return produced_items;
}

long localised_search(unordered_map<long, long>& machine_map, long lower, long upper, long goal)
{
    long produced_items{}, curr_rate{};
    for(auto i = lower; i <= upper; ++i)
    {
        produced_items = count_produced_items(machine_map, i);
        if(produced_items >= goal)
        {
            curr_rate = i;
            break;
        }
    }
    return curr_rate;
}

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());
    unordered_map<long, long> machine_map{};
    for(auto& el : machines)
    {
        ++machine_map[el];
    }
    
    long curr_rate = (machine_map.begin()->first * goal) / (machine_map.begin()->second);
    long produced_items = count_produced_items(machine_map, curr_rate);
    
    if(produced_items == goal) return curr_rate;
    
    long low_rate{0}, high_rate{curr_rate}, mid_rate = curr_rate - 1;
    while(low_rate < mid_rate && mid_rate < high_rate)
    {
        if(produced_items > goal)
        {
            high_rate = curr_rate;
            mid_rate = floor((low_rate + high_rate) / 2);
        }
        else if(produced_items < goal)
        {
            low_rate = mid_rate;
            mid_rate = floor((low_rate + high_rate) / 2);
        }
        else if(produced_items == goal)
        {
            curr_rate = localised_search(machine_map, low_rate, curr_rate, goal);
            break;
        }
        curr_rate = mid_rate;
        
        if(low_rate == mid_rate - 1 && mid_rate == high_rate - 1)
        {
            curr_rate = localised_search(machine_map, low_rate, high_rate, goal);
            break;   
        }
        produced_items = count_produced_items(machine_map, curr_rate);
    }    
    
    return curr_rate;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = minTime(machines, goal);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
