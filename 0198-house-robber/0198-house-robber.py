class Solution:
    def helper(self, idx, nums, dp):
        if idx < 0:
            return 0
        if idx == 0:
            return nums[idx]
        if dp[idx] != -1:
            return dp[idx]
        
        take = nums[idx] + self.helper(idx - 2, nums, dp)
        not_take = self.helper(idx - 1, nums, dp)
        
        dp[idx] = max(take, not_take)
        return dp[idx]

    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        return self.helper(n-1, nums, dp)