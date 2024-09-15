// HACKERRANK 
Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape. Each building has a height, given by . If you join  adjacent buildings, they will form a solid rectangle of area .

Example

A rectangle of height  and length  can be constructed within the boundaries. The area formed is .

Function Description

Complete the function largestRectangle int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

largestRectangle has the following parameter(s):

int h[n]: the building heights
Returns
- long: the area of the largest rectangle that can be formed within the bounds of consecutive buildings

Input Format

The first line contains , the number of buildings.
The second line contains  space-separated integers, each the height of a building.

Constraints

Sample Input

STDIN       Function
-----       --------
5           h[] size n = 5
1 2 3 4 5   h = [1, 2, 3, 4, 5]
Sample Output

9
Explanation

An illustration of the test case follows.

// SOLUTION

struct buildings
{
    long height;
    pair<int, int> plot;
};

long largestRectangle(vector<int> h) {
    long largest_area = -1;
    stack<buildings> areas_s;
    vector<buildings> rectangle_areas;

    buildings h0;
    h0.height = h[0];
    h0.plot.first = 0;
    areas_s.push(h0);
    for(int i = 1; i < h.size(); ++i)
    {
        if(areas_s.empty())
        {
            buildings h_i;
            h_i.height = h[i];
            h_i.plot.first = i;
            areas_s.push(h_i);
            continue;
        }
        
        if(h[i] > areas_s.top().height)
        {
            buildings h_i;
            h_i.height = h[i];
            h_i.plot.first = i;
            areas_s.push(h_i);
        }
        else if (h[i] < areas_s.top().height)
        {   
            int tmp_idx;
            while(!areas_s.empty() && h[i] < areas_s.top().height)
            {
                buildings b_tmp = areas_s.top(); 
                b_tmp.plot.second = i - 1;
                rectangle_areas.push_back(b_tmp);
                tmp_idx = b_tmp.plot.first;
                areas_s.pop();      
            }
            buildings h_i;
            h_i.height = h[i];
            h_i.plot.first = tmp_idx;
            areas_s.push(h_i);
        }
    }
    
    while(!areas_s.empty())
    {
            buildings b_tmp = areas_s.top(); 
            b_tmp.plot.second = h.size() - 1;
            rectangle_areas.push_back(b_tmp);
            areas_s.pop(); 
    }
    
    long area_tmp = 0;
    for(auto el : rectangle_areas)
    {   
        area_tmp = el.height * ((el.plot.second - el.plot.first) + 1);
        
        cout << el.height << " * (" << el.plot.second << " -> " << el.plot.first << " ) =  " << area_tmp << endl;
        if(area_tmp > largest_area)
        {
            largest_area = area_tmp;
        }
    }
    
    return largest_area;
}