 /*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */
 int truckTour(vector<vector<int>> petrolpumps) {
    int index{-1};
    int tank{0};
    for(int i{0}; i < petrolpumps.size(); ++i)
    {
        if(index == i)
            break;
        if(tank == 0) index = i;
        tank += (petrolpumps[i][0] - petrolpumps[i][1]);

        if(tank < 0)
        {
            tank = 0;

            index = -1;
            continue;
        }
        if(i == petrolpumps.size() - 1) i = -1;
    }
 
    return index;
 }

 
