class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefix_sums = list(accumulate(nums))
        
        for i in range(len(nums)):
            if prefix_sums[i] - nums[i] == prefix_sums[-1] - prefix_sums[i]:
                return i
        
        return -1