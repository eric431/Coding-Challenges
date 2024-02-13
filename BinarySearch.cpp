#include <vector>
#include <iostream>

using namespace std;

int BinarySearch(vector<int>& v, int el)
{
    int low = 0;
    int high = v.size();
    int mid;

    while (true)
    {
        mid = low + (high-low)/2;

        if(v[mid] == el)
        {
            return mid;
        }
        else if(v[mid] > el)
        {
            high = mid;
        }
        else if(v[mid] < el)
        {
            low = mid;
        }
    }
}

int main()
{
    vector<int> test = {1, 2, 3};

    int rst1 = BinarySearch(test, 1);
    int rst2 = BinarySearch(test, 2);
    int rst3 = BinarySearch(test, 3);


    // cout << rst1 << endl;
    // cout << rst2 << endl;
    // cout << rst3 << endl;
}