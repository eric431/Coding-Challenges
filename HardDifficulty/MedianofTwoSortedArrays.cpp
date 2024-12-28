/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0)
        {
            bool even{nums2.size() % 2 == 0};
            size_t mid = nums2.size() / 2;
            if(nums2.size() > 1) return (even) * 0.5 * (nums2[mid - 1] + nums2[mid]) + (!even) * nums2[mid];
            else return nums2[mid];
        }
        else if (nums2.size() == 0)
        {
            bool even{nums1.size() % 2 == 0};
            size_t mid = nums1.size() / 2;
            if(nums1.size() > 1) return (even) * 0.5 * (nums1[mid - 1] + nums1[mid]) + (!even) * nums1[mid];
            else return nums1[mid];
        }
        else if(nums1.size() == 0 && nums2.size() == 0)
        {
            return 0;
        }

        int sentinel_value = numeric_limits<int>::max();
        vector<int> merged_vec(nums1.size() + nums2.size(), sentinel_value);

        int median_pos = merged_vec.size() / 2;
        int i{0}, j{0}, pos{0};
        int i_cache{i}, j_cache{j};        

        bool even{false};
        if(merged_vec.size() % 2 == 0) even = true;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                merged_vec[pos] = move(nums1[i]);
                auto el_itr = lower_bound(nums1.begin(), nums1.end(), nums2[j]);
                auto idx = (el_itr - nums1.begin());

                pos += idx - i;

                merged_vec[pos] = move(nums2[j]);
              
                if(pos == median_pos)
                {
                    return (even) * 0.5 * (nums1[idx - 1] + merged_vec[pos]) + (!even) * merged_vec[pos];
                }
                else if(pos > median_pos)
                {
                    if(merged_vec[median_pos - 1] != sentinel_value && merged_vec[median_pos] != sentinel_value)
                        return (even) * 0.5 * (merged_vec[median_pos - 1] + merged_vec[median_pos]) + (!even) * merged_vec[median_pos];
                    else
                    {
                        idx = idx - (pos - median_pos);
                        return (even) * 0.5 * (nums1[idx - 1] + nums1[idx]) + (!even) * nums1[idx];
                    }
                }
                i = idx;
                ++j;
            }
            else if(nums1[i] > nums2[j])
            {
                merged_vec[pos] = move(nums2[j]);
                auto el_itr = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
                auto idx = (el_itr - nums2.begin());

                pos += (idx - j);
                merged_vec[pos] = move(nums1[i]);

                if(pos == median_pos)
                {
                    return (even) * 0.5 * (nums2[idx - 1] + merged_vec[pos]) + (!even) * merged_vec[pos];
                }
                else if(pos > median_pos)
                {
                    if(merged_vec[median_pos - 1] != sentinel_value && merged_vec[median_pos] != sentinel_value)
                        return (even) * 0.5 * (merged_vec[median_pos - 1] + merged_vec[median_pos]) + (!even) * merged_vec[median_pos];
                    else    
                    {
                        idx = idx - (pos - median_pos);
                        return (even) * 0.5 * (nums2[idx - 1] + nums2[idx]) + (!even) * nums2[idx];
                    }
                }
                ++i;
                j = idx;
            }
            else if(nums1[i] == nums2[j])
            {
                merged_vec[pos] = move(nums1[i]);
                ++pos;
                merged_vec[pos] = move(nums2[j]);

                if(merged_vec[median_pos - 1] != sentinel_value && merged_vec[median_pos] != sentinel_value)
                {
                    return (even) * 0.5 * (merged_vec[median_pos - 1] + merged_vec[median_pos]) + (!even) * merged_vec[median_pos];
                }

                ++i;
                ++j;
            }
            ++pos;
        }
        
        double median{};
        if(i == nums1.size())
        {
            int d{median_pos - pos + j};
            if(pos == median_pos)
            {
                median = (even) * 0.5 * (merged_vec[pos - 1] + nums2[j]) + (!even) * nums2[j];
            }
            else if(pos < median_pos)
            {
                median = (even) * 0.5 * (nums2[d - 1] + nums2[d]) + (!even) * nums2[d];
            }
        }
        else if(j == nums2.size())
        {
            int d{median_pos - pos + i};
            if(pos == median_pos)
            {
                median = (even) * 0.5 * (merged_vec[pos - 1] + nums1[i]) + (!even) * nums1[i];
            }
            else if(pos < median_pos)
            {
                median = (even) * 0.5 * (nums1[d - 1] + nums1[d]) + (!even) * nums1[d];
            }
        }

        return median;
    }
};