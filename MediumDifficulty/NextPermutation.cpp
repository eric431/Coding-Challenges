class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        pair<int, int> container{-1, -1};

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1])
            {
                container = make_pair(nums[i - 1], i - 1);
            }
        }

        int i = container.second, j;
        if(container.second == -1)
        {
            j = nums.size() - 1;
            container.second = 0;
        }
        else
        {
            j = container.second + 1;
        }
        while(true)
        {
            if(i == j)
            {
                int tmp{nums[container.second]};
                nums[container.second] = nums[i];
                nums[i] = tmp;

                i = container.second + 1;
                sort(nums.begin() + i, nums.end());
                break;
            }
            ++i;
        }

    }
};