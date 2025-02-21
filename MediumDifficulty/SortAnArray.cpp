class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int r)
    {
        vector<int> left(m - l + 1);
        for(auto i {l}; i <= m; ++i)
            left[i - l] = arr[i];
        
        vector<int> right(r - m);
        for(auto j {m + 1}; j <= r; ++j)
            right[j  - (m + 1)] = arr[j];
        
        int i = 0;
        int j = 0;
        int k = l;
        while(i < left.size() && j < right.size())
        {
            if(left[i] <= right[j])
            {
                arr[k] = left[i];
                ++i;
            }
            else if(right[j] < left[i])
            {
                arr[k] = right[j];
                ++j;
            }
            ++k;
        }
        
        while(i < left.size())
        {
            arr[k] = left[i];
            ++i;
            ++k;
        }
        
        while(j < right.size())
        {
            arr[k] = right[j];
            ++j;
            ++k;
        }
    }
    
    void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l < r)
        {
            int m = (l + r) / 2;
            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        mergeSort(nums, l, r);
        
        return nums;
    }
};