class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []
        for val in nums:
            val = abs(val)
            if nums[val - 1] > 0:
                nums[val - 1] *= -1
            else:
                result.append(val)
        return result