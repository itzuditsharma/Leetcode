class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_array = []
        for i, val in enumerate(nums):
            sorted_array.append((val, i))
        sorted_array.sort()

        n = len(nums)
        left = 0
        right = n-1

        while left < right:
            summ = sorted_array[left][0] + sorted_array[right][0]
            if summ == target:
                return [sorted_array[left][1], sorted_array[right][1]]

            if summ > target:
                right -= 1
            else:
                left += 1
        
        return []
            