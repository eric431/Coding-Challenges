class Solution:
    def merge(self, arr: List[int], l: int, m: int, r: int):
        left = arr[l : m + 1]
        right = arr[m + 1 : r + 1]

        i = 0
        j = 0
        k = l
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            elif right[j] < left[i]:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

    def mergeSort(self, nums: List[int], l: int, r: int):
        if l < r:
            m = (l + r) // 2

            self.mergeSort(nums, l, m)
            self.mergeSort(nums, m + 1, r)
            self.merge(nums, l, m, r)

    def sortArray(self, nums: List[int]) -> List[int]:
        l = 0
        r = len(nums) - 1

        self.mergeSort(nums, l, r)

        return nums