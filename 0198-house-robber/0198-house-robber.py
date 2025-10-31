class Solution:
    def helper(self,ind, nums, dp):
        if ind < 0:
            return 0
        
        if dp[ind] != -1:
            return dp[ind]

        take = nums[ind] + self.helper(ind - 2, nums, dp)
        not_take = self.helper(ind - 1, nums, dp)
        
        dp[ind] = max(take, not_take)
        return dp[ind]

    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        return self.helper(n-1, nums, dp)