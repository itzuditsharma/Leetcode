class Solution(object):
    def helper(self, nums, goal):
        l = 0
        r = 0
        sum = 0
        count = 0
        if goal < 0:
            return 0
        while r < len(nums):
            sum += nums[r]
            while(sum > goal):
                sum -= nums[l]
                l += 1
            count += r-l+1
            r+=1
        
        return count

    def numSubarraysWithSum(self, nums, goal):
        return self.helper(nums, goal) - self.helper(nums, goal - 1)
        
        