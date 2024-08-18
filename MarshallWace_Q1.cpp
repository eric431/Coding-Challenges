#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(string S, string C)
{
    map<int, string> store;
    map<string, vector<string>> cell;
    string field = "";
    int i = 0;
    bool header = false;

    for(auto& el : S)
    {
        if(el == ',' && header == false)
        {
            store[i] = field;
            i++;
            continue;
        }
        else if (el == '\n' && header == false)
        {
            i = 0;
            header = true;
            continue;
        }
        else if(el == ',' && header == true)
        {
            cell[store[i]].push_back(field);
            i++;
            continue;
        }
        else if (el == '\n' && header == true)
        {
            i = 0;
            continue;
        }
        field+=el;
    }

    int max = -1;
    for(auto& e : cell[C])
    {
        if(stoi(e) > max)
        {
            max = stoi(e);
        }
    }

    return max;
}