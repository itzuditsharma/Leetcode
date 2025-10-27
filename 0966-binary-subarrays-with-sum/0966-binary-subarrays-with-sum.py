class Solution:
    def helper(self, nums, goal):
        summ = 0
        l = 0
        r = 0
        count = 0
        if goal < 0:
            return 0
        while r < len(nums):
            summ += nums[r]
            while summ > goal:
                summ -= nums[l]
                l+=1
            count += (r-l+1)
            r+=1
            
        return count

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.helper(nums, goal) - self.helper(nums, goal - 1)